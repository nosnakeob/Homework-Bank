#include <ctime>
#include <iostream>
#include <random>
using namespace std;

int main()
{
    int from, to;

    while (cin >> from >> to)
    {
        uniform_int_distribution<unsigned> u(from, to);
        default_random_engine e(time(0));

        cout << u(e);
    }
1
    return 0;
}