#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
    int maze[101][101];
    bool visit[101][101];
	int test_case;
	int T;
    cout<<"Print Hello"<<endl;
	cin>>T;
    cout<<"Print Complete!"<<endl;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        int N;
        cin>>N;

        for (int i = 0; i<N;i++){
            for(int j = 0; j<N; j++){
                cin>>maze[i][j];
            }
        }



	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}