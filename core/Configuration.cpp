#include "Configuration.h"

void Configuration::setBackgroundColor(QString value)
{
  backgroundColor = value;
  backgroundColorChanged();
}

void Configuration::addImage(QString filename)
{
  const auto newRow = rowCount();
  insertRow(newRow);
  setData(index(newRow), filename);
}
