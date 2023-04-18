#include <iostream>

using namespace std;

int main(){
    long long n,m;
    cin>>n>>m;
    long long answer = 0;
    answer = n * n - m * m;
    cout<<answer<<endl;
    return 0;
}