#include<iostream>
#include<string>
#define endl "\n"

using namespace std;

void solve(string s1,string s2){

    while(s1.length() != s2.length()){
        if(s1.length() < s2.length()){
            s1 = '0' + s1;
        }
        else if(s1.length() > s2.length()){
            s2 = '0' + s2;
        }
    }
    
    string s3 = "";

    for(int i = 0;i<s1.length();i++){
        s3 = '0' + s3;
    }
    
    for(int i = s1.length()-1;i>=1;i--){

        if(s1[i]-'0' + s2[i]-'0' >= 10){
            s1[i-1] = s1[i-1] + 1;
            s3[i] += (s1[i] + s2[i] -'0' - '0')%10;
        }
        else {
            s3[i] += (s1[i] + s2[i] - '0' - '0');
        }
    }

    if(s1[0] + s2[0]-'0'-'0'>=10){
        s3[0] += (s1[0] + s2[0] -'0' - '0') % 10;
        s3 = '1' + s3;
    }
    else{
        s3[0] += s1[0] + s2[0] -'0' - '0';
    }
    
    cout<<s3<<endl;

    return;
}

int main(){
    string s1,s2;
    cin>>s1>>s2;
    solve(s1,s2);

    return 0;
}