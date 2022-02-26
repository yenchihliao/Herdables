#include <SFML/Graphics.hpp>
#include "unit/Unit.h"
#include <iostream>

int main(){
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "Tyranny");
	window.setFramerateLimit(15);
	Unit u;
	while(window.isOpen()){
		sf::Event event;
		sf::Vector2f pos = sf::Vector2f(sf::Mouse::getPosition(window));
		float dx = 0, dy = 0;
		while(window.pollEvent(event)){
			// Event window close
			if(event.type == sf::Event::Closed) window.close();
			if(event.type == sf::Event::MouseButtonPressed){
				if(event.key.code == sf::Mouse::Right){
					std::cout << "clicked" << std::endl;
					u.moveTo(pos);
				}
			}

			window.clear();
			u.update();
			window.draw(*u.shape);
			window.display();
		}
	}
}
