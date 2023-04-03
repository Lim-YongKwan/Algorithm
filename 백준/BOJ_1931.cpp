#include <iostream>
#include <vector>
#include<algorithm>
#define endl "\n"

using namespace std;

int main()
{

    int n;
    cin >> n;
    vector<pair<int, int> > boardroom;
    for (int i = 0; i < n; i++)
    {
        pair<int, int> temp;
        cin >> temp.second >> temp.first;
        boardroom.push_back(temp);
    }

    sort(boardroom.begin(), boardroom.end());

    int max_answer = 0;
    
        int process = boardroom[0].first;
        int count = 1;

        for(int j = 1;j<n;j++){
            if(boardroom[j].second >= process){
                process = boardroom[j].first;
                count++;
            }
        }
        max_answer = max(max_answer,count);

    cout<<max_answer<<endl;

    return 0;
}