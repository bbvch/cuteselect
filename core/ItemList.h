#ifndef ITEMLIST_H
#define ITEMLIST_H

#include <QAbstractListModel>

#include <vector>

class ItemList :
    public QAbstractListModel
{
  Q_OBJECT

public:
  virtual void append(QString path, QString value) = 0;
  virtual QVariant data(int row, int role) const = 0;

  enum ItemRole {
    PathRole = Qt::UserRole,
    ValueRole,
  };

};

#endif // ITEMLIST_H
