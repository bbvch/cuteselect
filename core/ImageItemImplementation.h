/*
 * (C) Copyright 2016
 * Urs Fässler, bbv Software Services, http://bbv.ch
 *
 * SPDX-License-Identifier:	GPL-3.0+
 */

#ifndef IMAGEITEMIMPLEMENTATION_H
#define IMAGEITEMIMPLEMENTATION_H

#include "ImageItem.h"

class ImageItemImplementation :
    public ImageItem
{
public:
  ImageItemImplementation(const ImageItemImplementation &original);

  ImageItemImplementation(QString path, QString value);

  QString path() const override;
  QString value() const override;

private:
  const QString _path;
  const QString _value;


};

#endif // IMAGEITEMIMPLEMENTATION_H
