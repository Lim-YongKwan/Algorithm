#include<iostream>
#include<vector>
#define endl "\n"
using namespace std;

bool prime[50000001];

void eratos(){
    for(int i = 2;i*i<=50000001;i++){
        if(prime[i] == false){
            for(int j = i*i;j<=50000001;j+=i){
                prime[j] = true;
            }
        }
    }
}

int main(){
    eratos();
    int n;
    cin>>n;
    
    int answer = 0;
    for(int i = 2;i<=10000001;i++){
        if(prime[i] == false){
        answer++;
        }
        if(answer == n){
            cout<<i<<endl;
            break;
        }
    }
    return 0;
}