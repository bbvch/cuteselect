#include <IostreamPrinter.h>

#include <gtest/gtest.h>

#include <ostream>

namespace
{

class IostreamPrinter_Test:
    public testing::Test
{
public:
  std::stringstream stream;
  IostreamPrinter testee{stream};

};

TEST_F(IostreamPrinter_Test, has_a_slot_for_printing)
{
  const auto meta = testee.staticMetaObject;
  const auto index = meta.indexOfSlot("print(QString)");

  ASSERT_LE(0, index);
}


TEST_F(IostreamPrinter_Test, print_data_from_slot)
{
  testee.print("lala");

  ASSERT_EQ("lala\n", stream.str());
}

}

