#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include "ConfigurationListener.h"

#include <QStringListModel>

class Configuration :
    public QStringListModel,
    public ConfigurationListener
{
  Q_OBJECT

  Q_PROPERTY(QString backgroundColor MEMBER backgroundColor NOTIFY backgroundColorChanged)

public:
  void setBackgroundColor(QString value) override;
  void addImage(QString filename) override;

signals:
  void backgroundColorChanged();

private:
  QString backgroundColor{"#000000"};

};

#endif
