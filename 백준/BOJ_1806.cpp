#include<iostream>
#include<vector>
#include<algorithm>
#define endl "\n"

using namespace std;

int subtotal[100001];

int main(){
    int n;
    int s;
    cin>>n>>s;
    for(int i = 0;i<n;i++){
        cin>> subtotal[i];
       }

    int start=0;
    int end= 0;
    int total = subtotal[start];
    int count = 123456789;

    //투포인터
    //start하고 end를 비교
    //만일 start하 end혹은 n 이하일때 계속 돌아가게 만들기.
    //total은 계속해서 subtotal를 더하게 만들기.
    while(start<=end and end<=n){

        if(total>=s){
            //만일 total이 s보다 클때
            //count의 가장 짧은 구간 길이 구하기.
            //구간길이 최솟값 갱신하기.
            cout<<"total : "<<total<<" "<<"start : "<<start<<" end : "<<end<<endl;
            count = min(count,end-start+1);
            total -= subtotal[start];
            start++;
        }
        else{
            //만일 total이 s보다 짧을때
            //end 하나씩 늘리기.
            end++;
            total += subtotal[end];
        }
    }
    if(count == 123456789){
        cout<<0<<endl;
    }
    else{
        cout<<count<<endl;
    }

    return 0;
}