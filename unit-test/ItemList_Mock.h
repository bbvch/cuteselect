/*
 * (C) Copyright 2016
 * Urs Fässler, bbv Software Services, http://bbv.ch
 *
 * SPDX-License-Identifier:	GPL-3.0+
 */

#ifndef ITEMLIST_MOCK_H
#define ITEMLIST_MOCK_H

#include <ItemList.h>

#include <gmock/gmock.h>

class ItemList_Mock :
    public ItemList
{
public:
  MOCK_METHOD1(append, void(ImageItem* item));

  MOCK_CONST_METHOD0(count, size_t());
  MOCK_CONST_METHOD1(at, ImageItem*(size_t row));

};

#endif // ITEMLIST_MOCK_H
