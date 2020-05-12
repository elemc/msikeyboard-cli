#ifndef MSIKEYBOARD_CLI_MSIKEYBOARD_H
#define MSIKEYBOARD_CLI_MSIKEYBOARD_H

#include <map>
#include <string>
#include "Region.h"


class MSIKeyboard {
public:
    MSIKeyboard();
    ~MSIKeyboard();
    void SetRegion(Region region);
    void Send();
    void SetMode(std::string m);

    static std::string GetModes();
    static std::string GetRegions();
    static std::string GetColors();
    static std::string GetIntensities();

private:
    std::map<std::string, Region> regions;
    std::string mode;

    static std::string getList(char **data, size_t size);
};


#endif //MSIKEYBOARD_CLI_MSIKEYBOARD_H
