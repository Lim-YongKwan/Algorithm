#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> candidate(n);
    for(int i = 0;i<n;i++){
        cin>>candidate[i];
    }
    int b,c;
    cin>>b>>c;

    long long answer = 0;
    answer += n;

    for(int i = 0;i<n;i++){
        candidate[i] -= b;
        if(candidate[i] % c == 0 and candidate[i] > 0){
            candidate[i] /= c;
            answer += candidate[i];
        }
        else if(candidate[i] > 0 and candidate[i] % c > 0){
            candidate[i] /= c;
            answer += candidate[i];
            answer++;
        }
    }
    cout<<answer<<endl;

    return 0;
}