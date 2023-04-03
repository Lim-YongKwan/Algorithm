#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> stone(n,0);
    for(int i = 0;i<n;i++){
        cin>>stone[i];
    }
    stack<int> halbang;
    int answer = 0;

    for(int i = 0;i<n;i++){
        if(stone[i] == 1){
            halbang.push(1);
        }
        else if(stone[i] == 2){
            if(halbang.size() > 0){
                if(halbang.top() == 1){
                    halbang.pop();
                }
            }
        }
        int temp = halbang.size();
        answer = max(answer, temp);
    }

    while(!halbang.empty()){
        halbang.pop();
    }

    for(int i = 0;i<n;i++){
        if(stone[i] == 2){
            halbang.push(2);
        }
        else if(stone[i] == 1){
            if(halbang.size() > 0){
                if(halbang.top() == 2){
                    halbang.pop();
                }
            }
        }
        int temp = halbang.size();
        answer = max(answer, temp);
    }

    cout<<answer<<endl;
    return 0;
}