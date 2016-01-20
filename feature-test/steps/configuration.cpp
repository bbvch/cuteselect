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

}
