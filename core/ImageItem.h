/*
 * (C) Copyright 2016
 * Urs Fässler, bbv Software Services, http://bbv.ch
 *
 * SPDX-License-Identifier:	GPL-3.0+
 */

#ifndef IMAGEITEM_H
#define IMAGEITEM_H

#include <QString>
#include <QObject>
#include <QVariant>

class ImageItem
{
public:
  enum ImageItemRole {
    PathRole = Qt::UserRole,
    ValueRole
  };

  static QHash<int, QByteArray> roleNames();

  virtual ~ImageItem() = default;
  virtual QVariant data(int role) const = 0;

};

bool operator == (const ImageItem &left, const ImageItem &right);

#endif // IMAGEITEM_H
