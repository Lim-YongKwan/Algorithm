#include <iostream>
#include <vector>

using namespace std;

vector<int> prime;
int arr[10000001];

void eratos(){
    arr[0] = 1;
    arr[1] = 1;

    for(int i = 2;i<=1000;i++){
        if(arr[i] == 0){
            for(int j = i * i;j<=1000001;j+=i){
                arr[j] = 1;
            }
        }
    }

    for(int i = 2;i<=1000000;i++){
        if(arr[i] == 0){
            prime.push_back(i);
        }
    }

    return;
}

void goldBach(int n){
    int answer = 0;
    for(int i = 0;i<prime.size();i++){
        if(prime[i] > n / 2){
            break;
        }
        if(arr[n - prime[i]] == 0 ){
            answer++;
        }
    }
    cout<<answer<<endl;
    return;
}

int main(){
    int n;
    cin>>n;
    eratos();
    for(int i = 0;i<n;i++){
        int a;
        cin>>a;
        goldBach(a);
    }
    return 0;
}