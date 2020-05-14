//
// Created by alex on 09.05.2020.
//

#include "Region.h"
#include <utility>
#include <boost/algorithm/string.hpp>
#include <vector>
#include <stdexcept>

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

Region::Region(std::string raw) {
    std::vector<std::string> parts;
    boost::split(parts, raw, boost::is_any_of(":"));

    if ( parts.size() < 3 ) {
        throw std::runtime_error("unexpected color set");
    }
    name = parts[0];

    if ( parts.size() == 3) {
        color = parts[1];
        intensity = parts[2];
    }
    if ( parts.size() == 4 ) {
        rgbR = std::stoi(parts[1]);
        rgbG = std::stoi(parts[2]);
        rgbB = std::stoi(parts[3]);
    }
}

Region::Region(std::string name, unsigned int r, unsigned int g, unsigned int b)
        : name(std::move(name)), rgbR(r), rgbG(g), rgbB(b) {}

RGB Region::GetRGB() const {
    RGB result{};
    result.r = this->rgbR;
    result.g = this->rgbG;
    result.b = this->rgbB;

    return result;
}
