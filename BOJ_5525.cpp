#include<iostream>
#include<string>
#include<string.h>
#include<vector>
#define endl "\n"

using namespace std;

int n, m;

vector<int> makeTable(string substr) { // fs : 검색할 문자열
	int substrSize = substr.size();
	vector<int>	table(substrSize, 0); // 0으로 초기화
	int j = 0; 
	for (int i = 1; i < substrSize; i++) {
		// 일치하지 않으면
		while (j > 0 && substr[i] != substr[j]) { 
			j = table[j - 1];
		}
		// 일치하면
		if (substr[i] == substr[j]) {
			table[i] = ++j;
		}
	}
	return table;
}

int KMP(string s, string substr) { 
    int answer = 0;
	vector<int> table = makeTable(substr);
	int sSize = s.size();
	int substrSize = substr.size();
	int j = 0;
	for (int i = 0; i < s.size(); i++) {
		// 일치하지 않는 경우 (단, j > 0)
		while (j > 0 && s[i] != substr[j]) {
			j = table[j - 1];
		}
		// 일치한 경우
		if (s[i] == substr[j]) {
			if (j == substrSize - 1) { // 문자열이 완전히 일치하면
				// printf("%d번째에서 발견\n", i - substrSize + 2);
                answer++;
				j = table[j];
			}
			else {
				j++;
			}
		}
	}
    return answer;
}

int main(){
    cin>>n>>m;
    string s;
    cin >> s;
    string substr = "";
    for(int i = 0;i<n;i++){
        substr.append("IO");
    }
    substr.append("I");

    cout<<KMP(s,substr);
}