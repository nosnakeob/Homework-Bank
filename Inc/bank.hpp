#ifndef B_H
#define B_H

typedef struct CNode
{
    int enter_time, cost_time, left_time;
    struct CNode *next;
} CNode, *Client;

struct Counter
{
    int num; //排队人数
    Client next,rear;//记录队尾
};

class Bank
{
private:
    Counter counter[4];

public:
    Bank();
    ~Bank();
    void openForDay();
    void eventDrived();
    void closeForDay();
};

#endif