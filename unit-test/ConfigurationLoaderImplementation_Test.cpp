#include "ConfigurationListener_Mock.h"
#include "FilePathResolver_Mock.h"

#include <ConfigurationLoaderImplementation.h>

#include <gtest/gtest.h>

#include <QBuffer>

#include <stdexcept>

namespace
{

class ConfigurationLoaderImplementation_Test :
    public testing::Test
{
public:
  QBuffer data{};

  testing::NiceMock<FilePathResolver_Mock> pathResolver;
  testing::StrictMock<ConfigurationListener_Mock> listener;

  ConfigurationLoaderImplementation testee{listener, pathResolver};
};

TEST_F(ConfigurationLoaderImplementation_Test, load_an_empty_configuration_is_invalid)
{
  ASSERT_THROW(testee.load(&data), std::invalid_argument);
}

TEST_F(ConfigurationLoaderImplementation_Test, load_the_background_color)
{
  data.setData("<cuteselect background-color=\"#041233\" />");

  EXPECT_CALL(listener, setBackgroundColor(QString{"#041233"})).Times(1);

  testee.load(&data);
}

TEST_F(ConfigurationLoaderImplementation_Test, does_not_set_the_background_color_if_not_specified)
{
  data.setData("<cuteselect />");

  EXPECT_CALL(listener, setBackgroundColor(testing::_)).Times(0);

  testee.load(&data);
}

TEST_F(ConfigurationLoaderImplementation_Test, does_not_set_the_width_if_not_specified)
{
  data.setData("<cuteselect />");

  EXPECT_CALL(listener, setRelativeWidth(testing::_)).Times(0);

  testee.load(&data);
}

TEST_F(ConfigurationLoaderImplementation_Test, load_the_width)
{
  data.setData("<cuteselect relative-width=\"0.541\" />");

  EXPECT_CALL(listener, setRelativeWidth(0.541)).Times(1);

  testee.load(&data);
}

TEST_F(ConfigurationLoaderImplementation_Test, does_not_set_the_height_if_not_specified)
{
  data.setData("<cuteselect />");

  EXPECT_CALL(listener, setRelativeHeight(testing::_)).Times(0);

  testee.load(&data);
}

TEST_F(ConfigurationLoaderImplementation_Test, load_the_height)
{
  data.setData("<cuteselect relative-height=\"0.1123\" />");

  EXPECT_CALL(listener, setRelativeHeight(0.1123)).Times(1);

  testee.load(&data);
}

TEST_F(ConfigurationLoaderImplementation_Test, loads_the_images)
{
  data.setData("<cuteselect><image id=\"first\" file=\"file1\" /></cuteselect>");

  EXPECT_CALL(pathResolver, resolve(QString{"file1"})).WillOnce(testing::Return(QString{"file2"}));
  EXPECT_CALL(listener, addImage(QString{"file2"})).Times(1);

  testee.load(&data);
}

}
