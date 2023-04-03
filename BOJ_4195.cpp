#include <map>
#include <iostream>
#define endl "\n"

using namespace std;

int parent[200001];
int friends[200001];
string s1, s2;
map<string, int> m;
int cnt;

int findUnion(int x){
    if(parent[x] == x){
        return x;
    }
    return parent[x] = findUnion(parent[x]);
}

void mergeUnion(int a, int b){
    a = findUnion(a);
    b = findUnion(b);
    if(a != b){
        parent[b] = a;
        friends[a] += friends[b];
    }
    return;
}

int main(){

    ios::sync_with_stdio(0);
	cin.tie(0);

    int testcase;
    cin>>testcase;
    while(testcase--){
        int n;
        cin>>n;
        cnt = 1;

        for(int i = 0;i<200001;i++){
            parent[i] = i;
            friends[i] = 1;
        }

        for(int i = 0;i<n;i++){
            cin>>s1>>s2;

            if(m[s1] == 0){
                m[s1] = cnt;
                cnt++;
            }

            if(m[s2] == 0){
                m[s2] = cnt;
                cnt++;
            }
            mergeUnion(m[s1],m[s2]);
            cout<<friends[findUnion(m[s1])]<<endl;
        }
    }

    return 0;
}