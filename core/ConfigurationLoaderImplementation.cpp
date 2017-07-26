/*
 * (C) Copyright 2016
 * Urs Fässler, bbv Software Services, http://bbv.ch
 *
 * SPDX-License-Identifier:	GPL-3.0+
 */

#include "ConfigurationLoaderImplementation.h"

#include <ImageItemImplementation.h>

#include <QXmlSimpleReader>
#include <QXmlDefaultHandler>
#include <QMap>

#include <stdexcept>
#include <functional>

class Handler :
    public QXmlDefaultHandler
{
public:
  Handler(ConfigurationListener &aListener, const FilePathResolver &aPathResolver) :
    listener{aListener},
    pathResolver{aPathResolver}
  {
  }

  bool startElement(const QString&, const QString& localName, const QString&, const QXmlAttributes& atts) override
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
      const auto file = atts.value("file");
      const auto label = atts.value("label");
      const auto path = pathResolver.resolve(file);
      const auto value = atts.value("value");
      listener.addImage(new ImageItemImplementation(path, label, value));
    }
    return true;
  }

private:
  ConfigurationListener &listener;
  const FilePathResolver &pathResolver;

};



ConfigurationLoaderImplementation::ConfigurationLoaderImplementation(ConfigurationListener &aListener, const FilePathResolver &aPathResolver) :
  listener{aListener},
  pathResolver{aPathResolver}
{
}

void ConfigurationLoaderImplementation::load(QIODevice *data) const
{
  QXmlInputSource source{data};

  QXmlSimpleReader reader;
  Handler handler{listener, pathResolver};
  reader.setContentHandler(&handler);

  if (!reader.parse(source)) {
    throw std::invalid_argument("error while parsing configuration");
  }
}
