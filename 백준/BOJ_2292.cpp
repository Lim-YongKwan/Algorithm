#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    long long arr = 2;

    int answer = 0;
    for(int i = 1;arr<=n;i++){
        arr += (6 * i);
        if(arr > n){
            answer = i;
            break;
        }
    }

    if(n == 1){
        answer = 0;
    }

    cout<<answer + 1<<endl;

    return 0;
}