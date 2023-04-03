#include <iostream>
#include <vector>
#include<algorithm>
#define endl "\n"

using namespace std;

bool prime[10000001];

void eratos(int n)
{
    prime[0] = true;
    prime[1] = true;

    for (int i = 2; i * i <= n; i++)
    {
        if (prime[i] == false)
        {
            for (int j = i * i; j <= n; j += i)
            {
                prime[j] = true;
            }
        }
    }
    return;
}

bool palindrome(int n){
    vector<int> ans;
    while(n>=1){
        ans.push_back(n % 10);
        n/=10;
    }
    vector<int> ans2 = ans;
    reverse(ans.begin(),ans.end());
    if(ans2 == ans){
        return true;
    }
    else{
        return false;
    }
}

int main()
{
    int n;
    cin>>n;
    eratos(10000001);
    for(int i = n;i<=10000001;i++){
        if(prime[i] == false){
            if(palindrome(i) == true){
                cout<<i<<endl;
                break;
            }
        }
    }
    return 0;
}