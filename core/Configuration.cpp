#include "Configuration.h"

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
  const auto newRow = rowCount();
  insertRow(newRow);
  setData(index(newRow), filename);
}

void Configuration::activate(QString id)
{
  quit(id + "\n");
}
