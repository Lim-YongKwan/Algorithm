#include <iostream>
#include <algorithm>
#include <vector>
#define endl "\n"

using namespace std;

bool prime[10000001];

void eratos()
{
    prime[1] = true;
    prime[0] = true;
    for (int i = 2; i * i <= 10000001; i++)
    {
        if (prime[i] == false)
        {
            for (int j = i * i; j <= 10000001; j += i)
            {
                prime[j] = true;
            }
        }
    }
    return;
}

int main()
{
    int n;
    cin >> n;
    eratos();
    int answer = 0;

    for(int i = 2;i<=n;i++){
        if(prime[i] == 0 and answer == 0){
            for(int j = i;j<=n;j++){
                if(prime[j] == 0 and answer == 0){
                    for(int k = j;k<=n;k++){
                        if(prime[k] == 0 and answer == 0){
                            if(prime[n-i-j-k]==0 and n-j-i-k>=2){
                                cout<<i<<" "<<j<<" "<<k<<" "<<n-i-j-k<<endl;
                                answer = 1;
                            }
                        }
                    }
                }
            }
        }
    }

    if(answer != 1){
        cout<<-1<<endl;
    }

    return 0;
}