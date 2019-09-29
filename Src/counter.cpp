#include "counter.hpp"
#include <iostream>
using namespace std;

Counter::Counter()
{
    queue_num = 0;
    queue_front = queue_back = nullptr;
}

Counter::~Counter()
{
}

void Counter::push(Client &client)
{
    if (isEmpty())
        queue_front = queue_back = client;
    else
    {
        queue_back->next = client;
        queue_back = client;
    }
    queue_num++;
}

bool Counter::pop()
{
    if (isEmpty())
        return 0;

    Client p = queue_front;
    if (queue_front == queue_back)
        queue_front = queue_back = nullptr;
    else
        queue_front = queue_front->next;
    delete p;
    queue_num--;
    return 1;
}

Client Counter::front()
{
    return queue_front;
}

Client Counter::back()
{
    return queue_back;
}

bool Counter::isEmpty()
{
    if (queue_back == nullptr)
        return 1;

    return 0;
}

int Counter::size()
{
    return queue_num;
}

void Counter::handling()
{
    queue_front->handling_time--;
    for (auto p = queue_front; p != nullptr; p = p->next)
        p->stay_time++;
}