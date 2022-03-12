#include <SFML/Graphics.hpp>
#include "unit/Unit.h"
#include <iostream>

void logTime(const char* s, sf::Clock &c){
	static float c_previous;
	float c_new = c.getElapsedTime().asSeconds();
	float diff = c_new - c_previous;

	if(diff > 1){
		std::cout << s << ": ";
		std::cout <<  c_new - c_previous << std::endl;
	}
	c_previous = c_new;
}

int main(){
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "Tyranny");
	Unit u;

	// window.setFramerateLimit(15);
	sf::Clock clock;
	float timer=0, delay=0.1;
	int counter = 0;
	sf::Clock time_counter;


	while(window.isOpen()){
		float time = clock.getElapsedTime().asSeconds();
		counter++;
		clock.restart();
		timer+=time;

		sf::Event event;
		float dx = 0, dy = 0;
		while(window.pollEvent(event)){
			// Event window close
			if(event.type == sf::Event::Closed) window.close();
			if(event.type == sf::Event::MouseButtonPressed){
				if(event.key.code == sf::Mouse::Right){
					std::cout << "clicked" << std::endl;
					u.moveTo(sf::Vector2f(sf::Mouse::getPosition(window)));
				}
			}
		}

		if(timer > delay){
			logTime("b update", time_counter);
			timer = 0;
			u.update();
		}
		logTime("b redraw", time_counter);
		window.clear();
		window.draw(*u.shape);
		window.display();
		logTime("a redraw", time_counter);
	}
}
