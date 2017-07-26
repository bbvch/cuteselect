/*
 * (C) Copyright 2016
 * Urs Fässler, bbv Software Services, http://bbv.ch
 *
 * SPDX-License-Identifier:	GPL-3.0+
 */

#include "helper/Context.h"

#include <ItemList.h>

#include <gtest/gtest.h>
#include <cucumber-cpp/autodetect.hpp>

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

THEN("^I expect the property (.+) to be the number (\\d+\\.\\d+)$")
{
  REGEX_PARAM(std::string, name);
  REGEX_PARAM(double, value);

  cucumber::ScenarioScope<Context> context;
  const auto property = context->configuration.property(name.c_str());
  ASSERT_TRUE(property.isValid());

  bool ok;
  ASSERT_EQ(value, property.toDouble(&ok));
  ASSERT_TRUE(ok);
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
  QQmlListProperty<ImageItem> model = items.value<QQmlListProperty<ImageItem>>();
  for (int idx = 0; idx < model.count(&model); idx++) {
    const auto item = model.at(&model, idx);
    const auto path = item->property("path");
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
