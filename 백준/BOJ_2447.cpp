#include<iostream>
#define endl "\n"

using namespace std;

char stars[7000][7000];

void fold(int x, int y, int size){

    if(size > 3){
        fold(x,y,size/3);
        fold(x + size / 3,y, size / 3);
        fold(x + 2 * size / 3, y , size / 3);
        fold(x, y + size / 3, size / 3);
        fold(x, y + 2 * size / 3, size / 3);
        fold(x + 2 * size / 3, y + size / 3, size / 3);
        fold(x + size / 3 , y + 2 * size / 3 , size / 3);
        fold(x + 2 * size / 3, y + 2 * size / 3, size / 3);
        return;
    }

    for(int i = x;i< x + size;i++){
        for(int j = y;j<y + size;j++){
            if(i == x + 1 and j == y + 1){
                continue;
            }
            else{
                stars[i][j] = '*';
            }
        }
    }
    return;
}

int main(){
    int n;
    cin>>n;
    fold(0,0,n);
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(stars[i][j] == '*'){
                cout<<stars[i][j];
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }

    return 0;
}