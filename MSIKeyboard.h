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
    std::string GetMode();

private:
    std::map<std::string, Region> regions;
    std::string mode;
};


#endif //MSIKEYBOARD_CLI_MSIKEYBOARD_H
