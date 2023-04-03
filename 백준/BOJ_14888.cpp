#include<iostream>
#include<vector>
#include<algorithm>
#define endl "\n"

using namespace std;

int t;
int Max = -1000000000;
int Min = 1000000000;
int mathmetical[12];
vector<string> answer;
vector<string> arithmetic;
bool visit[102];

void backtracking(int n){
    if(n == t-1){
        int total = mathmetical[0];
        for(int i = 0;i<t-1;i++){
            if(answer[i] == "plus"){
                total += mathmetical[i+1];
            }
            else if(answer[i] == "minus"){
                total -= mathmetical[i+1];
            }
            else if(answer[i] == "multiple"){
                total *= mathmetical[i+1];
            }
            else{
                total /= mathmetical[i+1];
            }
        }
        if(total<Min){
            Min = min(Min,total);
        }
        if(total>Max){
            Max = max(Max,total);
        }
        return;
    }

    for(int i = 0;i<arithmetic.size();i++){
        if(visit[i] == true){
            continue;
        }
        visit[i] = true;
        answer.push_back(arithmetic[i]);
        backtracking(n+1);
        answer.pop_back();
        visit[i] = false;
    }
}

int main(){
    cin>>t;
    for(int i = 0;i<t;i++){
        cin>>mathmetical[i];
    }
    for(int i = 0;i<4;i++){
        int temp;
        cin>>temp;
        for(int j = 0;j<temp;j++){
            if(i == 0){
                arithmetic.push_back("plus");
            }
            else if(i == 1){
                arithmetic.push_back("minus");
            }
            else if(i == 2){
                arithmetic.push_back("multiple");
            }
            else if(i == 3){
                arithmetic.push_back("divide");
            }
        }
    }

    backtracking(0);
    cout<<Max<<endl;
    cout<<Min<<endl;
    return 0;
}