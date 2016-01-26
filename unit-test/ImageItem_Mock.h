#ifndef IMAGEITEM_MOCK_H
#define IMAGEITEM_MOCK_H

#include <ImageItem.h>

#include <gmock/gmock.h>

class ImageItem_Mock :
    public ImageItem
{
public:
  MOCK_CONST_METHOD1(data, QVariant(int role));

};

#endif // IMAGEITEM_MOCK_H
