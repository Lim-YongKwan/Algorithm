#include<iostream>
#include <algorithm>

using namespace std;

long long array_sum(long long mid, int n){
    long long answer = 0;

    for(int i = 1;i<=n;i++){
        if(n < (mid / i)){
            answer += n;
        }
        else{
            answer += (mid / i);
        }
        if(i > mid){
            break;
        }
    }
    return answer;
}

int main(){
    long long n,k;
    cin>>n>>k;

    long long low = 1;
    long long high = n*n;
    long long mid = 0;
    long long answer = 0;
    while(low <= high){
        mid = (low + high) / 2;
        if(array_sum(mid,n) < k){
            low = mid + 1;
        }
        else{
            answer = mid;
            high = mid - 1;
        }
    }
    cout<<answer<<endl;

    return 0;
}