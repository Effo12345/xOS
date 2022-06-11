#pragma once

#include <string>
#include <map>

//selector configuration
#define HUE 360
#define DEFAULT 1
#define AUTONS "Front", "Back", "Test", "Tmp", "Do Nothing"


namespace selector{
    enum Color {red, blue};
    extern Color color;


    extern int autonIndex;
    const char *b[] = {AUTONS, ""};
    void init(int hue = HUE, int default_auton = DEFAULT, const char **autons = b);
    void (*getSelection()) ();

}
