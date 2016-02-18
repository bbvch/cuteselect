/*
 * (C) Copyright 2016
 * Urs Fässler, bbv Software Services, http://bbv.ch
 *
 * SPDX-License-Identifier:	GPL-3.0+
 */

#ifndef ITEMLISTIMPLEMENTATION_H
#define ITEMLISTIMPLEMENTATION_H

#include "ItemList.h"
#include "ImageItem.h"

#include <vector>

class ItemListImplementation :
    public ItemList
{
public:
  ~ItemListImplementation();

  void append(ImageItem* item) override;

  size_t count() const override;
  ImageItem *at(size_t index) const override;

private:
  std::vector<ImageItem*> items;

  bool validIndex(size_t index) const;

};

#endif // ITEMLIST_H
