#include "Unit.h"

Unit::Unit(){
	std::cout << "default unit" << std::endl;
	this->shape = new(sf::CircleShape)(10);
	this->shape->setFillColor(sf::Color::Blue);
}
Unit::~Unit(){
	delete this->shape;
}

void Unit::moveTo(sf::Vector2i pos_){
	std::cout << "moving to " << pos_.x << ", " << pos_.y << std::endl;
	this->shape->setPosition(pos_.x, pos_.y);
}
void Unit::takeDamage(uint8_t damage_){
	if(damage_ >= this->health){
		delete this;
	}else{
		this->health -= damage_;
	}
	return;
}
