/*
 * (C) Copyright 2016
 * Urs Fässler, bbv Software Services, http://bbv.ch
 *
 * SPDX-License-Identifier:	GPL-3.0+
 */

#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include "ConfigurationListener.h"
#include "ItemList.h"

#include <QAbstractListModel>

class Configuration :
    public QObject,
    public ConfigurationListener
{
  Q_OBJECT

  Q_PROPERTY(QString backgroundColor MEMBER backgroundColor NOTIFY backgroundColorChanged)
  Q_PROPERTY(double relativeWidth MEMBER relativeWidth NOTIFY relativeWidthChanged)
  Q_PROPERTY(double relativeHeight MEMBER relativeHeight NOTIFY relativeHeightChanged)
  Q_PROPERTY(ItemList* items MEMBER items CONSTANT)

public:
  Configuration(ItemList *items);
  ~Configuration();

  void setBackgroundColor(QString value) override;
  void setRelativeWidth(double value) override;
  void setRelativeHeight(double value) override;
  void addImage(ImageItem *item) override;

public slots:
  void activate(int index);

signals:
  void backgroundColorChanged();
  void relativeWidthChanged();
  void relativeHeightChanged();

  void quit(QString message);

private:
  QString backgroundColor{"#000000"};
  double relativeWidth{0.25};
  double relativeHeight{0.5};
  ItemList * const items;

};

#endif
