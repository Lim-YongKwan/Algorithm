#include <iostream>
#include <map>
#define endl "\n"

using namespace std;

map<char,int> telephone;

bool isPalindrome(string s){
    bool answer = true;
    for(int i = 0;i<s.size() / 2; i++){
        if(telephone[s[i]] != telephone[s[s.size() - 1 - i]]){
            answer = false;
        }
    }
    return answer;
}

int main(){
    telephone['A'] = 2;
    telephone['a'] = 2;
    telephone['B'] = 2;
    telephone['b'] = 2;
    telephone['C'] = 2;
    telephone['c'] = 2;
    telephone['D'] = 3;
    telephone['d'] = 3;
    telephone['E'] = 3;
    telephone['e'] = 3;
    telephone['F'] = 3;
    telephone['f'] = 3;
    telephone['G'] = 4;
    telephone['g'] = 4;
    telephone['H'] = 4;
    telephone['h'] = 4;
    telephone['I'] = 4;
    telephone['i'] = 4;
    telephone['J'] = 5;
    telephone['j'] = 5;
    telephone['K'] = 5;
    telephone['k'] = 5;
    telephone['L'] = 5;
    telephone['l'] = 5;
    telephone['M'] = 6;
    telephone['m'] = 6;
    telephone['N'] = 6;
    telephone['n'] = 6;
    telephone['O'] = 6;
    telephone['o'] = 6;
    telephone['P'] = 7;
    telephone['p'] = 7;
    telephone['Q'] = 7;
    telephone['q'] = 7;
    telephone['R'] = 7;
    telephone['r'] = 7;
    telephone['S'] = 7;
    telephone['s'] = 7;
    telephone['T'] = 8;
    telephone['t'] = 8;
    telephone['U'] = 8;
    telephone['u'] = 8;
    telephone['V'] = 8;
    telephone['v'] = 8;
    telephone['W'] = 9;
    telephone['w'] = 9;
    telephone['X'] = 9;
    telephone['x'] = 9;
    telephone['Y'] = 9;
    telephone['y'] = 9;
    telephone['Z'] = 9;
    telephone['z'] = 9;


    int n;
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        bool answer;
        answer = isPalindrome(s);
        cout<<(answer ? "YES" : "NO")<<endl;
    }
    return 0;
}