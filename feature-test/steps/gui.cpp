#include "helper/Context.h"

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

  QStringList images;
  for(const auto & entry : imageList) {
    const auto filename = entry.at("filename");
    images.append(QString::fromStdString(filename));
  }

  cucumber::ScenarioScope<Context> context;
  ASSERT_EQ(images, context->configuration.stringList());
}

WHEN("^I activate the item \"([^\"]*)\" on the gui$")
{
  REGEX_PARAM(std::string, id);

  cucumber::ScenarioScope<Context> context;
  context->configuration.activate(QString::fromStdString(id));
}

}
