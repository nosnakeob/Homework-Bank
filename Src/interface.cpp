#include "bank.hpp"
#include <iostream>
#include <windows.h>

using namespace std;

void Bank::startMenu()
{
    cout << "---------------------------------------------------------------------" << endl
         << "                          Welcome to the bank" << endl
         << "Clients will " << PROBABILITY << "% arrive at " << MIN_ENTER << "~" << MAX_ENTER << " mins and spend " << MIN_HANDLE << "~" << MAX_HANDLE << " mins handling" << endl
         << endl
         << RUN << ". Run the bank" << endl
         << SETTING << ". Setting" << endl
         << EXIT << ". Exit" << endl
         << "---------------------------------------------------------------------" << endl
         << "Please choose an option:";
}

void Bank::option()
{
    Choice choice;
    cin >> (int &)choice;
    switch (choice)
    {
    case RUN:
        run();
        break;

    case SETTING:
        setting();

        cout << endl
             << "Done!" << endl;
        break;

    case EXIT:
        cout << endl
             << "See you next time!!!" << endl;
        Sleep(1000);
        exit(1);

    default:
        cout << "Illegal input! Please try again." << endl;
    }
}

void Bank::setting()
{
    cout << "Please enter the range of open time:";
    cin >> MIN_ENTER >> MAX_ENTER;
    cout << "Please enter the range of processing time:";
    cin >> MIN_HANDLE >> MAX_HANDLE;
    cout << "Please enter the probability of clients' presence(0~100%):";
    cin >> PROBABILITY;
}

void Bank::run()
{
    eventDrived();

    closeForDay();

    Bank();
}

void Bank::countersStatus()
{
    cout << "Time:" << now << endl
         << endl;

    for (int i = 0; i < 4; i++)
    {
        cout << "Counter " << i + 1 << ":";

        cout << (counter[i].isEmpty() ? " " : "O");

        for (int j = 0; j < counter[i].size() - 1; j++)
            cout << " <- O";
        cout << endl;
    }
}

void Bank::frontStatus()
{
    for (int i = 0; i < 4; i++)
    {
        if (!counter[i].isEmpty())
            cout << "Counter " << i + 1 << " is handling:" << counter[i].front()->handling_time << endl;
    }
}
