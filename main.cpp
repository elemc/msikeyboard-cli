#include "MSIKeyboard.h"

using namespace std;

int main() {
    MSIKeyboard keyboard;
    keyboard.SetMode("gaming");
    keyboard.SetRegion(Region("left", "white", "high"));
    keyboard.SetRegion(Region("middle", "purple", "high"));
    keyboard.SetRegion(Region("right", "red", "high"));
    keyboard.Send();

    return 0;
}
