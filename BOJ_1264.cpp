#include <iostream>
#define endl "\n"
using namespace std;

int main(){
    string s;
    while(getline(cin,s)){
        if(s == "#"){
            break;
        }
        int answer = 0;
        for(int i = 0;i<s.size();i++){
            if(s[i] == 'a' or s[i] == 'o' or s[i] == 'u' or s[i] == 'i' or s[i] == 'e' or s[i] == 'A' or s[i] == 'E' or s[i] == 'I' or s[i] == 'O' or s[i] == 'U'){
                answer++;
            }
        }
        cout<<answer<<endl;
    }
    return 0;
}