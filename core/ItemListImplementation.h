#ifndef ITEMLISTIMPLEMENTATION_H
#define ITEMLISTIMPLEMENTATION_H

#include "ItemList.h"
#include "ImageItem.h"

#include <vector>

class ItemListImplementation :
    public ItemList
{
public:
  ~ItemListImplementation();

  void append(ImageItem* item) override;

  int rowCount(const QModelIndex & parent = QModelIndex()) const override;
  QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const override;
  QVariant data(int row, int role) const override;
  QHash<int, QByteArray> roleNames() const override;

private:
  std::vector<ImageItem*> items;

  bool validIndex(int index) const;

};

#endif // ITEMLIST_H
