#include <FileDownloader.h>

bool FileDownloader::DownloadVideo(std::string url)
{
   bool result = true;

	SSLInitializer sslInitializer;
	HTTPStreamFactory::registerFactory();
	HTTPSStreamFactory::registerFactory();
	FTPStreamFactory::registerFactory();
	FTPSStreamFactory::registerFactory();

	// Note: we must create the passphrase handler prior Context
	// SharedPtr<InvalidCertificateHandler> ptrCert = new ConsoleCertificateHandler(false); // ask the user via console
	// Context::Ptr ptrContext = new Context(Context::TLS_CLIENT_USE, "", "", "", 
   //    Context::VERIFY_NONE, 9, false, "ALL:!ADH:!LOW:!EXP:!MD5:@STRENGTH");
	// SSLManager::instance().initializeClient(0, ptrCert, ptrContext);

	try
	{
		URI uri(url);
		std::unique_ptr<std::istream> pStr(URIStreamOpener::defaultOpener().open(uri));

      std::ofstream ofs(outputPath, std::fstream::binary);
		StreamCopier::copyStream(*pStr.get(), ofs);
	}
	catch (Exception& exc)
	{
		std::cerr << exc.displayText() << std::endl;
		result = false;
	}

   return result;
}

// blob:https://www.youtube.com/4972dc09-b8d2-4803-a124-bb3afd4e84ff

// bool FileDownloader::DownloadVideo(std::string url)
// {
//    // TODO
//    bool result = true;
   
//    try
//    {
//       Poco::URI uri(url);
//       std::string path(uri.getPathAndQuery());

//       const Poco::Net::Context::Ptr context = new Poco::Net::Context(
//          Poco::Net::Context::CLIENT_USE, "", "", "",
//          Poco::Net::Context::VERIFY_NONE, 9, false,
//          "ALL:!ADH:!LOW:!EXP:!MD5:@STRENGTH");

//       Poco::Net::HTTPSClientSession session(uri.getHost(), uri.getPort(), context);
//       Poco::Net::HTTPRequest request(Poco::Net::HTTPRequest::HTTP_GET, path, Poco::Net::HTTPMessage::HTTP_1_1);
//       Poco::Net::HTTPResponse response;

//       session.sendRequest(request);
//       std::istream &rs = session.receiveResponse(response);
//       std::cout << response.getStatus() << " " << response.getReason() << std::endl;
      
//       if (response.getStatus() != Poco::Net::HTTPResponse::HTTP_UNAUTHORIZED) 
//       {
//          std::ofstream ofs(outputPath, std::fstream::binary);
//          Poco::StreamCopier::copyStream(rs, ofs);
//       }
//    }
//    catch(const std::exception& e)
//    {
//       std::cerr << e.what() << '\n';
//       result = false;
//    }
   
//    return result;
// }
