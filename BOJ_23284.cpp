#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int visit[11];
vector<int> ret;
void backtracking(int n, vector<int> sequence, int cnt)
{
    if (n == ret.size()) {
        for(int i = 0;i<ret.size();i++){
            cout<<ret[i]<<" ";
        }
        cout << endl;
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (visit[i] == 0)
        {
            visit[i] = 1;
            sequence.push_back(i);
            int se_size = sequence.size();
            for(int j = se_size -1  ; j>= i;j--){
                ret.push_back(sequence.back());
                sequence.pop_back();
            }
            backtracking(n, sequence, cnt + 1);
            for(int j = se_size - 1;j>=i;j--){
                sequence.push_back(ret.back());
                ret.pop_back();
            }
            // sequence.pop_back();
            visit[i] = 0;
        }
    }
    return;
}

int main()
{
    int n;
    cin >> n;
    vector<int> sequence;
    backtracking(n, sequence, 1);
    return 0;
}