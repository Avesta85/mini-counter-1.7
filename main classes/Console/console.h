#pragma once
#include <iostream>
#include <map>

class Console {
public:
    enum class Color {
        BLACK = 0, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE,
        BRIGHT_BLACK = 60, BRIGHT_RED, BRIGHT_GREEN, BRIGHT_YELLOW,
        BRIGHT_BLUE, BRIGHT_MAGENTA, BRIGHT_CYAN, BRIGHT_WHITE
    };

    static void printColored(const std::string& text, Color textColor);

    static void waiter();
};

