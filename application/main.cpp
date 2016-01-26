#include <ConfigurationLoaderImplementation.h>
#include <FilePathResolverImplementation.h>
#include <Configuration.h>
#include <IostreamPrinter.h>
#include <ItemListImplementation.h>


#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QCommandLineParser>
#include <QQmlContext>

#include <QFile>

#include <iostream>

static QString getConfigFilename(const QStringList &arguments)
{
  QCommandLineParser parser;

  parser.addPositionalArgument("filename", "configuration file");

  if (!parser.parse(arguments)) {
    parser.showHelp(-1);
  }

  const auto filename = parser.positionalArguments();

  if (filename.size() != 1) {
    parser.showHelp(-1);
  }

  return filename[0];
}

int main(int argc, char *argv[])
{

    QGuiApplication app(argc, argv);
    app.setApplicationName("cuteselect");

    const auto configFilename = getConfigFilename(app.arguments());
    QFile configFile{configFilename};
    if (!configFile.open(QFile::ReadOnly)) {
      std::cerr << "could not open file " << configFilename.toStdString() << std::endl;
      return -1;
    }

    Configuration main{new ItemListImplementation()};
    FilePathResolverImplementation pathResolver;
    pathResolver.setBase(QFileInfo(configFilename).absolutePath());
    ConfigurationLoaderImplementation configLoader{main, pathResolver};

    IostreamPrinter printer{std::cout};
    QObject::connect(&main, SIGNAL(quit(QString)), &printer, SLOT(print(QString)));
    QObject::connect(&main, SIGNAL(quit(QString)), &app, SLOT(quit()));

    configLoader.load(&configFile);


    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("configuration", &main);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));


    return app.exec();
}
