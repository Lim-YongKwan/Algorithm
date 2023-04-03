#include<iostream>
#include<vector>
#include<string>
#define endl "\n"

using namespace std;

bool prime[10000000];

void eratos(){
    prime[0] = 1;
    prime[1] = 1;
    for(int i = 2;i*i<=10000000;i++){
        if(prime[i] == false){
            for(int j = i*i;j<=10000000;j+=i){
                prime[j] = true;
            }
        }
    }
    return;
}

bool discrim(int n, int c){
    string temp = "";
    temp = to_string(n);
    string answer = "";
    answer = to_string(c);

    if(temp.find(answer) != string::npos){
        // cout<<temp<<" "<<answer<<endl;
        return true;
    }

    return false;
}

int main(){
    int a,b,c;
    cin>>a>>b>>c;
    eratos();
    int answer = 0;
    for(int i = a;i<=b;i++){
        if(prime[i] == false){
            
            if(discrim(i,c) == true){
                answer++;
            }
        }
    }
    cout<<answer<<endl;
    return 0;
}