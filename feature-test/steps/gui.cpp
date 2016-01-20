#include "helper/Context.h"

#include <gtest/gtest.h>
#include <cucumber-cpp/defs.hpp>

#include <QVariant>

namespace
{

THEN("^I expect the background color to be \"([^\"]*)\"$")
{
  REGEX_PARAM(std::string, color);

  cucumber::ScenarioScope<Context> context;
  const auto backgroundColor = context->application.property("backgroundColor");
  ASSERT_TRUE(backgroundColor.isValid());

  ASSERT_EQ(color, backgroundColor.toString().toStdString());
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
  ASSERT_EQ(images, context->application.stringList());
}

}
