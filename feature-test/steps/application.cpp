#include "helper/Context.h"

#include <ConfigurationLoaderImplementation.h>

#include <gtest/gtest.h>
#include <cucumber-cpp/defs.hpp>

namespace
{

WHEN("^I start the application$")
{
  cucumber::ScenarioScope<Context> context;

  //TODO move that to common part
  ConfigurationLoaderImplementation loader{context->application};
  loader.load(&context->configurationFileContent);
}

}
