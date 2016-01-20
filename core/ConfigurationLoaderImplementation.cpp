#include "ConfigurationLoaderImplementation.h"

#include <QXmlSimpleReader>
#include <QXmlDefaultHandler>

#include <stdexcept>
#include <functional>

class Handler :
    public QXmlDefaultHandler
{
public:
  Handler(ConfigurationListener &aListener) :
    listener{aListener}
  {
  }

  bool startElement(const QString& namespaceURI, const QString& localName, const QString& qName, const QXmlAttributes& atts) override
  {
    if (localName == "cuteselect") {
      readAttribute(atts, "background-color", [this](QString value){
        listener.setBackgroundColor(value);
      });
    }
    return true;
  }

private:
  ConfigurationListener &listener;

  void readAttribute(const QXmlAttributes& atts, QString name, std::function<void(QString)> writer)
  {
    const auto index = atts.index(name);
    if (index != -1) {
      writer(atts.value(name));
    }
  }

};



ConfigurationLoaderImplementation::ConfigurationLoaderImplementation(ConfigurationListener &aListener) :
  listener{aListener}
{
}

void ConfigurationLoaderImplementation::load(QIODevice *data) const
{
  QXmlInputSource source{data};

  QXmlSimpleReader reader;
  Handler handler{listener};
  reader.setContentHandler(&handler);

  if (!reader.parse(source)) {
    throw std::invalid_argument("error while parsing configuration");
  }
}
