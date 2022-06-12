#include <QCommandLineParser>

class CommandParser
{
public:
    CommandParser();
    ~CommandParser();
    
    void process(QCoreApplication& app);
    bool isURLSet(void);
    bool isOutputset(void);
    QString getOutputPath(void);
    QString getURL(void);

private:
    void addHelpOption(void);
    void addAppOptions(void);

    QCommandLineParser parser;
    QCommandLineOption* URLOption;
    QCommandLineOption* OutputOption;
};