#pragma once

#include <iostream>
#include <thread>

#include <boost/asio.hpp>

using boost_socket = boost::asio::ip::tcp::socket;

class Thread_Guard
{
public:

	explicit Thread_Guard(std::thread & thread) noexcept :
		m_thread(thread)
	{}

	Thread_Guard			(const Thread_Guard &) = delete;

	Thread_Guard & operator=(const Thread_Guard &) = delete;

	~Thread_Guard() noexcept
	{
		try { if (m_thread.joinable()) { m_thread.join(); } }
		catch (...) { std::abort(); }
	}

private:

	std::thread & m_thread;
};

class Sender
{
public:

	Sender() : client("Anonymous") {}
	Sender(const std::string & username) : client(username) {}

	void operate(boost_socket &);

private:
	std::string client;
	std::string message;
};

class Client
{
public:
	Client(std::string raw_ip_address, size_t port) : ios(), endpoint(
		boost::asio::ip::address::from_string(raw_ip_address), port), socket(ios, endpoint.protocol()) {}

	auto connect();

private:
	boost::asio::io_service ios;
	boost::asio::ip::tcp::endpoint endpoint;
	boost::asio::ip::tcp::socket socket;

	std::string username;
};

class Server
{
public:
	Server(size_t port) : ios(), endpoint(boost::asio::ip::address_v4::any(), port),
		acceptor(ios, boost::asio::ip::tcp::v4()), socket(ios) {}

	auto connect();

	void get_client(boost::asio::streambuf &);
	void read(boost::asio::streambuf &);

private:
	boost::asio::io_service ios;
	boost::asio::ip::tcp::endpoint endpoint;
	boost::asio::ip::tcp::acceptor acceptor;
	boost::asio::ip::tcp::socket socket;

	std::string client;
	const size_t size = 30U;
};

class Connection
{
public:
	Connection(std::string, size_t, size_t);
};