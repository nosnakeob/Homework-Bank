#ifndef B_H
#define B_H
#include "counter.hpp"

class Bank
{
private:
    Counter counter[4];
    int total_num, total_stay; //总人数、总逗留时间

    int random(int from, int to); //返回

public:
    Bank(); //初始化
    // void openForDay();
    ~Bank();
    void eventDrived();
    void closeForDay();
};

#endif