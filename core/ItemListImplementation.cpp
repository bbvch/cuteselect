#include "ItemListImplementation.h"

void ItemListImplementation::append(QString path)
{
  items.emplace_back(path);
}

int ItemListImplementation::rowCount(const QModelIndex &parent) const
{
  return items.size();
}

QVariant ItemListImplementation::data(const QModelIndex &index, int role) const
{
  return items[index.row()].path;
}

QVariant ItemListImplementation::data(int row, int role) const
{
  return items[row].path;
}

QHash<int, QByteArray> ItemListImplementation::roleNames() const
{
  QHash<int, QByteArray> names;
  names[PathRole] = "path";
  return names;
}

