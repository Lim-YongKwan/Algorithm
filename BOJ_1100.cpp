#include<iostream>

using namespace std;

char chess[9][9];

int main(){

    int answer = 0;

    for(int i = 0;i<8;i++){
        for(int j = 0;j<8;j++){
            cin>>chess[i][j];
            if( (i + j) % 2 == 0 && chess[i][j] == 'F' ){
                answer++;
            }
        }
    }
    
    cout<<answer<<endl;

    return 0;
}