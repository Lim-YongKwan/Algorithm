#include <iostream>
#include <string>
#include <vector>

using namespace std;


vector<string> solution(vector<string> words) {
    vector<string> result;
    for (int i = 0; i < words.size(); i++) {
        string word = words[i];
        for (int j = 0; j < word.size(); j++) {
            for (int k = 1; k <= word.size() - j; k++) {
                string sub = word.substr(j, k);
                bool overlap = false;
                for (int l = 0; l < words.size(); l++) {
                    if (l != i && words[l].find(sub) != string::npos) {
                        overlap = true;
                        break;
                    }
                }
                if (!overlap) {
                    result.push_back(sub);
                }
            }
        }
    }
    if (result.empty()) {
        result.push_back("none");
    }
    return result;
}

int main() {
    vector<string> words;
    words.push_back("pencil");
    words.push_back("cilicon");
    words.push_back("contrabase");
    words.push_back("picturelist");
    vector<string> result = solution(words);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
    return 0;
}