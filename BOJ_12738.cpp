#include<iostream>
#include<vector>
#include<algorithm>
#define endl "\n"

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> sequence;
    for(int i = 0;i<n;i++){
        int temp;
        cin>>temp;
        if(sequence.size() == 0 or sequence.back()<temp){
            sequence.push_back(temp);
        }
        else{
            *lower_bound(sequence.begin(),sequence.end(),temp) = temp;
        }
    }
    cout<<sequence.size()<<endl;
    return 0;
}