#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <iostream>
#include <string>
#include <cinttypes>
#include <cmath>

class Unit{
public:
	uint8_t health;
	uint8_t owner;
	uint8_t speed;
	sf::Vector2f targetPosition;
	sf::Color c;
	bool isWalking;
	sf::Shape *shape;
	Unit();
	~Unit();
	void moveTo(sf::Vector2f);
	void update();
	void takeDamage(uint8_t);
private:
	float distance(const sf::Vector2f&, const sf::Vector2f&);
};
