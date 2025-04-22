#include "console.h"


void Console::printColored(const std::string& text, Color textColor) {
    std::cout << "\033[" << static_cast<int>(30 + static_cast<int>(textColor)) << "m"
        << text << "\033[0m";
}




void Console::waiter() {
    printColored("Do you want to come back?(y,n) : ", Color::RED);
    while (1) {
        char tmp;
        std::cin >> tmp;
        if (tmp == 'y') {
            break;
        }
    }
}
