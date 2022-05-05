#include "tron_game.hpp"

class Connection_Client
{
public:
	Connection_Client(std::string ip, int port) : io_service(), endpoint(
			boost::asio::ip::address::from_string(ip), port), socket(io_service, endpoint.protocol()) {}

	void connect(const std::string & background, int W, int H)
	{
		try
		{
			system("pause");
			socket.connect(endpoint);

			Game game(background, W, H);
			game.run(socket); 
		}
		catch (boost::system::system_error & e)
		{
			std::cout << "Error occurred: " << e.code() << " desc: " << e.what() << std::endl;
		}
	}
	
private:
	boost::asio::io_service io_service;
	boost::asio::ip::tcp::endpoint endpoint;
	boost::asio::ip::tcp::socket socket;
};

int main()
{
	const int W = 600;
	const int H = 480;

	const auto ip = "127.0.0.1"; //"192.168.31.64";
	const auto port = 3333;

	Connection_Client client(ip, port);
	client.connect("background.jpg", W, H);

	return EXIT_SUCCESS;
}
