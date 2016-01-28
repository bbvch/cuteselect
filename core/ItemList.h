/*
 * (C) Copyright 2016
 * Urs Fässler, bbv Software Services, http://bbv.ch
 *
 * SPDX-License-Identifier:	GPL-3.0+
 */

#ifndef ITEMLIST_H
#define ITEMLIST_H

#include "ImageItem.h"

#include <QAbstractListModel>

#include <vector>

class ItemList :
    public QAbstractListModel
{
  Q_OBJECT

public:
  virtual void append(ImageItem* item) = 0;
  virtual QVariant data(int row, int role) const = 0;

};

#endif // ITEMLIST_H
