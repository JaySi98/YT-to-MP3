#include <iostream>
#include <Include/Config.h>
#include <CommandParser.h>
#include <FileDownloader.h>


int main(int argc, char* argv[])
{   
    CommandParser commandParser;
    commandParser.ParseCommands(argc, argv);

    if(commandParser.result == RESULT_OK_URL)
    {
        FileDownloader downloader;
        if(!downloader.DownloadVideo(commandParser.GetUrl()))
        {
            std::cout << "Failed to download video" << std::endl;
            return EXIT_FAILURE;
        }
    }
    else
    {
        std::cout << "Url must be specified. Example --u <url>" << std::endl;
    }

   return EXIT_SUCCESS;
}
