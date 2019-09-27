#include "counter.hpp"
#include <iostream>
using namespace std;

Counter::Counter()
{
    queue_num = 0;
    queue_front = queue_rear = nullptr;
}

Counter::~Counter()
{
}

void Counter::push(Client &client)
{
    if (isEmpty())
        queue_front = queue_rear = client;
    else
    {
        queue_rear->next = client;
        queue_rear = client;
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

Client Counter::rear()
{
    return queue_rear;
}

bool Counter::isEmpty()
{
    if (queue_rear == nullptr)
        return 1;

    return 0;
}

int Counter::howMany()
{
    return queue_num;
}