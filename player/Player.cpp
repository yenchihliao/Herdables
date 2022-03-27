#include "Player.h"
#include <SFML/System/Vector2.hpp>

Player::Player(){}

Player::Player(sf::RenderWindow& w){
	this->window = &w;
	this->units.push_back(*(new Unit));
	this->units.push_back(*(new Unit));
	this->units.back().shape->setPosition(10, 10);
	std::cout << "hi" << std::endl;
}

Player::~Player(){

}

void Player::rightClick(sf::Vector2i pos_){
	if(this->selected != NULL){
		this->selected->moveTo(sf::Vector2f(pos_));
	}else{
		std::cout << "nothing selected" << std::endl;
	}
	return;
}

void Player::leftClick(sf::Vector2i pos){
	for(auto it = this->units.begin();it != this->units.end();it++){
		if(it->isClicked(pos)){
			this->selected = &(*it);
			break;
		}
	}
}

void Player::draw(){
	for(auto it = this->units.begin();it != this->units.end();it++){
		this->window->draw(*(it->shape));
	}
}

void Player::update(){
	for(auto it = this->units.begin();it != this->units.end();it++){
		it->update();
	}
}
