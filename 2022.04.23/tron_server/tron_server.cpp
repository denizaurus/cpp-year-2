#include "tron_game.hpp"

class Connection_Server
{
public:
    Connection_Server(int port) : io_service(), endpoint(boost::asio::ip::address_v4::any(), port),
        acceptor(io_service, endpoint.protocol()), socket(io_service) {} 

    void connect(const std::string & background, int W, int H)
    {
        try
        {
            acceptor.bind(endpoint);
	        acceptor.listen(1);

            acceptor.accept(socket);

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
    boost::asio::ip::tcp::acceptor acceptor;  
    boost::asio::ip::tcp::socket socket;
};

int main()
{
    const auto port = 3333;
    const int W = 600;
    const int H = 480;

    Connection_Server server(port);
    server.connect("background.jpg", W, H);

    return EXIT_SUCCESS;
}
