/*
 * (C) Copyright 2016
 * Urs Fässler, bbv Software Services, http://bbv.ch
 *
 * SPDX-License-Identifier:	GPL-3.0+
 */

#ifndef ITEMLIST_H
#define ITEMLIST_H

#include "ImageItem.h"

class ItemList
{
public:
  virtual ~ItemList() = default;

  virtual void append(ImageItem* item) = 0;
  virtual size_t count() const = 0;
  virtual ImageItem *at(size_t index) const = 0;

};

#endif // ITEMLIST_H
