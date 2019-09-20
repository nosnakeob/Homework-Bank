#include "bank.hpp"
#include <ctime>
#include <iostream>
#include <random>

using namespace std;

Bank::Bank()
{
    for (int i = 0; i < 4; i++)
    {
        counter[i].num = 0;
        counter[i].next = counter[i].rear = nullptr;
    }
}

int random(int from, int to)
{
    default_random_engine e(time(0));
    u.param(uniform_int_distribution<>::param_type(from, to));

    return u(e);
}

void Bank::eventDrived()
{
    const int MAXTIME = 10 * 60 + 5;
    int total = random(1, 100);     //随机生成1~100个客户
    int enter_time[MAXTIME] = {0};  //用于桶排
    for (int i = 0; i < total; i++) //为每个客户生成进入时间0~600、放入桶内
        enter_time[random(0, 600)]++;

    int time = 0;
    while (time++ < MAXTIME)
    {
        // 处理队中客户
        for (auto s : counter)
        {
            if (s.next == nullptr) //空闲
                break;
            else if (s.next->left_time == 0) //办理完毕
            {
                Client p = s.next->next;
                delete s.next;
                s.next = p;
            }
            else
                s.next->left_time--;

            
        }

        if (enter_time[time]) //有客户这个时间点进来
        {
            Client come = new CNode; //bug:多客户
            come->enter_time = time;
            come->next = nullptr;

            //排在人数少的窗口
            int min_counter = 0;
            int min_num = counter[0].num;
            for (int i = 1; i < 4; i++)
            {
                if (counter[i].num < min_num)
                    min_counter = i;
            }
            // 尾插法
            counter[min_counter].rear->next = come;
            counter[min_counter].rear = come;

            u.param(uniform_int_distribution<>::param_type(1, 10));
            come->cost_time = come->left_time = random(1, 10); //生成办理时间1~10
        }

        //
    }
}