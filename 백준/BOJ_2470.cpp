#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solution(vector<int> liquid){
    pair<int, int> answer;
    int total = 2000000000;
    int start = 0;
    int end = liquid.size() - 1;

    while(start < end){

        if(abs(liquid[start] + liquid[end]) < total){
            total = abs(liquid[start] + liquid[end]);
            answer.first = liquid[start];
            answer.second = liquid[end];
        }

        if((liquid[start] + liquid[end]) > 0){
            end--;
        }
        else if((liquid[start] + liquid[end]) < 0){
            start++;
        }
        else{
            break;
        }
    }
    cout<<answer.first<<" "<<answer.second<<endl;

    return;
}

int main(){
    int n;
    cin>>n;
    vector<int> liquid(n,0);
    for(int i = 0;i<n;i++){
        cin>>liquid[i];
    }
    sort(liquid.begin(),liquid.end());

    solution(liquid);   

    return 0;
}