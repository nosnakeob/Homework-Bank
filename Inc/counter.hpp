#ifndef _COUNTER_H_
#define _COUNTER_H_

typedef struct CNode //客户结点
{
    int handling_time, stay_time; //办理时间、逗留时间
    struct CNode *next;
} CNode, *Client;

class Counter //窗口
{
private:
    int queue_num;                  //排队人数
    Client queue_front, queue_back; //记录队首队尾

public:
    Counter();
    ~Counter();
    void push(Client &client); //入队
    bool pop();                //出队
    int size();                //取人数
    Client front();            //取首值
    Client back();             //取尾值
    bool isEmpty();            //判空
    void handling();           //客户处理时间-1、逗留时间+1
};

#endif