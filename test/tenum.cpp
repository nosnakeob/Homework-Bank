#include <iostream>

using namespace std;

enum SS
{
    A,
    B,
    C
};

int main()
{
    SS s;

    cin >> (int &)s;

    cout << s;

    return 0;
}