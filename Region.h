//
// Created by alex on 09.05.2020.
//

#ifndef MSIKEYBOARD_CLI_REGION_H
#define MSIKEYBOARD_CLI_REGION_H

#include <string>
#include <msikeyboard.h>

class Region {
public:
    Region();
    Region(std::string name, std::string color, std::string intensity);
    explicit Region(std::string raw);
    Region(std::string name, unsigned int r, unsigned int g, unsigned int b);

    std::string Name();
    std::string Color();
    std::string Intensity();

    RGB GetRGB() const;

private:
    std::string name;
    std::string color;
    std::string intensity;

    unsigned int rgbR;
    unsigned int rgbG;
    unsigned int rgbB;
};


#endif //MSIKEYBOARD_CLI_REGION_H
