#include "screen.hpp"
#include "bank.hpp"
#include <iostream>

using namespace std;

void Screen::startMenu()
{
    cout << "------------------------------------" << endl
         << "Banking Business MManagement System." << endl
         << RUN << ". Run the bank" << endl
         << SETTING << ". Setting."
         << EXIT << ". Exit" << endl
         << "------------------------------------" << endl
         << "Please choose an option:";
}

void Screen::option()
{
    while (1)
    {
        Choice choice;
        cin >> choice;
        switch (choice)
        {
        case INFO:
            infomation();
            break;

        case RUN:
            run();
            break;

        case EXIT:
            exit(1);

        default:
            cout << "Illegal input! Please try again." << endl;
        }
    }
}

void Screen::setting()
{
    cout << "There will be" << endl
         << COUNTER_NUM << " counter(s)" << endl
         << MIN_CLIENT << " ~ " << MAX_CLIENT << " client(s)" << endl
         << "They'll" << endl
         << "arrive at " << MIN_ENTER << " ~ " << MAX_ENTER << endl
         << "spend " << MIN_HANDLE << " ~ " << MAX_HANDLE << " handling" << endl;

    
}

void Screen::run()
{
    Bank bank;
    bank.eventDrived();

    bank.closeForDay();

    startMenu();
    option();
}
