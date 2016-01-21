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
  }

  Configuration testee{};
  QSignalSpy backgroundSpy{&testee, SIGNAL(backgroundColorChanged())};

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

TEST_F(Configuration_Test, quit_when_an_activate_is_received)
{
  QSignalSpy spy{&testee, SIGNAL(quit(QString))};

  testee.activate("lala");

  ASSERT_TRUE(spy.isValid());
  ASSERT_EQ(1, spy.count());
  const auto args = spy[0];
  ASSERT_EQ(1, args.count());
  ASSERT_EQ("lala\n", args[0].toString().toStdString());
}

}
