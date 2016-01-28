/*
 * (C) Copyright 2016
 * Urs Fässler, bbv Software Services, http://bbv.ch
 *
 * SPDX-License-Identifier:	GPL-3.0+
 */

#include <FilePathResolverImplementation.h>

#include <gtest/gtest.h>


namespace
{

class FilePathResolver_Test:
    public testing::Test
{
public:
  FilePathResolverImplementation testee{};
};

TEST_F(FilePathResolver_Test, does_nothing_when_the_file_is_absolute)
{
  ASSERT_EQ("/path/file", testee.resolve("/path/file").toStdString());
}

TEST_F(FilePathResolver_Test, adds_the_path_when_the_file_is_relative)
{
  testee.setBase("/base");

  ASSERT_EQ("/base/path/file", testee.resolve("path/file").toStdString());
}

}
