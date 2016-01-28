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
  ImageItemImplementation testee{"the path", "the value"};
};

TEST_F(ImageItemImplementation_Test, get_values_by_roles)
{
  ASSERT_EQ("the path", testee.data(ImageItem::PathRole).toString().toStdString());
  ASSERT_EQ("the value", testee.data(ImageItem::ValueRole).toString().toStdString());
}

TEST_F(ImageItemImplementation_Test, returns_nothing_for_invalid_role)
{
  ASSERT_FALSE(testee.data(-1).isValid());
}

}

