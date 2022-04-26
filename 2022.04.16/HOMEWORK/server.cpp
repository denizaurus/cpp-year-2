#include <iostream>

#include <boost/asio.hpp>

//class Acceptor
//{
//public:
//
//	Acceptor() { operate(); }
//
//	void operate()
//	{
//		boost::asio::streambuf buffer;
//
//		while (message != "CLOSE CONNECTION")
//		{
//			boost::asio::read_until(socket, buffer, '\n');	
//			std::istream input_stream(&buffer);
//			std::getline(input_stream, message, '\n');
//
//			std::cout << message << std::endl;;
//		}
//	}
//
//private:
//	std::string message;
//};

int main(int argc, char ** argv)
{
	auto port = 26000U;
	auto size = 30U;

	boost::asio::ip::address ip_address =
		boost::asio::ip::address_v4::any();

	boost::asio::ip::tcp::endpoint endpoint(ip_address, port);

	std::cout << "Endpoint ready" << std::endl;

	system("pause");

	// PASSIVE SOCKET

	boost::asio::io_service ios;

	boost::asio::ip::tcp protocol = boost::asio::ip::tcp::v4();

	try 
	{
		boost::asio::ip::tcp::acceptor acceptor(ios, protocol);

		acceptor.bind(endpoint);

		acceptor.listen(size);

		boost::asio::ip::tcp::socket socket(ios);

		acceptor.accept(socket);

		boost::asio::streambuf buffer;
		std::string username;

		boost::asio::read_until(socket, buffer, '\n');	
		std::istream input_stream(&buffer);
		std::getline(input_stream, username, '\n');

		std::string message;

		while (message != "CLOSE CONNECTION")
		{
			boost::asio::read_until(socket, buffer, '\n');	
			std::istream input_stream(&buffer);
			std::getline(input_stream, message, '\n');

			std::cout << username << ": " << message << std::endl;
		}
	}
	catch (boost::system::system_error & e) 
	{
		std::cout << "Error occurred! Error code = " << e.code() << ". Message: " << e.what();
	}

	system("pause");
}