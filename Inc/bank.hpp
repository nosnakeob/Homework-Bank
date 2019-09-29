#ifndef _BANK_H_
#define _BANK_H_
#include "counter.hpp"

class Bank
{
private:
    int MAX_HANDLE, MIN_HANDLE, MIN_ENTER, MAX_ENTER, PROBABILITY;
    int now;

    Counter counter[4];
    double total_num, total_stay; //总人数、总逗留时间
    int random(int from, int to); //返回

    enum Choice
    {
        RUN = 1,
        SETTING,
        EXIT
    };

public:
    Bank(); //初始化
    // void openForDay();
    ~Bank();

    //操作
    void eventDrived(); //开门
    void closeForDay(); //关门
    // void clear();       //清场

    //显示
    void startMenu();      //开始界面
    void option();         //选项栏
    void setting();        //修改参数
    void run();            //运行过程
    void countersStatus(); //输出某一时刻窗口状态
    void frontStatus();    //输出某一时刻办理状态
};

#endif