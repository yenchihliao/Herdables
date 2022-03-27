#include <SFML/Graphics.hpp>
#include "player/Player.h"
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
	Player player(window);

	// window.setFramerateLimit(15);
	sf::Clock clock;
	float timer=0, delay=0.1;
	int counter = 0;
	sf::Clock time_counter;


	std::cout << "hi again" << std::endl;
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
					player.rightClick(sf::Mouse::getPosition(window));
				}else if(event.key.code == sf::Mouse::Left){
					std::cout << "clicked" << std::endl;
					player.leftClick(sf::Mouse::getPosition(window));
				}
			}
		}

		if(timer > delay){
			// logTime("b update", time_counter);
			timer = 0;
			player.update();
		}
		// logTime("b redraw", time_counter);
		window.clear();
		player.draw();
		window.display();
		// logTime("a redraw", time_counter);
	}
}
