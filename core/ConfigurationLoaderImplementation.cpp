#include "ConfigurationLoaderImplementation.h"

#include <QXmlSimpleReader>
#include <QXmlDefaultHandler>
#include <QMap>

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
      QMap<QString,std::function<void(QString)>> attributeWriter;
      attributeWriter["background-color"] = [this](QString value){ listener.setBackgroundColor(value); };
      attributeWriter["relative-width"] = [this](QString value){ listener.setRelativeWidth(value.toDouble()); };
      attributeWriter["relative-height"] = [this](QString value){ listener.setRelativeHeight(value.toDouble()); };

      for (int i = 0; i < atts.count(); i++) {
        const auto writer = attributeWriter.value(atts.localName(i), [](QString){});
        writer(atts.value(i));
      }
    } else if (localName == "image") {
      listener.addImage(atts.value("file"));
    }
    return true;
  }

private:
  ConfigurationListener &listener;

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
