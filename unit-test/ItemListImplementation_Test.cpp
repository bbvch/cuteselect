/*
 * (C) Copyright 2016
 * Urs Fässler, bbv Software Services, http://bbv.ch
 *
 * SPDX-License-Identifier:	GPL-3.0+
 */

#include <ItemListImplementation.h>

#include "ImageItem_Mock.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <QVariant>
#include <QtTest/QSignalSpy>

namespace
{

class ItemListImplementation_Test:
    public testing::Test
{
public:
  ItemListImplementation testee{};

};

TEST_F(ItemListImplementation_Test, returns_nothing_for_invalid_index)
{
  ASSERT_EQ(nullptr, testee.at(-1));
  ASSERT_EQ(nullptr, testee.at(10));
}

TEST_F(ItemListImplementation_Test, add_a_image_to_the_items)
{
  testing::StrictMock<ImageItem_Mock> *item = new testing::StrictMock<ImageItem_Mock>();

  testee.append(item);

  ASSERT_EQ(1, testee.count());
  ASSERT_EQ(item, testee.at(0));
}

TEST_F(ItemListImplementation_Test, can_direcltly_access_element)
{
  testing::StrictMock<ImageItem_Mock> *item = new testing::StrictMock<ImageItem_Mock>();
  testee.append(item);

  ASSERT_EQ(item, testee.at(0));
}

}

