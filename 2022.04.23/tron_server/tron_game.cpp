#include "tron_game.hpp"

Screen::Screen(std::string background, int W, int H) : sprite(), t(), texture()
{
	texture.loadFromFile(background);
	sf::Sprite sBackground(texture);

	t.create(W, H);
	t.setSmooth(true);
	sprite.setTexture(t.getTexture());
	t.clear();  t.draw(sBackground);
} 

Player::Player(sf::Color c, int W, int H) : color(c), W(W), H(H)
{
	std::random_device rd;  
	std::mt19937 gen(rd()); 
	std::uniform_int_distribution<> rand_x(0, W - 1), rand_y(0, H - 1), rand_dir(0, 3);

	x = rand_x(gen);
	y = rand_y(gen);
	dir = rand_dir(gen);
}

void Player::tick()
{
	/* Movement with set direction */

	switch (dir)
	{
	case 0: ++y; break;
	case 1: --x; break;
	case 2: ++x; break;
	case 3: --y; break;
	}

	if (x >= W) x = 0;  else if (x < 0) x = W - 1;
	if (y >= H) y = 0;  else if (y < 0) y = H - 1;
}


void Local::action(boost::asio::ip::tcp::socket & socket)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)  && dir != 2) dir = 1;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && dir != 1) dir = 2;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)    && dir != 0) dir = 3;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)  && dir != 3) dir = 0;

	json send = json::array({ x, y, dir });
	boost::asio::write(socket, boost::asio::buffer(send.dump() + '!'));
}

void Connected::action(boost::asio::ip::tcp::socket & socket)
{
	std::string j;

	boost::asio::streambuf buffer;
	boost::asio::read_until(socket, buffer, '!');	
	std::istream input_stream(&buffer);
	std::getline(input_stream, j, '!');

	json receive = json::parse(j);
	x   = receive[0]; y = receive[1];
	dir = receive[2];
}

void Game::run(boost::asio::ip::tcp::socket & socket)
{
	while (window.isOpen())
	{
		sf::Event e;
		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
				window.close();
		}

		if (!game)    continue;

		p1.action(socket);  p2.action(socket);

		size_t ticks = 0;
		while (ticks < speed && game)
		{
			p1.tick();             p2.tick();
			p1.field(field, game); p2.field(field, game);

			sf::CircleShape c(3);
			p1.create(c); screen.draw(c);
			p2.create(c); screen.draw(c);
			screen.display();

			++ticks;
		}

		////// draw  ///////
		window.clear();
		window.draw(screen.sprite);
		window.display();
	}
}