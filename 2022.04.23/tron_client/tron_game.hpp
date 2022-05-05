#pragma once

#include <SFML/Graphics.hpp>
#include <boost/asio.hpp>
#include "json.hpp"

#include <random>
#include <string>
#include <atomic>
#include <vector>

#include <iostream>

using json = nlohmann::json;

class Screen
{
public:
    Screen(std::string background, int W, int H);

    void draw(const sf::Drawable & drawable) { t.draw(drawable); }
    void display() { t.display(); }

    sf::Sprite sprite;
private:
    sf::RenderTexture t;
    sf::Texture texture;
};

class Player
{ 
public:

    Player(sf::Color c, int W, int H);

    virtual void action(boost::asio::ip::tcp::socket & socket) = 0;

    void tick();

    void create(sf::Shape & shape) 
    { 
        shape.setPosition(x, y); 
        shape.setFillColor(color); 
    }

    void field(std::vector < std::vector < bool > > & field, 
             std::atomic < bool > & flag)
    {
        if (field[x][y] == 1) flag = 0;
        field[x][y] = 1;
    }

protected: 
    int x, y, dir;
    const int W, H;
    sf::Color color;
};

class Local : public Player
{
public:
    Local(sf::Color c, int W, int H) : Player(c, W, H) {};

    void action(boost::asio::ip::tcp::socket & socket);
};

class Connected : public Player
{
public:
    Connected(sf::Color c, int W, int H) : Player(c, W, H) {};

    void action(boost::asio::ip::tcp::socket & socket);
};

class Game
{
public:
    Game(std::string background, size_t W, size_t H) :
        window(sf::VideoMode(W, H), "The Tron Game!"), screen(background, W, H),
        p1(sf::Color::Blue, W, H), p2(sf::Color::Red, W, H), field(W, std::vector < bool >(H, 0)), game(1)
    {
        window.setFramerateLimit(60);
    }

    void run(boost::asio::ip::tcp::socket & socket);

private:
    sf::RenderWindow window;
    Screen screen;
    Local p1;
    Connected p2;

    std::vector < std::vector < bool > > field;
    std::atomic < bool > game;

    const int speed = 4;
};