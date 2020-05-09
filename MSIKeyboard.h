#ifndef MSIKEYBOARD_CLI_MSIKEYBOARD_H
#define MSIKEYBOARD_CLI_MSIKEYBOARD_H

#include <map>
#include <string>
#include <hidapi/hidapi.h>
#include "Region.h"


class MSIKeyboard {
public:
    MSIKeyboard();
    ~MSIKeyboard();
    void SetRegion(Region region);
    void Send();
    void SetMode(string m);
    string GetMode();

private:
    map<string, Region> regions;
    string mode;
};


#endif //MSIKEYBOARD_CLI_MSIKEYBOARD_H
