#include<iostream>
#define endl "\n"

using namespace std;

int confetti[130][130];
int blue,white;

void fold(int x, int y, int size){
    int check = confetti[x][y];
    
    for(int i = x;i< x+size;i++){
        for(int j = y;j<y+size;j++){
            if(confetti[i][j] != check){
                check = 2;
            }
            if(check == 2){
                fold(x, y, size / 2);
                fold(x, y + size/2, size /2 );
                fold(x + size / 2, y , size / 2);
                fold(x + size / 2, y + size / 2, size / 2);
                return;
            }
        }
    }
    if( check == 0){
        white++;
    }
    else{
        blue++;
    }
    return;
}

int main(){
    int n;
    cin>>n;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin>>confetti[i][j];
        }
    }

    fold(0,0,n);

    cout<<white<<endl;
    cout<<blue<<endl;

    return 0;
}