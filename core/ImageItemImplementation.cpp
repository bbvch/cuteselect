#include "ImageItemImplementation.h"

ImageItemImplementation::ImageItemImplementation(QString path, QString value) :
  _path{path},
  _value{value}
{
}

QVariant ImageItemImplementation::data(int role) const
{
  switch (role) {
  case PathRole:
    return _path;
  case ValueRole:
    return _value;
  }

  return {};
}
