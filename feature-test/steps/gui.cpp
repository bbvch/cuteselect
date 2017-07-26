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

void assert_equal_value(const std::string &name, const cucumber::internal::Table::hash_row_type &expected, const ImageItem *actual)
{
  const auto expectedValue = expected.at(name);
  const auto actualValue = actual->property(name.c_str());

  ASSERT_EQ(expectedValue, actualValue.toString().toStdString());
}

THEN("^I expect to see the following images in this order on the screen:$")
{
  TABLE_PARAM(imageListTable);
  const table_hashes_type& imageList = imageListTable.hashes();

  cucumber::ScenarioScope<Context> context;
  QVariant items = context->configuration.property("items");
  ASSERT_TRUE(items.isValid());
  QQmlListProperty<ImageItem> model = items.value<QQmlListProperty<ImageItem>>();

  for (std::size_t i = 0; i < imageList.size(); i++) {
    const auto &entry = imageList.at(i);
    const auto item = model.at(&model, i);

    assert_equal_value("path", entry, item);
    assert_equal_value("label", entry, item);
  }
}

WHEN("^I activate the item with the index (\\d+) on the gui$")
{
  REGEX_PARAM(unsigned, index);

  cucumber::ScenarioScope<Context> context;
  context->configuration.activate(index);
}

}
