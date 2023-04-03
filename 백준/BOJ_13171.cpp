#include <iostream>
#define endl "\n"
#define mod 1000000007
using namespace std;

long long pow(long long a, long long x)
{
    if (x == 0)
    {
        return 1;
    }
    else
    {
        long long n = pow(a, x / 2);
        long long temp = n * n % mod;
        if (x % 2 == 0)
        {
            return temp;
        }
        else
        {
            return temp * a % mod;
        }
    }
}

int main()
{
    long long a;
    long long x;
    cin >> a >> x;
    cout << pow(a % mod, x) << endl;

    return 0;
}