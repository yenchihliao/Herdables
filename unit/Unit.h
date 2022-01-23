#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <iostream>
#include <string>
#include <cinttypes>

class Unit{
public:
	uint8_t health;
	uint8_t owner;
	sf::Color c;
	sf::Shape *shape;
	Unit();
	~Unit();
	void moveTo(sf::Vector2i);
	void takeDamage(uint8_t);
};
