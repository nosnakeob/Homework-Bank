#ifndef C_H
#define C_H

typedef struct CNode //客户结点
{
    int handling_time, stay_time; //办理时间、逗留时间
    struct CNode *next;
} CNode, *Client;

class Counter //窗口
{
private:
    int queue_num;                  //排队人数
    Client queue_front, queue_rear; //记录队首队尾

public:
    Counter();
    ~Counter();
    void push(Client &client); //入队
    bool pop();                //出队
    int howMany();             //取人数
    Client front();            //取首值
    Client rear();             //取尾值
    bool isEmpty();            //判空
};

#endif