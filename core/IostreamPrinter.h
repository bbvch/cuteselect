#ifndef IOSTREAMPRINTER_H
#define IOSTREAMPRINTER_H

#include <QObject>

#include <ostream>

class IostreamPrinter :
    public QObject
{
  Q_OBJECT

public:
  IostreamPrinter(std::ostream &stream);

public slots:
  void print(QString message);

private:
  std::ostream &stream;

};

#endif // IOSTREAMPRINTER_H
