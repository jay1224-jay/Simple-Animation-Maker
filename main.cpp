#include <SFML/Graphics.hpp>

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <thread>
#include <chrono>

typedef sf::RectangleShape rect;

#include "button.hpp"
#include "common.h"

#define print(x) std::cout << x << std::endl;


int mouse_x, mouse_y;
bool record_flag = false;

std::ofstream ps_file("great.ps");

void write_ps_file(void);

int main() {

    sf::RenderWindow window(sf::VideoMode(1000, 700), "Simple Animation Maker - SAM");

    Button start_btn;
    start_btn.setSize(sf::Vector2f(100.f, 70.f));
    start_btn.setFillColor(sf::Color::Black);
    start_btn.setPosition(400, 250);

    Button end_btn;
    end_btn.setSize(sf::Vector2f(100.f, 70.f));
    end_btn.setFillColor(sf::Color::Red);
    end_btn.setPosition(600, 250);




    
    std::thread record_thread;

    
    while ( window.isOpen() ) {

        sf::Event event;
        while ( window.pollEvent(event) ) {

            if (event.type == sf::Event::Closed) 
                window.close();

            else if ( event.type == sf::Event::MouseButtonPressed ) {
                if ( event.mouseButton.button == sf::Mouse::Left ) {

                    if ( start_btn.isClick( event.mouseButton ) && !record_flag) {

                        record_flag = true;
                        record_thread = std::thread(write_ps_file);


                    } else if ( end_btn.isClick( event.mouseButton ) ) {

                        record_flag = false;
                    }
                }
            }

        }


        if (!record_flag) {

            record_flag = false;


        }





        window.clear(sf::Color::White);


        window.draw(start_btn);
        window.draw(end_btn);

        window.display();
    }
}

