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

TEST(ImageItem_Test, retrieve_the_role_names)
{
  const auto names = ImageItem::roleNames();

  ASSERT_EQ("path", names[ImageItem::PathRole]);
  ASSERT_FALSE(names.contains(ImageItem::ValueRole));
}


}