#include <iostream>
#include <memory>
#include <fstream>

#include <Poco/URIStreamOpener.h>
#include <Poco/Path.h>
#include <Poco/URI.h>
#include <Poco/Exception.h>
#include <Poco/MD5Engine.h>
#include <Poco/DigestStream.h>
#include <Poco/Net/Context.h>
#include <Poco/Net/HTTPSClientSession.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/Net/HTTPRequest.h>

#include "Poco/Net/HTTPStreamFactory.h"
#include "Poco/Net/HTTPSStreamFactory.h"
#include "Poco/Net/FTPStreamFactory.h"
#include "Poco/Net/FTPSStreamFactory.h"
#include "Poco/Net/ConsoleCertificateHandler.h"
#include "Poco/Net/SSLManager.h"
#include "Poco/Net/KeyConsoleHandler.h"

using Poco::URIStreamOpener;
using Poco::StreamCopier;
using Poco::Path;
using Poco::URI;
using Poco::SharedPtr;
using Poco::Exception;
using Poco::Net::HTTPStreamFactory;
using Poco::Net::HTTPSStreamFactory;
using Poco::Net::FTPStreamFactory;
using Poco::Net::FTPSStreamFactory;
using Poco::Net::SSLManager;
using Poco::Net::Context;
using Poco::Net::KeyConsoleHandler;
using Poco::Net::PrivateKeyPassphraseHandler;
using Poco::Net::InvalidCertificateHandler;
using Poco::Net::ConsoleCertificateHandler;

class SSLInitializer
{
public:
	SSLInitializer()
	{
		Poco::Net::initializeSSL();
	}

	~SSLInitializer()
	{
		Poco::Net::uninitializeSSL();
	}
};

class FileDownloader
{
public:
    bool DownloadVideo(std::string url);

private:
    const std::string outputPath = "output.mp3";
};