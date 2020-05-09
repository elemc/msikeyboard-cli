#include <iostream>
#include "MSIKeyboard.h"

int main() {
    MSIKeyboard keyboard;
    keyboard.SetMode("gaming");
    keyboard.SetRegion(Region("left", "red", "high"));
    keyboard.SetRegion(Region("middle", "orange", "high"));
    keyboard.SetRegion(Region("right", "purple", "high"));
    keyboard.Send();

    return 0;
}
