#include "helper/Context.h"

#include <ItemList.h>

#include <gtest/gtest.h>
#include <cucumber-cpp/defs.hpp>

#include <QVariant>

namespace
{

THEN("^I expect the property (.+) to be \"([^\"]*)\"$")
{
  REGEX_PARAM(std::string, name);
  REGEX_PARAM(std::string, value);

  cucumber::ScenarioScope<Context> context;
  const auto property = context->configuration.property(name.c_str());
  ASSERT_TRUE(property.isValid());

  ASSERT_EQ(value, property.toString().toStdString());
}

THEN("^I expect to see the following images in this order on the screen:$")
{
  TABLE_PARAM(imageListTable);
  const table_hashes_type& imageList = imageListTable.hashes();

  std::vector<std::string> expected;
  for (const auto & entry : imageList) {
    const auto filename = entry.at("filename");
    expected.push_back(filename);
  }

  std::vector<std::string> available;
  cucumber::ScenarioScope<Context> context;
  QVariant items = context->configuration.property("items");
  ASSERT_TRUE(items.isValid());
  ItemList *model = items.value<ItemList*>();
  ASSERT_NE(nullptr, model);
  for (int idx = 0; idx < model->rowCount(); idx++) {
    const auto index = model->index(idx);
    const auto path = index.data(ImageItem::PathRole);
    available.push_back(path.toString().toStdString());
  }

  ASSERT_EQ(expected, available);
}

WHEN("^I activate the item with the index (\\d+) on the gui$")
{
  REGEX_PARAM(unsigned, index);

  cucumber::ScenarioScope<Context> context;
  context->configuration.activate(index);
}

}
