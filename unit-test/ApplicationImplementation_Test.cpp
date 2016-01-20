#include "Configuration_Mock.h"

#include <ApplicationImplementation.h>

#include <gtest/gtest.h>

#include <QVariant>

namespace
{

//class Application_Test:
//    public testing::Test
//{
//public:
//  testing::NiceMock<Configuration_Mock> configuration;
//  Application testee{configuration};

//};

TEST(ApplicationImplementation_Test, has_a_property_for_background_color)
{
  testing::NiceMock<Configuration_Mock> configuration;
  ApplicationImplementation testee{configuration};

  ASSERT_TRUE(testee.property("backgroundColor").isValid());
}

TEST(ApplicationImplementation_Test, background_color_is_specified_when_application_starts)
{
  testing::NiceMock<Configuration_Mock> configuration;
  ON_CALL(configuration, backgroundColor())
      .WillByDefault(testing::Return(QString{"1234"}));

  ApplicationImplementation testee{configuration};

  ASSERT_EQ("1234", testee.property("backgroundColor").toString());
}

}
