#include "helper/Context.h"

#include <ApplicationFactory.h>
#include <ConfigurationLoaderImplementation.h>

#include <gtest/gtest.h>
#include <cucumber-cpp/defs.hpp>

namespace
{

WHEN("^I start the application$")
{
  cucumber::ScenarioScope<Context> context;

  //TODO move that to common part
  ConfigurationLoaderImplementation loader;
  ApplicationFactory factory{loader};

  context->application = factory.produce(&context->configurationFileContent);
}

}
