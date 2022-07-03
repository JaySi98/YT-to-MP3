#include <CommandParser.h>

CommandParser::CommandParser() :
    result(RESULT_ERROR), 
    ImgURLRegex("(?:https?:\\/\\/)?(?:www\\.)?youtu\\.?be(?:\\.com)?\\/?.*(?:watch|embed)?(?:.*v=|v\\/|\\/)([\\w\\-_]+)\\&?"), 
    ImgUrl("")
{ }

void CommandParser::ParseCommands(int argc, char* argv[])
{
    po::options_description desc("Allowed options");
    desc.add_options()
        ("h", "Shows program options")
        ("u", po::value<std::string>(), "YouTube link");
    
    po::variables_map vm;
    po::store(po::parse_command_line(argc,argv,desc),vm);
    po::notify(vm);

    if(vm.count("h"))
    {
        std::cout << desc << std::endl;
        result = RESULT_HELP;
        return;
    }

    if(vm.count("u"))
    {
        std::string option = vm["u"].as<std::string>(); 
        checkURL(option);
    }
}

void CommandParser::checkURL(std::string line)
{
    if(regex_match(line, regex(ImgURLRegex), match_partial))
    {
        ImgUrl = line;
        result = RESULT_OK_URL;
    }
}

std::string CommandParser::GetUrl(void)
{
    if(result == RESULT_OK_URL)
        return ImgUrl;
    else
        throw "No valid URL specified";
}
