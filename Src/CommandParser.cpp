#include <CommandParser.h>

CommandParser::CommandParser() : URLOption(nullptr), OutputOption(nullptr)
{
    addHelpOption();
    addAppOptions();
}

CommandParser::~CommandParser()
{
    delete URLOption;
    delete OutputOption;
}

void CommandParser::process(QCoreApplication& app)
{
    parser.process(app);
    outputPath = parser.value(*OutputOption);
    ytURL = parser.value(*OutputOption);
}

void CommandParser::addHelpOption(void)
{
    parser.addHelpOption();
    parser.addPositionalArgument("url",    QCoreApplication::translate("main", "Youtube link"));
    parser.addPositionalArgument("output", QCoreApplication::translate("main", "Output filename"));
}

void CommandParser::addAppOptions(void)
{
    URLOption = new QCommandLineOption(QStringList() << "u" << "url",     
        QCoreApplication::translate("main", "Youtube link"));
    
    OutputOption = new QCommandLineOption(QStringList() << "o" << "output",  
        QCoreApplication::translate("main", "Output filename"), 
        QCoreApplication::translate("main", "filename"));

    parser.addOption(*URLOption);
    parser.addOption(*OutputOption);
}

bool CommandParser::isURLSet(void)
{
    return parser.isSet(*URLOption);
}

bool CommandParser::isOutputset(void)
{
    return parser.isSet(*OutputOption);
}

QString CommandParser::getOutputPath(void)
{
    return ytURL;
}

QString CommandParser::getURL(void)
{
    return outputPath;
}