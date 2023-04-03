#include<iostream>
#define endl "\n"

using namespace std;

char star[10000][10000];

void fold(int y, int x, int size){

    if(size > 3){
        fold(y ,x ,size/2 );
        fold(y + size / 2 ,x - size / 2 ,size/2);
        fold(y + size / 2, x + size / 2  ,size/2);
        return;
    }

    star[y][x] = '*';
    star[y+1][x-1] = '*';
    star[y+1][x+1] = '*';

    for(int i = x;i<x+ size * 2 -1; i++){
        star[y+2][i-2] = '*';
    }

    return;
}

int main(){
    int n;
    cin>>n;

    fold(0,n-1,n);

    for(int i = 0;i<n;i++){
        for(int j = 0 ;j< n * 2-1 ;j++){
            if(star[i][j] == '*'){
                cout<<'*';
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }


    return 0;
}