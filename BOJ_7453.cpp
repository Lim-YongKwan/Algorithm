#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    long long answer = 0;
    int n;
    cin>>n;
    vector<long long> a(n,0);
    vector<long long> b(n,0);
    vector<long long> c(n,0);
    vector<long long> d(n,0);

    for(int i = 0;i<n;i++){
        cin>>a[i]>>b[i]>>c[i]>>d[i];
    }

    vector<long long> sum_a;

    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            sum_a.push_back(a[i] + b[j]);
        }
    }

    vector<long long> sum_c;

    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            sum_c.push_back(c[i] + d[j]);
        }
    }

    sort(sum_a.begin(),sum_a.end());
    sort(sum_c.begin(),sum_c.end());

    for(int i = 0;i<sum_a.size();i++){
        long long temp = -(sum_a[i]);
        long long lower = lower_bound(sum_c.begin(),sum_c.end(),temp) - sum_c.begin();
        long long upper = upper_bound(sum_c.begin(),sum_c.end(),temp) - sum_c.begin();
        if(temp == sum_c[lower]){
            answer += (upper - lower);
        }
        //sum_c의 lower bound와 upper bound 파악해주기.
    }

    cout<<answer<<endl;
    
    return 0;
}