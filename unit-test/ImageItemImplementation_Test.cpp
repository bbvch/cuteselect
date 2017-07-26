/*
 * (C) Copyright 2016
 * Urs Fässler, bbv Software Services, http://bbv.ch
 *
 * SPDX-License-Identifier:	GPL-3.0+
 */

#include <ImageItemImplementation.h>

#include <gtest/gtest.h>


namespace
{

class ImageItemImplementation_Test:
    public testing::Test
{
public:
  ImageItemImplementation testee{"the path", "the label", "the value"};
};

TEST_F(ImageItemImplementation_Test, get_values_by_methods)
{
  ASSERT_EQ("the path", testee.path().toStdString());
  ASSERT_EQ("the label", testee.label().toStdString());
  ASSERT_EQ("the value", testee.value().toStdString());
}

TEST_F(ImageItemImplementation_Test, can_copy_construct)
{
  ImageItemImplementation testee2{testee};

  ASSERT_EQ("the path", testee2.path().toStdString());
  ASSERT_EQ("the label", testee2.label().toStdString());
  ASSERT_EQ("the value", testee2.value().toStdString());
}

TEST_F(ImageItemImplementation_Test, access_the_property_path)
{
  const auto property = testee.property("path");

  ASSERT_TRUE(property.isValid());
  ASSERT_EQ("the path", property.toString().toStdString());
}

TEST_F(ImageItemImplementation_Test, read_the_path)
{
  ASSERT_EQ("the path", testee.path().toStdString());
}

TEST_F(ImageItemImplementation_Test, access_the_property_label)
{
  const auto property = testee.property("label");

  ASSERT_TRUE(property.isValid());
  ASSERT_EQ("the label", property.toString().toStdString());
}

TEST_F(ImageItemImplementation_Test, read_the_label)
{
  ASSERT_EQ("the label", testee.label().toStdString());
}

TEST_F(ImageItemImplementation_Test, access_the_property_value)
{
  const auto property = testee.property("value");

  ASSERT_TRUE(property.isValid());
  ASSERT_EQ("the value", property.toString().toStdString());
}

TEST_F(ImageItemImplementation_Test, read_the_value)
{
  ASSERT_EQ("the value", testee.value().toStdString());
}


}

