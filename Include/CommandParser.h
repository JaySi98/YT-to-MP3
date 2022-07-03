#pragma once

#include <string>
#include <iostream>
#include <boost/regex.hpp>
#include <boost/filesystem.hpp>
#include <boost/program_options.hpp>

using namespace boost;
namespace po = boost::program_options;

enum ParseResult
{
    RESULT_ERROR    = 0x00,
    RESULT_OK_URL   = 0x01,        
    RESULT_HELP     = 0x04,
};

class CommandParser
{
public:
    CommandParser(void);
    void ParseCommands(int argc, char* argv[]);
    std::string GetUrl(void);
    
    ParseResult result;

private:
    void checkURL(std::string line);

    const std::string ImgURLRegex;
    std::string ImgUrl;
};