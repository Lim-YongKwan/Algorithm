#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main(){
    string s;
    cin>>s;

    //1. ()가 들어가면 우선순위 최상위
    //2. */ 는 는  +- 보다 빠르다.
    //3. +- 는 최하위 순위.

    stack<char> four;

    for(int i = 0;i<s.size();i++){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            cout<<s[i];
        }
        else{
            if(s[i] == '('){
                four.push(s[i]);
            }
            else if(s[i] == '*' || s[i] == '/'){
                while(!four.empty() && (four.top() == '*' || four.top() == '/')){
                    cout<<four.top();
                    four.pop();
                }
                four.push(s[i]);
            }
            else if(s[i] == '+' || s[i] == '-'){
                while(!four.empty() && four.top() != '('){
                    cout<<four.top();
                    four.pop();
                }
                four.push(s[i]);
            }
            else if(s[i] == ')'){
                while(!four.empty() && four.top() != '('){
                    cout<<four.top();
                    four.pop();
                }
                four.pop();
            }
        }
    }
    while(four.size() > 0){
        cout<<four.top();
        four.pop();
    }


    return 0;
}