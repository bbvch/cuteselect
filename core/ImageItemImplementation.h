#ifndef IMAGEITEMIMPLEMENTATION_H
#define IMAGEITEMIMPLEMENTATION_H

#include "ImageItem.h"

class ImageItemImplementation :
    public ImageItem
{
public:

  ImageItemImplementation(QString path, QString value);

  QVariant data(int role) const override;

private:
  const QString _path;
  const QString _value;


};

#endif // IMAGEITEMIMPLEMENTATION_H
