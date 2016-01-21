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
  ConfigurationLoaderImplementation loader{context->configuration};
  loader.load(&context->configurationFileContent);
}

THEN("^I expect the application to quit with \"([^\"]*)\" followed by a newline$")
{
  REGEX_PARAM(std::string, message_prefix);
  const auto message = message_prefix + "\n";

  cucumber::ScenarioScope<Context> context;
  ASSERT_TRUE(context->quitSpy.isValid());
  ASSERT_EQ(1, context->quitSpy.count());
  const auto args = context->quitSpy[0];
  ASSERT_EQ(1, args.count());
  ASSERT_EQ(message, args[0].toString().toStdString());
}


}
