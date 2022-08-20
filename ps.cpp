
/*   position script(.ps) handling c++ file   */

#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <chrono>
#include <vector>

#include <SFML/Graphics.hpp>

#include "common.h"

ps_file.open("great.ps"):

bool read_ps_file( std::string filename ) {

    std::vector<sf::Vector2i> position_script_data;



    return true;

}


void write_ps_file(void) {

    while (!record_flag) {
        ps_file << mouse_x << " " << mouse_y;
        std::cout << mouse_x << " " << mouse_y;
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }

}
