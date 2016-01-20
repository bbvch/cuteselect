#include "helper/Context.h"

#include <gtest/gtest.h>
#include <cucumber-cpp/defs.hpp>

#include <QVariant>

namespace
{

THEN("^I expect the background color to be \"([^\"]*)\"$")
{
  REGEX_PARAM(std::string, color);

  cucumber::ScenarioScope<Context> context;
  const auto backgroundColor = context->application->property("backgroundColor");
  ASSERT_TRUE(backgroundColor.isValid());

  ASSERT_EQ(color, backgroundColor.toString().toStdString());
}

}
