#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int solve(string str){
    int answer = 0;
    int max_B = 0;
    int count_R = 0;
    int max_R = 0 ;
    int count_B = 0;

    //B 판별
    for(int i = str.size() - 1;i >= 0;i--){
        if(str[i] == 'B'){
            count_B = 1;
            max_B += count_R;
        }
        else if(str[i] == 'R'){
            count_R = 1;
            max_R += count_B;
        }
    }
    answer = min(max_B, max_R);
    max_B = 0;
    max_R = 0;
    count_B = 0;
    count_R = 0;

    for(int i = 0;i < str.size();i++){
        if(str[i] == 'B'){
            count_B = 1;
            max_B += count_R;
        }
        else if(str[i] == 'R'){
            count_R = 1;
            max_R += count_B;
        }
    }
    answer = min(answer,max_B);
    answer = min(answer,max_R);
    return answer;
}


int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    cout<<solve(s)<<endl;

    return 0;
}