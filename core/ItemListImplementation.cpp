#include "ItemListImplementation.h"

void ItemListImplementation::append(QString path, QString value)
{
  items.emplace_back(path, value);
}

int ItemListImplementation::rowCount(const QModelIndex &) const
{
  return items.size();
}

QVariant ItemListImplementation::data(const QModelIndex &index, int role) const
{
  return data(index.row(), role);
}

QVariant ItemListImplementation::data(int row, int role) const
{
  if (validIndex(row)) {
    switch (role) {
    case PathRole:
      return items[row].path;
    case ValueRole:
      return items[row].value;
    }
  }

  return {};
}

QHash<int, QByteArray> ItemListImplementation::roleNames() const
{
  QHash<int, QByteArray> names;
  names[PathRole] = "path";
  return names;
}

bool ItemListImplementation::validIndex(int index) const
{
  return (0 <= index) && (index < items.size());
}
