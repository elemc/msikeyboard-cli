//
// Created by alex on 09.05.2020.
//

#include "Region.h"
#include <utility>

Region::Region(std::string name, std::string color, std::string intensity)
        : name(std::move(name)), color(std::move(color)), intensity(std::move(intensity)) {}
Region::Region() : name(""), color(""), intensity("") {}

std::string Region::Name() {
    return this->name;
}

std::string Region::Color() {
    return this->color;
}

std::string Region::Intensity() {
    return this->intensity;
}