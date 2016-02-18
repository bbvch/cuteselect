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

TEST_F(ItemListImplementation_Test, retrieve_the_role_names)
{
  const auto names = testee.roleNames();

  ASSERT_EQ("path", names[ImageItem::PathRole]);
  ASSERT_FALSE(names.contains(ImageItem::ValueRole));
}

TEST_F(ItemListImplementation_Test, returns_nothing_for_invalid_index)
{
  ASSERT_FALSE(testee.data(-1, ImageItem::PathRole).isValid());
  ASSERT_FALSE(testee.data(10, ImageItem::PathRole).isValid());
}

TEST_F(ItemListImplementation_Test, add_a_image_to_the_items)
{
  testing::StrictMock<ImageItem_Mock> *item = new testing::StrictMock<ImageItem_Mock>();
  EXPECT_CALL(*item, data(ImageItem::PathRole))
      .WillOnce(testing::Return(QString{"the image path"}));

  testee.append(item);

  ASSERT_EQ(1, testee.rowCount());
  ASSERT_EQ("the image path", testee.data(0, ImageItem::PathRole).toString().toStdString());
}

TEST_F(ItemListImplementation_Test, can_retrieve_data_by_QModelIndex)
{
  testing::StrictMock<ImageItem_Mock> *item = new testing::StrictMock<ImageItem_Mock>();
  EXPECT_CALL(*item, data(ImageItem::PathRole))
      .WillOnce(testing::Return(QString{"the image path"}));
  testee.append(item);
  QModelIndex index = testee.index(0);

  ASSERT_EQ("the image path", testee.data(index, ImageItem::PathRole));
}

TEST_F(ItemListImplementation_Test, can_direcltly_access_element)
{
  testing::StrictMock<ImageItem_Mock> *item = new testing::StrictMock<ImageItem_Mock>();
  testee.append(item);

  ASSERT_EQ(item, testee.at(0));
}

}

