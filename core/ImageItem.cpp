/*
 * (C) Copyright 2016
 * Urs Fässler, bbv Software Services, http://bbv.ch
 *
 * SPDX-License-Identifier:	GPL-3.0+
 */

#include "ImageItem.h"

bool operator ==(const ImageItem &left, const ImageItem &right)
{
  return (left.path() == right.path()) &&
      (left.value() == right.value());
}
