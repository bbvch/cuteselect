/*
 * (C) Copyright 2016
 * Urs Fässler, bbv Software Services, http://bbv.ch
 *
 * SPDX-License-Identifier:	GPL-3.0+
 */

#include "IostreamPrinter.h"

IostreamPrinter::IostreamPrinter(std::ostream &aStream) :
  stream{aStream}
{
}

void IostreamPrinter::print(QString message)
{
  stream << message.toStdString() << std::endl;
}
