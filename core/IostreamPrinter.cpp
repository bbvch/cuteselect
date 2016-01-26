#include "IostreamPrinter.h"

IostreamPrinter::IostreamPrinter(std::ostream &aStream) :
  stream{aStream}
{
}

void IostreamPrinter::print(QString message)
{
  stream << message.toStdString() << std::endl;
}
