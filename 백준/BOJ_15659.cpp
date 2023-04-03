#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#define endl "\n"

using namespace std;

int t;
int Max = -1000000000;
int Min = 1000000000;
int mathmetical[12];
int arithmetic[4];
vector<char> answer;

void backtracking(int n){
    if(n == t-1){
        int total = 0;
        vector<int> pro_1;

        pro_1.push_back(mathmetical[0]);
        cout<<pro_1[pro_1.size()-1]<<" ";
        // cout<<mathmetical[0]<<" ";

        for(int i =0;i<t-1;i++){
            cout<<answer[i]<<" ";
            if(answer[i] == 'x'){
                pro_1[pro_1.size()-1] *= mathmetical[i+1];
            }
            else if(answer[i] == '%'){
                pro_1[pro_1.size()-1] /= mathmetical[i+1];
            }
            else{
                pro_1.push_back(mathmetical[i+1]);
            }
            cout<<pro_1[pro_1.size()-1]<<" ";
            // pro_1.push_back(mathmetical[i+1]);
        }

        int result = pro_1[0];

        for(int i = 0;i<t;i++){
            if(answer[i] == '+'){
                result += pro_1[i+1];
            }
            else if(answer[i] == '-'){
                result -= pro_1[i+1];
            }
            else{
                result += pro_1[i+1];
            }
            i++;
        }

        total = result;
        cout<<" = : "<<total<<endl;
        Min = min(Min,total);
        Max = max(Max,total);
        return;
    }

    for(int i = 0;i<4;i++){
        if(arithmetic[i] == 0){
            continue;
        }
        
        if(i == 0){
            answer.push_back('+');
        }
        else if(i == 1){
            answer.push_back('-');
        }
        else if(i == 2){
            answer.push_back('x');
        }
        else{
            answer.push_back('%');
        }

        arithmetic[i]--;
        backtracking(n+1);
        arithmetic[i]++;
        answer.pop_back();
    }

    return;
}

int main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>t;
    for(int i = 0;i<t;i++){
        cin>>mathmetical[i];
    }

    for(int i = 0;i<4;i++){
        cin>>arithmetic[i];
    }

    backtracking(0);
    cout<<Max<<endl;
    cout<<Min<<endl;
    return 0;
}