#include "bank.hpp"
#include <cstdlib>
#include <iostream>
#include <windows.h>

using namespace std;

int main(int argc, char *argv[])
{
    SetConsoleTitle("Banking Business Management System");
    Bank bank;

    while (1)
    {

        system("cls");

        bank.startMenu();
        bank.option();

        Sleep(1000);
    }

    return 0;
}