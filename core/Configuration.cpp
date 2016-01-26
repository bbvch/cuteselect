#include "Configuration.h"

Configuration::Configuration(ItemList *aItems) :
  items{aItems}
{
  qRegisterMetaType<ItemList*>("ItemList*");
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

void Configuration::addImage(QString filename)
{
  items->append(filename);
}

void Configuration::activate(int index)
{
  const auto value = items->data(index, ItemList::PathRole);
  if (value.isValid()) {
    quit(value.toString());
  }
}
