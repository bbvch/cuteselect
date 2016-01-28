/*
 * (C) Copyright 2016
 * Urs Fässler, bbv Software Services, http://bbv.ch
 *
 * SPDX-License-Identifier:	GPL-3.0+
 */

#include "helper/Context.h"

#include <ConfigurationLoaderImplementation.h>
#include <FilePathResolverImplementation.h>

#include <gtest/gtest.h>
#include <cucumber-cpp/defs.hpp>

namespace
{

WHEN("^I start the application$")
{
  cucumber::ScenarioScope<Context> context;

  //TODO move that to common part
  FilePathResolverImplementation pathResolver;
  pathResolver.setBase(context->configurationFilePath);
  ConfigurationLoaderImplementation loader{context->configuration, pathResolver};
  loader.load(&context->configurationFileContent);
}

THEN("^I expect the application to quit with \"([^\"]*)\"$")
{
  REGEX_PARAM(std::string, message);

  cucumber::ScenarioScope<Context> context;
  ASSERT_TRUE(context->quitSpy.isValid());
  ASSERT_EQ(1, context->quitSpy.count());
  const auto args = context->quitSpy[0];
  ASSERT_EQ(1, args.count());
  ASSERT_EQ(message, args[0].toString().toStdString());
}


}
