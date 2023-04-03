#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'minNum' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER samDaily
 *  2. INTEGER kellyDaily
 *  3. INTEGER difference
 */

int minNum(int samDaily, int kellyDaily, int difference) {
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string samDaily_temp;
    getline(cin, samDaily_temp);

    int samDaily = stoi(ltrim(rtrim(samDaily_temp)));

    string kellyDaily_temp;
    getline(cin, kellyDaily_temp);

    int kellyDaily = stoi(ltrim(rtrim(kellyDaily_temp)));

    string difference_temp;
    getline(cin, difference_temp);

    int difference = stoi(ltrim(rtrim(difference_temp)));

    int result = minNum(samDaily, kellyDaily, difference);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
