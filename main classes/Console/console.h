#pragma once
#include <iostream>
#include <map>
#include <limits>
#include <sstream>
#include "../CT_class/CT_Class.h"
#include "../TerroristClass/TerroristClass.h"

class Console {
public:
    enum class Color {
        BLACK = 0, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE,
        BRIGHT_BLACK = 60, BRIGHT_RED, BRIGHT_GREEN, BRIGHT_YELLOW,
        BRIGHT_BLUE, BRIGHT_MAGENTA, BRIGHT_CYAN, BRIGHT_WHITE
    };

    static void printColored(const std::string& text, Color textColor);

    static void waiter();

    static void ClearBuffer();

    static void ClearLine();

    static void Player_To_Player(std::string& p1, std::string& p2,bool Ct1,bool ct2,bool kill,bool both);
};

