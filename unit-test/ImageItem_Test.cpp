/*
 * (C) Copyright 2016
 * Urs Fässler, bbv Software Services, http://bbv.ch
 *
 * SPDX-License-Identifier:	GPL-3.0+
 */

#include <ImageItem.h>
#include <ImageItemImplementation.h>

#include <gtest/gtest.h>


namespace
{

TEST(ImageItem_Test, can_compare_for_equality_when_equal)
{
  ImageItem *a = new ImageItemImplementation("path", "value");
  ImageItem *b = new ImageItemImplementation("path", "value");

  ASSERT_TRUE(*a == *b);
}

TEST(ImageItem_Test, can_compare_for_equality_when_not_equal)
{
  ImageItem *a = new ImageItemImplementation("path", "value");
  ImageItem *b = new ImageItemImplementation("", "value");
  ImageItem *c = new ImageItemImplementation("path", "");

  ASSERT_FALSE(*a == *b);
  ASSERT_FALSE(*a == *c);
  ASSERT_FALSE(*b == *c);
}

}
