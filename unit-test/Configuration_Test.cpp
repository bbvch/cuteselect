#include <Configuration.h>

#include <gtest/gtest.h>

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

  Configuration testee{};
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

TEST_F(Configuration_Test, add_a_image_to_the_items)
{
  testee.addImage("the image path");

  ASSERT_EQ(1, testee.rowCount());
  ASSERT_EQ("the image path", testee.stringList().at(0));
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
  testee.addImage("image1");
  testee.addImage("image2");
  testee.addImage("image3");

  testee.activate(1);

  ASSERT_EQ(1, quitSpy.count());
  const auto args = quitSpy[0];
  ASSERT_EQ(1, args.count());
  ASSERT_EQ("image2", args[0].toString().toStdString());
}

TEST_F(Configuration_Test, does_nothing_when_index_of_activate_is_invalid)
{
  testee.activate(-1);
  testee.activate(1);

  ASSERT_EQ(0, quitSpy.count());
}

}
