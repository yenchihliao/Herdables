#include "Unit.h"
#include <cmath>

Unit::Unit(){
	std::cout << "default unit" << std::endl;
	this->shape = new(sf::CircleShape)(10);
	this->shape->setFillColor(sf::Color::Blue);
	this->speed = 3;
	this->isWalking = false;
}
Unit::~Unit(){
	delete this->shape;
}
float Unit::distance(const sf::Vector2f& from, const sf::Vector2f& to){
	float ret = std::sqrt(std::pow(to.x-from.x, 2) + std::pow(to.y-from.y, 2));
	return ret;
}
void Unit::moveTo(sf::Vector2f pos_){
	std::cout << "moving to " << pos_.x << ", " << pos_.y << std::endl;
	this->targetPosition = pos_;
	this->isWalking = true;
}
void Unit::update(){
	// Keep walking to the target position
	if(this->isWalking){
		sf::Vector2f pos = this->targetPosition - this->shape->getPosition();
		// pos = &this->shape->getPosition()
		// float len = this->distance(this->shape->getPosition(), this->targetPosition);
		float len = std::sqrt(std::pow(pos.x, 2) + std::pow(pos.y, 2));
		if(len <= 1){
			this->shape->setPosition(sf::Vector2f(this->targetPosition));
			this->isWalking = false;
		}else{
			float dx = pos.x / len * this->speed;
			float dy = pos.y / len * this->speed;
			this->shape->move(dx, dy);
		}
	}
}
void Unit::takeDamage(uint8_t damage_){
	if(damage_ >= this->health){
		delete this;
	}else{
		this->health -= damage_;
	}
	return;
}

bool Unit::isClicked(sf::Vector2i pos){
	std::cout << "clicked?" << pos.x << " " << pos.y << " " << this->shape->getPosition().x << " " << this->shape->getPosition().y << std::endl;
	if(this->distance(sf::Vector2f(pos), this->shape->getPosition()) <= 9){
		return true;
	}
	return false;
}
