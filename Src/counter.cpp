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
}

bool Counter::pop()
{
    if (isEmpty())
        return 0;

    Client p = queue_front->next;
    delete queue_front;
    queue_front = p;
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
    for (auto p = queue_front; p != nullptr; p = p->next)
    {
        p->handling_time--;
        p->stay_time++;
    }
}