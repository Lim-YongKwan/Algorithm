#include <iostream>

using namespace std;

long long answer;
long long total;

long long fibonachi(long long n){

    if(n == 1){
        return 1;
    }
    else if(n == 2){
        return 1;
    }
    else if(n == 0){
        return 0;
    }
    else if(n == 3){
        return 2;
    }
    else if(n == 4){
        return 3;
    }
    else if(n == 5){
        return 5;
    }

    return ((fibonachi(n - 5) * 3) % 1000000007) + ((fibonachi(n - 4) * 5) % 1000000007);
}

int main(){
    long long n;
    cin>>n;

    answer = fibonachi(n);
    cout<<answer<<endl;    

    return 0;
}