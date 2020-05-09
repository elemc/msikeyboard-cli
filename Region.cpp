//
// Created by alex on 09.05.2020.
//

#include "Region.h"
#include <utility>

Region::Region(string name, string color, string intensity)
        : name(std::move(name)), color(std::move(color)), intensity(std::move(intensity)) {}
Region::Region() : name(""), color(""), intensity("") {}

string Region::Name() {
    return this->name;
}

string Region::Color() {
    return this->color;
}

string Region::Intensity() {
    return this->intensity;
}