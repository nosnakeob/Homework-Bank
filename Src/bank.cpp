#include "bank.hpp"
#include <ctime>
#include <iostream>
#include <random>

using namespace std;

Bank::Bank()
{
    total_num = total_stay = 0;
    for (int i = 0; i < 4; i++)
    {
        counter[i].queue_num = 0;
        counter[i].next = counter[i].rear = nullptr;
    }
}

Bank::~Bank()
{
}

int Bank::random(int from, int to)
{
    uniform_int_distribution<unsigned> u(from, to);
    default_random_engine e(time(0));

    return u(e);
}

void Bank::eventDrived()
{
    // const int MAXTIME = 10 * 60 + 5;
    total_num = random(1, 100);         //随机生成1~100个客户
    int enter_times[605] = {0};         //用于桶排
    for (int i = 0; i < total_num; i++) //为每个客户生成进入时间0~600、放入桶内
        enter_times[random(0, 600)]++;

    int time = 0;
    while (time++ < 600) //时间流逝
    {
        // 处理在窗口等着的客户
        for (auto c : counter) //遍历4个窗口
        {
            if (c.next == nullptr) //空闲
                break;

            else if (c.next->handling_time == 0) //办理完毕
            {
                total_stay += c.next->stay_time; //把逗留时间算入总逗留时间

                //离开、删除结点
                Client p = c.next->next;
                delete c.next;
                c.next = p;

                c.queue_num--; //窗口排队人数减少
            }
            else //还在办理
                c.next->handling_time--;

            for (auto p = c.next; p; p = p->next) //所有客户逗留时间++
                p->stay_time++;
        }

        //处理刚进银行的新客户
        for (int i = 0; i < enter_times[time]; i++) //有客户这个时间点进来
        {
            Client come = new CNode;
            come->handling_time = random(1, 10); //生成办理时间1~10
            come->next = nullptr;

            //排在人数少的窗口
            int min_counter = 0;
            int min_num = counter[0].queue_num;
            for (int i = 1; i < 4; i++)
            {
                if (counter[i].queue_num < min_num)
                    min_counter = i;
            }

            // 排队、尾插法
            counter[min_counter].rear->next = come;
            counter[min_counter].rear = come;
        }
    }
}

void Bank::closeForDay()
{
    
}
