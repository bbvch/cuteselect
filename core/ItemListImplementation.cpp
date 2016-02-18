/*
 * (C) Copyright 2016
 * Urs Fässler, bbv Software Services, http://bbv.ch
 *
 * SPDX-License-Identifier:	GPL-3.0+
 */

#include "ItemListImplementation.h"

ItemListImplementation::~ItemListImplementation()
{
  for (const auto itr : items) {
    delete itr;
  }
  items.clear();
}

void ItemListImplementation::append(ImageItem *item)
{
  items.push_back(item);
}

size_t ItemListImplementation::count() const
{
  return items.size();
}

ImageItem *ItemListImplementation::at(size_t index) const
{
  if (validIndex(index)) {
    return items[index];
  } else {
    return nullptr;
  }
}

bool ItemListImplementation::validIndex(size_t index) const
{
  return index < items.size();
}
