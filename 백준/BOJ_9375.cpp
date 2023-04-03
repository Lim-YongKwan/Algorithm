#include <iostream>
#include <vector>
#include <string>
#include<map>
#define endl "\n"
using namespace std;

int main()
{
    int t;
    cin >> t;
    int n;
    string catag, name;
    while (t--)
    {
        map<string, int> m;
        map<string, int>::iterator iter;
        cin >> n;
        while (n--)
        {
            cin >> name >> catag;
            if(m.find(catag) == m.end()){
                pair<string, int> temp;
                temp.first = catag;
                temp.second = 1;
                m.insert(temp);
            }
            else {
                m[catag]++;
            }
        }
        int answer = 1;
        for(iter = m.begin(); iter != m.end(); iter++){
            answer *= iter->second +1 ;
        }
        answer -= 1;
        cout<<answer<<endl;
    }
    // return 0;
}