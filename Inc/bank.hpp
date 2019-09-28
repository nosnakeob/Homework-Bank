#ifndef _BANK_H_
#define _BANK_H_
#include "counter.hpp"

class Bank
{
private:
    int MAX_HANDLE = 1, MIN_HANDLE = 1, MIN_ENTER = 0, MAX_ENTER = 600;

    Counter counter[4];
    double total_num, total_stay; //总人数、总逗留时间
    int random(int from, int to); //返回

public:
    Bank(); //初始化
    // void openForDay();
    ~Bank();
    void eventDrived();                    //开门
    void closeForDay();                    //关门
    void circumstance();                   //输出某一时刻状态
    void changeEnter(int open, int close); //改开、关门时间
    void changeHandel(int min, int max);   //改办理时间
};

#endif