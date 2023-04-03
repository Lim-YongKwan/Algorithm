#include <iostream>

using namespace std;

bool solve(int n){
    if(n % 2 == 0){
        return 1;
    }
    return 0;
}

int main(){
    int n;
    cin>>n;
    (solve(n) > 0) ? cout<< "CY" : cout<< "SK";
    return 0;
}