#include<iostream>

using namespace std;

void binary_search(int n){

    int count = 0;

    while(n>0){
        int temp = n % 2;
        n /= 2;
        if(temp == 1){
            cout<<count<<" ";
        }
        count++;
    }
    cout<<endl;

    return;
}

int main(){
    int testcase;
    cin>>testcase;
    while(testcase--){
        int n;
        cin>>n;
        binary_search(n);
    }

    return 0;
}