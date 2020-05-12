#include "MSIKeyboard.h"
#include <msikeyboard.h>
#include <utility>

MSIKeyboard::MSIKeyboard() {
    init_msi_keyboard();
};

void MSIKeyboard::SetRegion(Region region) {
    this->regions[region.Name()] = std::move(region);
}

void MSIKeyboard::Send() {
    for (auto it = this->regions.begin(); it != regions.end(); ++it) {
        Region region = it->second;
        int result = set_color_by_names(it->first.c_str(), region.Color().c_str(), region.Intensity().c_str());
        if ( result != 0 ) {
            throw std::runtime_error("set color by region name failed");
        }
    }
    if ( !this->mode.empty() ) {
        int result = set_mode_by_name(this->mode.c_str());
        if ( result != 0 ) {
            throw std::runtime_error("set mode failed");
        }
    }
}

void MSIKeyboard::SetMode(std::string m) {
    this->mode = std::move(m);
}

std::string MSIKeyboard::GetMode() {
    return this->mode;
}

MSIKeyboard::~MSIKeyboard() {
    free_msi_keyboard();
}
