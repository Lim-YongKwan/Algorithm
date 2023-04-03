#include<iostream>
#include<string>
#define endl "\n"

using namespace std;

string combi[101][101];

string addNum(string s1, string s2){
    string result = "";
    if(s1.length()>s2.length()){
        while(s1.length() != s2.length()){
            s2 = '0' + s2;
        }
    }
    else{
        while(s1.length() != s2.length()){
            s1 = '0' + s1;
        }
    }

    int sum = 0;

    for(int i = s1.length() - 1; i>= 0; i--){
        sum += s1[i] - '0';
        sum += s2[i] -'0';

        result = to_string(sum % 10) + result;

        if(sum>= 10 ){
            sum = 1;
        }
        else{
            sum = 0;
        }
    }
    if(sum == 1){
        return '1'+ result;
    }
    return result;
}

void combination(int n,int m){
    combi[0][0] = "1";
    combi[1][1] = combi[1][0] =  "1";
    for(int i = 2;i<=n;i++){
        for(int j = 0;j<=m;j++){
            if(i == j or j== 0 ){
                combi[i][j] = "1";
            }
            else {
                combi[i][j] = addNum(combi[i-1][j-1],combi[i-1][j]);
            }
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    combination(n,m);
    cout<<combi[n][m]<<endl;
    return 0;
}