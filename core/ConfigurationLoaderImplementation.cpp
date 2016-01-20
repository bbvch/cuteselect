#include "ConfigurationLoaderImplementation.h"

#include <QXmlSimpleReader>
#include <QXmlDefaultHandler>

#include <stdexcept>

#include <QDebug>

class ConfigurationData :
    public Configuration
{
public:
  QString backgroundColor() const override
  {
    return backgroundColorData;
  }

  QString backgroundColorData{"#000000"};

};

class Handler :
    public QXmlDefaultHandler
{
public:
  bool startElement(const QString& namespaceURI, const QString& localName, const QString& qName, const QXmlAttributes& atts) override
  {
    if (localName == "cuteselect") {
      configuration->backgroundColorData = attribute("background-color", configuration->backgroundColorData, atts);
    }
    return true;
  }

  ConfigurationData *configuration{new ConfigurationData()};

private:
  QString attribute(QString name, QString defaultValue, const QXmlAttributes& atts)
  {
    const auto index = atts.index(name);
    if (index == -1) {
      return defaultValue;
    } else {
      return atts.value(name);
    }
  }
};



QSharedPointer<Configuration> ConfigurationLoaderImplementation::load(QIODevice *data) const
{
  QXmlInputSource source{data};

  QXmlSimpleReader reader;
  Handler handler;
  reader.setContentHandler(&handler);

  if (!reader.parse(source)) {
    throw std::invalid_argument("error while parsing configuration");
  }

  return QSharedPointer<Configuration>(handler.configuration);
}
