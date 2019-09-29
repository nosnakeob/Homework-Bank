#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    for (int i = 0; i < 1; i++)
    {
        cout << "hahhahaha" << endl;
    }

    int a = 45, b = 87;
    cout << (double)a / b << endl;

    int arr[] = {1, 2, 4, 5, 6, 3, 8};

    for (auto &&a : arr)
    {
        a = 6;
    }

    for (int i = 0; i < 7; i++)
    {
        cout << arr[i];
    }

    return 0;
}