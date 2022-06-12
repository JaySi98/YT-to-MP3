#include <iostream>
#include <Include/Config.h>
#include <QDebug>
#include <CommandParser.h>

int main(int argc, char* argv[])
{
    QCoreApplication app(argc, argv);
    QCoreApplication::setApplicationName("YT-to-MP3");
    
    CommandParser commandParser;
    commandParser.process(app);

    if(commandParser.isURLSet() && commandParser.isOutputset())
    {
        // qInfo() << "URL: "    << commandParser.getURL();
        // qInfo() << "output: " << commandParser.getOutputPath();
    }
    else
    {
        qInfo() << "URL and output file path must be specified";
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
