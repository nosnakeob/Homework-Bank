#include "bank.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

Bank::Bank()
{
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

void Bank::changeEnter(int open, int close)
{
    MIN_ENTER = open;
    MAX_ENTER = close;
}

void Bank::changeHandel(int min, int max)
{
    MIN_HANDLE = min;
    MAX_HANDLE = max;
}

void Bank::eventDrived()
{
    int time = MIN_ENTER;
    do
    {
        // 处理在窗口等着的客户
        for (auto c : counter) //遍历窗口
        {
            if (c.isEmpty()) //空闲
                ;

            else if (c.front().handling_time == 0) //办理完毕
                c.pop();                           //离开

            else //还在办理
            {
                c.handling();
            }
        }

        //处理刚进银行的新客户
        if (random(1, 10) <= 3)
        {
            cout << "A client is comming" << endl;
            Client come;
            come.handling_time = random(MIN_HANDLE, MAX_HANDLE); //生成办理时间MIN_HANDLE~MAX_HANDLE
            cout << come.handling_time << endl;
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

            // 排队
            counter[min_counter].push(come);
        }
    } while (++time < MAX_ENTER); //时间流逝
}

void Bank::closeForDay()
{
    cout << "Today's average of the stay time:" << total_stay / total_num << endl;
}
