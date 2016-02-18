/*
 * (C) Copyright 2016
 * Urs Fässler, bbv Software Services, http://bbv.ch
 *
 * SPDX-License-Identifier:	GPL-3.0+
 */

#include <Configuration.h>

#include "ItemList_Mock.h"
#include "ImageItem_Mock.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <QVariant>
#include <QtTest/QSignalSpy>

namespace
{

class Configuration_Test:
    public testing::Test
{
public:
  void SetUp() override
  {
    ASSERT_TRUE(backgroundSpy.isValid());
    ASSERT_TRUE(widthSpy.isValid());
    ASSERT_TRUE(heightSpy.isValid());
    ASSERT_TRUE(quitSpy.isValid());
  }


  testing::StrictMock<ImageItem_Mock> item;
  testing::StrictMock<ItemList_Mock> *items = new testing::StrictMock<ItemList_Mock>();
  Configuration testee{items};
  QSignalSpy backgroundSpy{&testee, SIGNAL(backgroundColorChanged())};
  QSignalSpy widthSpy{&testee, SIGNAL(relativeWidthChanged())};
  QSignalSpy heightSpy{&testee, SIGNAL(relativeHeightChanged())};
  QSignalSpy quitSpy{&testee, SIGNAL(quit(QString))};

};

TEST_F(Configuration_Test, has_a_property_for_background_color)
{
  ASSERT_TRUE(testee.property("backgroundColor").isValid());
}

TEST_F(Configuration_Test, default_background_color_is_black)
{
  ASSERT_EQ("#000000", testee.property("backgroundColor").toString());
}

TEST_F(Configuration_Test, can_change_the_background_color)
{
  testee.setBackgroundColor("#123456");

  ASSERT_EQ("#123456", testee.property("backgroundColor").toString());
  ASSERT_EQ(1, backgroundSpy.count());
}

TEST_F(Configuration_Test, has_a_property_for_the_items)
{
  const QVariant itemsProperty = testee.property("items");

  ASSERT_TRUE(itemsProperty.isValid());
}

TEST_F(Configuration_Test, read_the_size_of_the_items)
{
  EXPECT_CALL(*items, count())
      .WillOnce(testing::Return(5));

  const QVariant itemsProperty = testee.property("items");

  QQmlListProperty<ImageItem> list = itemsProperty.value<QQmlListProperty<ImageItem>>();
  ASSERT_EQ(5, list.count(&list));
}

TEST_F(Configuration_Test, access_an_element_of_the_items)
{
  EXPECT_CALL(*items, at(42))
      .WillOnce(testing::Return(&item));

  const QVariant itemsProperty = testee.property("items");

  QQmlListProperty<ImageItem> list = itemsProperty.value<QQmlListProperty<ImageItem>>();
  ASSERT_EQ(&item, list.at(&list, 42));
}

TEST_F(Configuration_Test, add_a_image_to_the_items)
{
  testing::StrictMock<ImageItem_Mock> expectedImage;
  EXPECT_CALL(*items, append(&expectedImage));

  testee.addImage(&expectedImage);
}

TEST_F(Configuration_Test, the_default_width_is_defined)
{
  ASSERT_DOUBLE_EQ(0.25, testee.property("relativeWidth").toDouble());
}

TEST_F(Configuration_Test, can_write_the_width)
{
  testee.setRelativeWidth(0.312);

  ASSERT_DOUBLE_EQ(0.312, testee.property("relativeWidth").toDouble());
  ASSERT_EQ(1, widthSpy.count());
}

TEST_F(Configuration_Test, the_default_height_is_defined)
{
  ASSERT_DOUBLE_EQ(0.5, testee.property("relativeHeight").toDouble());
}

TEST_F(Configuration_Test, can_write_the_height)
{
  testee.setRelativeHeight(0.6132);

  ASSERT_DOUBLE_EQ(0.6132, testee.property("relativeHeight").toDouble());
  ASSERT_EQ(1, heightSpy.count());
}

TEST_F(Configuration_Test, quit_when_an_activate_is_received)
{
  EXPECT_CALL(item, value())
      .WillOnce(testing::Return("the value"));
  EXPECT_CALL(*items, at(5))
      .WillOnce(testing::Return(&item));

  testee.activate(5);

  ASSERT_EQ(1, quitSpy.count());
  const auto args = quitSpy[0];
  ASSERT_EQ(1, args.count());
  ASSERT_EQ("the value", args[0].toString().toStdString());
}

TEST_F(Configuration_Test, does_nothing_when_index_of_activate_is_invalid)
{
  EXPECT_CALL(*items, at(-1))
      .WillOnce(testing::Return(nullptr));
  EXPECT_CALL(*items, at(1))
      .WillOnce(testing::Return(nullptr));

  testee.activate(-1);
  testee.activate(1);

  ASSERT_EQ(0, quitSpy.count());
}

}
