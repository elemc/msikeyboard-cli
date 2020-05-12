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
        int result;
        if ( region.Color().empty() ) {
            result = set_rgb_color_by_name(it->first.c_str(), region.GetRGB(), "high");
        } else {
            result = set_color_by_names(it->first.c_str(), region.Color().c_str(), region.Intensity().c_str());
        }

        if ( result != 0 ) {
            throw std::runtime_error("set color failed");
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

MSIKeyboard::~MSIKeyboard() {
    free_msi_keyboard();
}

std::string MSIKeyboard::GetModes() {
    size_t size;
    char **modes = get_modes(&size);
    return getList(modes, size);
}

std::string MSIKeyboard::GetRegions() {
    size_t size;
    char **regions = get_regions(&size);
    return getList(regions, size);
}

std::string MSIKeyboard::GetColors() {
    size_t size;
    char **colors = get_colors(&size);
    return getList(colors, size);
}

std::string MSIKeyboard::GetIntensities()  {
    size_t size;
    char **intensities = get_colors(&size);
    return getList(intensities, size);
}

std::string MSIKeyboard::getList(char **data, size_t size) {
    std::string result;
    for (int i = 0; i < size; i++) {
        if (i != 0) {
            result.append(", ");
        }
        result.append(data[i]);
    }
    return result;
}
