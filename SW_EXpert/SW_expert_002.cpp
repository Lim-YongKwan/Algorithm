#include<iostream>
#include<vector>
#include<string>
#define endl "\n"

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
        long long s;
        int x,y;
        cin>>s>>x>>y;
        if(x < y){
            swap(x,y);
        }

        string answer = "";
        int count = 1;
        long long s_temp = s;
        
        while(s / 10 > 0){
            s /= 10;
            count++;
        }
        s = s_temp;
        for(int i = 0;i<count;i++){
            answer += to_string(x);
        }

        

        cout<<"#"<<test_case<<" "<<answer<<endl;

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}