#include <ItemListImplementation.h>

#include <gtest/gtest.h>

#include <QVariant>
#include <QtTest/QSignalSpy>

namespace
{

class ItemListImplementation_Test:
    public testing::Test
{
public:
  ItemListImplementation testee{};

};

TEST_F(ItemListImplementation_Test, add_a_image_to_the_items)
{
  testee.append("the image path");

  ASSERT_EQ(1, testee.rowCount());
  ASSERT_EQ("the image path", testee.data(0, ItemListImplementation::PathRole));
}

TEST_F(ItemListImplementation_Test, can_retrieve_data_by_QModelIndex)
{
  testee.append("the image path");
  QModelIndex index = testee.index(0);

  ASSERT_EQ("the image path", testee.data(index, ItemListImplementation::PathRole));
}

TEST_F(ItemListImplementation_Test, returns_the_role_names)
{
  const auto names = testee.roleNames();

  ASSERT_EQ("path", names[ItemList::PathRole]);
}

}

