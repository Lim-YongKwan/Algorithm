#include <iostream>
#include <vector>

using namespace std;

int bfs_tree[10][10];

int main(){
    int n;
    cin>>n;
    vector<int> people(n,0);

    bfs_tree[1][2] = 1;
    bfs_tree[1][3] = 1;
    bfs_tree[1][8] = 1;


    for(int i = 0;i<10;i++){
        for(int j = 0;j<10;j++){
            cout<<bfs_tree[i][j]<<" ";
        }
        cout<<endl;
    }


    for(int i = 1;i<=n;i++){
        int temp = 0;
        cin>>temp;
        
        for(int j = 0;j<n;j++){
            if(temp == 0 && people[j] == 0){
                people[j] = i;
                break;
            }
            if(people[j] == 0 ){
                temp--;
            }
        }
    }
    for(int i = 0;i<n;i++){
        cout<<people[i]<<" ";
    }

    return 0;
}