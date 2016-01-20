#include "ConfigurationLoader_Mock.h"
#include "Configuration_Mock.h"

#include <ApplicationFactory.h>
#include <Application.h>

#include <gtest/gtest.h>

#include <QBuffer>
#include <QVariant>

namespace
{

class ApplicationFactory_Test :
    public testing::Test
{
public:
  QBuffer configurationFile{};
  testing::StrictMock<ConfigurationLoader_Mock> configurationLoader;

  ApplicationFactory testee{configurationLoader};

};

TEST_F(ApplicationFactory_Test, create_application_from_buffer)
{
  testing::NiceMock<Configuration_Mock> *configuration = new testing::NiceMock<Configuration_Mock>();
  ON_CALL(*configuration, backgroundColor())
      .WillByDefault(testing::Return(QString("color")));
  EXPECT_CALL(configurationLoader, load(&configurationFile))
      .WillOnce(testing::Return(QSharedPointer<Configuration>(configuration)));

  const auto app = testee.produce(&configurationFile);

  ASSERT_EQ("color", app->property("backgroundColor").toString());
}

}
