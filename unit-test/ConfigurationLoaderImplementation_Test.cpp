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

  ConfigurationLoaderImplementation testee;

};

TEST_F(ConfigurationLoaderImplementation_Test, load_an_empty_configuration_is_invalid)
{
  ASSERT_THROW(testee.load(&data), std::invalid_argument);
}

TEST_F(ConfigurationLoaderImplementation_Test, load_the_background_color)
{
  data.setData("<cuteselect background-color=\"#041233\" />");

  const auto configuration = testee.load(&data);

  ASSERT_EQ("#041233", configuration->backgroundColor());
}

TEST_F(ConfigurationLoaderImplementation_Test, the_default_background_color_is_black)
{
  data.setData("<cuteselect />");

  const auto configuration = testee.load(&data);

  ASSERT_EQ("#000000", configuration->backgroundColor());
}

}
