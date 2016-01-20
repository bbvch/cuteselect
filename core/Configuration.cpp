#include "Configuration.h"

void Configuration::setBackgroundColor(QString value)
{
  backgroundColor = value;
  backgroundColorChanged();
}
