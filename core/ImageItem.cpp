/*
 * (C) Copyright 2016
 * Urs Fässler, bbv Software Services, http://bbv.ch
 *
 * SPDX-License-Identifier:	GPL-3.0+
 */

#include "ImageItem.h"



bool operator ==(const ImageItem &left, const ImageItem &right)
{
  return (left.data(ImageItem::PathRole) == right.data(ImageItem::PathRole)) &&
      (left.data(ImageItem::ValueRole) == right.data(ImageItem::ValueRole));
}


QHash<int, QByteArray> ImageItem::roleNames()
{
  QHash<int, QByteArray> names;
  names[ImageItem::PathRole] = "path";
  return names;
}
