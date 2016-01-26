#ifndef ITEMLIST_MOCK_H
#define ITEMLIST_MOCK_H

#include <ItemList.h>

#include <gmock/gmock.h>

class ItemList_Mock :
    public ItemList
{
public:
  MOCK_METHOD2(append, void(QString path, QString value));

  MOCK_CONST_METHOD1(rowCount, int(const QModelIndex & parent));
  MOCK_CONST_METHOD2(data, QVariant(const QModelIndex & index, int role));
  MOCK_CONST_METHOD0(roleNames, QHash<int, QByteArray>());
  MOCK_CONST_METHOD2(data, QVariant(int row, int role));

};

#endif // ITEMLIST_MOCK_H
