#include <iostream>

#include <boost/asio.hpp>

//using sock = boost::asio::ip::tcp::socket;
//
//class Sender
//{
//public:
//
//	Sender(sock & socket) : client("Anonymous: ") { operate(); }
//	Sender(sock & socket, const std::string & username) : client(username + ": ") { operate(); }
//
//	void operate()
//	{
//		while (message != "CLOSE CONNECTION")
//		{
//			std::cout << client;
//			std::getline(std::cin, message);
//			boost::asio::write(socket, boost::asio::buffer(client + message));
//		}
//	}
//
//private:
//	std::string client;
//	std::string message;
//};

int main(int argc, char ** argv)
{
	// ENDPOINT

	std::string raw_ip_address = "127.0.0.1";
	auto port = 26000U;
	
	system("pause");

	// SOCKET

	try 
	{
		boost::asio::ip::tcp::endpoint endpoint(
			boost::asio::ip::address::from_string(raw_ip_address), port);

		boost::asio::io_service ios;

		boost::asio::ip::tcp::socket socket(ios, endpoint.protocol());

		socket.connect(endpoint);

		std::string username;
		std::cout << "Input username: ";
		std::getline(std::cin, username);
		boost::asio::write(socket, boost::asio::buffer(username + '\n'));

		std::string message;

		while (message != "CLOSE CONNECTION")
		{
			std::cout << username << ": ";
			std::getline(std::cin, message);
			boost::asio::write(socket, boost::asio::buffer(message + '\n'));
		}
	}
	catch (boost::system::system_error & e) 
	{
		std::cout << "Error occured! Error code = " << e.code() << ". Message: " << e.what() << std::endl;

		system("pause");

		return e.code().value();
	}
}