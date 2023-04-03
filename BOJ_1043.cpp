#include<iostream>
#include <vector>
#include <string>
#include <istream>
#include <sstream>
#include <algorithm>

using namespace std;

int parent[51];
bool visited[51];

int findUnion(int x){
    if(parent[x] == x){
        return x;
    }
    return parent[x] = findUnion(parent[x]);
}

void mergeUnion(int a,int b){
    a = findUnion(a);
    b = findUnion(b);
    if(a == b){
        return;
    }
    parent[b] = a;
    return;
}

bool isUnion(int a, int b){
    a = findUnion(a);
    b = findUnion(b);
    if(a == b){
        return true;
    }
    return false;
}

int main(){

    for(int i = 0;i<51;i++){
        parent[i] = i;
    }

    int answer = 0;
    //n은 사람의 수, m은 파티의 수   
    int n, m;
    cin>>n>>m;

    //진실을 아는 사람 숫자.
    int truth;
    cin>>truth;
    //진실을 아는 사람을 넣을 벡터.
    vector<int> countTruth;

    //만일 1명 이상이 알고 있다면
    if(truth > 0 ){
        int a;
        cin>>a;
        countTruth.push_back(a);
        for(int i = 0;i<truth - 1;i++){
            int temp;
            cin>>temp;
            mergeUnion(a,temp);
            countTruth.push_back(temp);
        }
    }


    vector<vector<int> > party;

    for(int i = 0;i<m;i++){
        int temp;
        cin>>temp;
        vector<int> people;
        int a;
        cin>>a;
        people.push_back(a);
        for(int j = 0;j<temp - 1;j++){
            int b;
            cin>>b;
            mergeUnion(a,b);
            people.push_back(b);
        }
        party.push_back(people);
    }

    bool flag = true;
    if(truth > 0){
        for(int i = 0; i < party.size();i++){
            flag = true;
            if(findUnion(party[i][0]) == findUnion(countTruth[0])){
                flag = false;
            }
            if(flag == true){
                answer++;
            }
        }
    }
    else{
        answer = party.size();
    }

    cout<<answer<<endl;

    return 0;
}