#include "chat.hpp"

void Sender::operate(boost_socket & socket)
{
	boost::asio::write(socket, boost::asio::buffer(client + '\n'));

	while (message != "CLOSE CONNECTION")
	{ 
		std::getline(std::cin, message);

		if (message != "") {
			boost::asio::write(socket, boost::asio::buffer(message + '\n'));
			std::cout << "\x1b[A" << client << ": " << message << '\n';
		}
	}
}

auto Client::connect()
{
	std::cin >> username;
	socket.connect(endpoint);

	Sender sender(username);
	sender.operate(socket);
}

auto Server::connect()
{
	acceptor.bind(endpoint);
	acceptor.listen(size);
	acceptor.accept(socket);

	boost::asio::streambuf buffer;

	get_client(buffer);
	read(buffer);
}

void Server::get_client(boost::asio::streambuf & buffer)
{
	boost::asio::read_until(socket, buffer, '\n');	
	std::istream input_stream(&buffer);
	std::getline(input_stream, client, '\n');
	
	std::cout << "User Connected: " << client << std::endl;
}

void Server::read(boost::asio::streambuf & buffer)
{
	std::string message;

	while (message != "CLOSE CONNECTION")
	{
		boost::asio::read_until(socket, buffer, '\n');	
		std::istream input_stream(&buffer);
		std::getline(input_stream, message, '\n');

		std::cout << client << ": " << message << std::endl;
	}
}

Connection::Connection(std::string raw_ip, size_t port_await, size_t port_send)
{
	Client client(raw_ip, port_send);
	Server server(port_await);

	std::thread t1{ &Server::connect, &server};
	Thread_Guard guard1(t1);

	std::thread t2{ &Client::connect, &client};
	Thread_Guard guard2(t2);		
}