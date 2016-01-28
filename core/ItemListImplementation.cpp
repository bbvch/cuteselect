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

int ItemListImplementation::rowCount(const QModelIndex &) const
{
  return items.size();
}

QVariant ItemListImplementation::data(const QModelIndex &index, int role) const
{
  return data(index.row(), role);
}

QVariant ItemListImplementation::data(int row, int role) const
{
  if (validIndex(row)) {
    return items[row]->data(role);
  } else {
    return {};
  }
}

QHash<int, QByteArray> ItemListImplementation::roleNames() const
{
  return ImageItem::roleNames();
}

bool ItemListImplementation::validIndex(int index) const
{
  return (0 <= index) && (index < items.size());
}
