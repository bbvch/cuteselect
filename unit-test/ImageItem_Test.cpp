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
  ImageItem *a = new ImageItemImplementation("path", "label", "value");
  ImageItem *b = new ImageItemImplementation("path", "label", "value");

  ASSERT_TRUE(*a == *b);
}

TEST(ImageItem_Test, can_compare_for_equality_when_not_equal)
{
  ImageItem *a = new ImageItemImplementation("path", "",      "value");
  ImageItem *b = new ImageItemImplementation("",     "",      "value");
  ImageItem *c = new ImageItemImplementation("path", "",      "");
  ImageItem *d = new ImageItemImplementation("path", "label", "value");
  ImageItem *e = new ImageItemImplementation("",     "label", "value");
  ImageItem *f = new ImageItemImplementation("path", "label", "");

  ASSERT_FALSE(*a == *b);
  ASSERT_FALSE(*a == *c);
  ASSERT_FALSE(*a == *d);
  ASSERT_FALSE(*a == *e);
  ASSERT_FALSE(*a == *f);

  ASSERT_FALSE(*b == *c);
  ASSERT_FALSE(*b == *d);
  ASSERT_FALSE(*b == *e);
  ASSERT_FALSE(*b == *f);

  ASSERT_FALSE(*c == *d);
  ASSERT_FALSE(*c == *e);
  ASSERT_FALSE(*c == *f);

  ASSERT_FALSE(*d == *e);
  ASSERT_FALSE(*d == *f);

  ASSERT_FALSE(*e == *f);
}

}
