#include <iostream>

using namespace std;

long long a, b, c, total;

long long tracking(int b)
{
    if (b == 0)
        return 1;
        
    total = tracking( b / 2 )%c;
    
    if(b%2 == 0){
        return total * total %c;
    }
    return total * total % c * a % c;

}

int main()
{

    cin >> a >> b >> c;
    cout<<tracking(b);

    return 0;
}