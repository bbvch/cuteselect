#ifndef ITEMLISTIMPLEMENTATION_H
#define ITEMLISTIMPLEMENTATION_H

#include "ItemList.h"

#include <vector>

class ItemListImplementation :
    public ItemList
{
public:
  void append(QString path, QString value) override;

  int rowCount(const QModelIndex & parent = QModelIndex()) const override;
  QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const override;
  QVariant data(int row, int role) const override;
  QHash<int, QByteArray> roleNames() const override;

  enum ItemRole {
    PathRole = Qt::UserRole
  };

private:
  class Item
  {
  public:
    Item(QString aPath, QString aValue) :
      path{aPath},
      value{aValue}
    {
    }

    const QString path;
    const QString value;
  };

  std::vector<Item> items;

  bool validIndex(int index) const;

};

#endif // ITEMLIST_H
