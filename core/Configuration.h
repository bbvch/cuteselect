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
  Q_PROPERTY(double relativeWidth MEMBER relativeWidth NOTIFY relativeWidthChanged)
  Q_PROPERTY(double relativeHeight MEMBER relativeHeight NOTIFY relativeHeightChanged)

public:
  void setBackgroundColor(QString value) override;
  void setRelativeWidth(double value) override;
  void setRelativeHeight(double value) override;
  void addImage(QString filename) override;

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

};

#endif
