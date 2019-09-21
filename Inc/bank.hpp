#ifndef B_H
#define B_H

typedef struct CNode //客户结点
{
    int  handling_time, stay_time; //办理时间、逗留时间
    struct CNode *next;
} CNode, *Client;

struct Counter //窗口结点
{
    int queue_num;     //排队人数
    Client next, rear; //记录队尾
};

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