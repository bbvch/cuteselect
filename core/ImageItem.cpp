#include "ImageItem.h"



bool operator ==(const ImageItem &left, const ImageItem &right)
{
  return (left.data(ImageItem::PathRole) == right.data(ImageItem::PathRole)) &&
      (left.data(ImageItem::ValueRole) == right.data(ImageItem::ValueRole));
}


QHash<int, QByteArray> ImageItem::roleNames()
{
  QHash<int, QByteArray> names;
  names[ImageItem::PathRole] = "path";
  return names;
}
