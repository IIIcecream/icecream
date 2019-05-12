#include <iostream>
using namespace std;

int main()
{
    int n = 4 & 3;
    cout << (4 & 3) << endl;
    cout << n << endl;
    cout << ((4 & 3) == 0) << endl;
    cout << (n == 0) << endl;
    return 0;
}