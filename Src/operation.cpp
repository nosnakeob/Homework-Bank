#include "bank.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <windows.h>

using namespace std;

Bank::Bank()
{
    MIN_HANDLE = 1;
    MAX_HANDLE = 3;
    MIN_ENTER = 0;
    MAX_ENTER = 10;
    PROBABILITY = 100;
    now = MIN_ENTER;
    total_num = total_stay = 0;
}

Bank::~Bank()
{
}

int Bank::random(int from, int to)
{
    srand((unsigned)time(0));
    return from + rand() % (to - from + 1);
}

void Bank::eventDrived()
{

    for (now = 0; now <= MAX_ENTER; now++) //时间流逝
    {
        bool isleave = 0, iscome = 0;

        // 处理在窗口等着的客户
        for (auto &&c : counter) //遍历窗口
        {
            if (c.isEmpty()) //空闲
                ;

            else if (c.front()->handling_time == 0) //办理完毕
            {
                c.pop(); //离开
                isleave = 1;
            }

            else //还在办理
            {
                c.handling();
            }
        }

        //处理刚进银行的新客户
        int handle = random(MIN_HANDLE, MAX_HANDLE);
        if (random(1, 100) <= PROBABILITY && handle < MAX_ENTER - now)
        {
            iscome = 1;
            Client come = new CNode;
            come->next = nullptr;
            come->handling_time = handle; //生成办理时间MIN_HANDLE~MAX_HANDLE
            //排在人数少的窗口
            int min_counter = 0;
            int min_num = counter[0].size();
            for (int i = 1; i < 4; i++)
            {
                if (counter[i].size() < min_num)
                {
                    min_counter = i;
                    min_num = counter[i].size();
                }
            }

            counter[min_counter].push(come); // 排队
        }

        system("cls");
        countersStatus();
        if (iscome)
            cout << "A client is comming" << endl;
        if (isleave)
            cout << "A client is leaving" << endl;
        frontStatus();
        Sleep(700);
    }
}

void Bank::closeForDay()
{
    cout << "Today's average of the stay time:" << total_stay / total_num << endl;
}

/* void Bank::clear()
{
    Bank();
}
 */