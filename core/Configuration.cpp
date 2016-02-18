/*
 * (C) Copyright 2016
 * Urs Fässler, bbv Software Services, http://bbv.ch
 *
 * SPDX-License-Identifier:	GPL-3.0+
 */

#include "Configuration.h"

Configuration::Configuration(ItemList *aItems) :
  items{aItems}
{
  qRegisterMetaType<QQmlListProperty<ImageItem>>("QQmlListProperty<ImageItem>");
}

Configuration::~Configuration()
{
  delete items;
}

void Configuration::setBackgroundColor(QString value)
{
  backgroundColor = value;
  backgroundColorChanged();
}

void Configuration::setRelativeWidth(double value)
{
  relativeWidth = value;
  relativeWidthChanged();
}

void Configuration::setRelativeHeight(double value)
{
  relativeHeight = value;
  relativeHeightChanged();
}

void Configuration::addImage(ImageItem *item)
{
  items->append(item);
}

void Configuration::activate(int index)
{
  const auto value = items->data(index, ImageItem::ValueRole);
  if (value.isValid()) {
    quit(value.toString());
  }
}

QQmlListProperty<ImageItem> Configuration::getItems()
{
  return QQmlListProperty<ImageItem>(this, items, itemsCount, itemsAt);
}

int Configuration::itemsCount(QQmlListProperty<ImageItem> *list)
{
  ItemList *items = static_cast<ItemList*>(list->data);
  return items->rowCount();
}

ImageItem *Configuration::itemsAt(QQmlListProperty<ImageItem> *list, int index)
{
  ItemList *items = static_cast<ItemList*>(list->data);
  return items->at(index);
}
