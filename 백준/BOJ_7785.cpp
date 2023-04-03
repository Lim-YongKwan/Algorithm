#include<iostream>
#include<map>
#include<set>
#include<vector>
#define endl "\n"
using namespace std;

int main(){
    // set<string, greater<string> > company;
    // int n;
    // cin>>n;
    // for(int i = 0;i<n;i++){
    //     string person,log;
    //     cin>>person>>log;
    //     if(log == "enter"){
    //         company.insert(person);
    //     }
    //     else if(log == "leave"){
    //         company.erase(person);
    //     }
    // }
    // set<string>::iterator iter;
    // for(iter = company.begin();iter!=company.end();iter++){
    //     cout<<*iter<<endl;
    // }
    // return 0;
    int n; cin >> n;
	vector<string> v(n);
    string t;
	for (auto& i : v) cin >> i >> t;
	sort(v.rbegin(), v.rend());
	for (int i = 0; i < n; i++) {
		if (i != n - 1 && v[i] == v[i + 1]) i++;
		else cout << v[i] << '\n';
	}
}