//
// Created by alex on 09.05.2020.
//

#ifndef MSIKEYBOARD_CLI_REGION_H
#define MSIKEYBOARD_CLI_REGION_H

#include <string>

class Region {
public:
    Region();
    Region(std::string name, std::string color, std::string intensity);

    std::string Name();
    std::string Color();
    std::string Intensity();

private:
    std::string name;
    std::string color;
    std::string intensity;
};


#endif //MSIKEYBOARD_CLI_REGION_H
