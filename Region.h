//
// Created by alex on 09.05.2020.
//

#ifndef MSIKEYBOARD_CLI_REGION_H
#define MSIKEYBOARD_CLI_REGION_H

using namespace std;

#include <string>

class Region {
public:
    Region();
    Region(string name, string color, string intensity);

    string Name();
    string Color();
    string Intensity();

private:
    string name;
    string color;
    string intensity;
};


#endif //MSIKEYBOARD_CLI_REGION_H
