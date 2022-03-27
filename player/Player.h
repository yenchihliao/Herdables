#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>
#include <list>
#include "../unit/Unit.h"
// #include <string>
// #include <cinttypes>
// #include <cmath>

class Player{
public:
	// Heart *hearts;
	uint8_t id;
	sf::Color c;
	Player();
	Player(sf::RenderWindow&);
	~Player();
	void rightClick(sf::Vector2i pos);
	void leftClick(sf::Vector2i pos);
	void draw();
	void update();

private:
	float score;
	sf::RenderWindow* window;
	Unit* selected;
	std::list<Unit> units;
};
