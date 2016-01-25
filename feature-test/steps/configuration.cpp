#include "helper/Context.h"

#include <cucumber-cpp/defs.hpp>

namespace
{

GIVEN("^I have the following configuration file:$")
{
  REGEX_PARAM(std::string, content);

  cucumber::ScenarioScope<Context> context;
  context->configurationFileContent.setData(content.c_str(), content.size());
}

GIVEN("^the configuration file is stored at \"([^\"]*)\"$")
{
  REGEX_PARAM(std::string, path);

  cucumber::ScenarioScope<Context> context;
  context->configurationFilePath = QString::fromStdString(path);
}

}
