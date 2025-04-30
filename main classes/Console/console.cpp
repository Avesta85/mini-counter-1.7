#include "console.h"


void Console::printColored(const std::string& text, Color textColor) {
    std::cout << "\033[" << static_cast<int>(30 + static_cast<int>(textColor)) << "m"
        << text << "\033[0m";
}




void Console::waiter() {
    printColored("\nDo you want to come back?(y,n) : ", Color::RED);
    char tmp;

    do {

        while (!(std::cin >> tmp)) {
            Console::ClearBuffer();
            Console::printColored("WRONGE INPUT\n", Console::Color::BRIGHT_RED);

            Console::ClearLine();
            Console::ClearLine();
            Console::ClearLine();
            printColored("\nDo you want to come back?(y,n) : ", Color::RED);
        }

        if (tmp == 'y') break;
        else {
            Console::ClearBuffer();
            Console::printColored("WRONGE INPUT\n", Console::Color::BRIGHT_RED);

            Console::ClearLine();
            Console::ClearLine();
            Console::ClearLine();
            printColored("\nDo you want to come back?(y,n) : ", Color::RED);
        }
    } while (true);
}

void Console::ClearBuffer()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Console::ClearLine()
{
    std::cout << "\033[A"<< "\033[2K"<< "\r";

}

void Console::Player_To_Player(std::string& p1, std::string& p2, bool ct1, bool ct2, bool kill, bool both)
{
    std::stringstream p1_tag;
    std::stringstream p2_tag;
    std::stringstream final;
   
    if (ct1) {
        p1_tag << "CT_player :" << CT::get_from_map(p1)->get_name();
    }
    else {
        p1_tag << "Terrorist_Player :" << Terrorist::get_from_map(p1)->get_name();
    }

    if (ct2) {
        p2_tag << "CT_player :" << CT::get_from_map(p2)->get_name();
    }
    else {
        p2_tag << "Terrorist_Player :" << Terrorist::get_from_map(p2)->get_name();
    }

    if (!both) {
        final << p1_tag.str() << ((kill) ? (" defeated ") : (" damaged ")) << p2_tag.str() << "\n";

        if (ct1) {
            printColored(final.str(), Color::BRIGHT_BLUE);
        }
        else {
            printColored(final.str(), Color::BRIGHT_RED);
        }
    }
    else {
        bool player1_kill;
        bool player2_kill;
        if(ct1){
            player1_kill = !CT::get_from_map(p1)->is_Alive();
        }
        else {
            player1_kill = !Terrorist::get_from_map(p1)->is_Alive();

        }
        if (ct2) {
            player2_kill = !CT::get_from_map(p2)->is_Alive();
        }
        else {
            player2_kill = !Terrorist::get_from_map(p2)->is_Alive();

        }

        if (player1_kill) {
            final << p1_tag.str() << " defeated and ";
       }
        else {
            final << p1_tag.str() << " damaged and ";

        }
        if (player2_kill) {
            final << p2_tag.str() << " defeated \n";
        }
        else {
            final << p2_tag.str() << " damaged \n";

        }
        printColored(final.str(), Color::BRIGHT_YELLOW);
    }
}
