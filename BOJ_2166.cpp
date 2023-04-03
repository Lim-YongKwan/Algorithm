#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

double solve(vector<double> x, vector<double> y, int n){
    double answer = 0.0;
    for(int i = 2;i<n;i++){
        answer += x[0] * y[i-1] + x[i-1] * y[i] + x[i] * y[0];
        answer -= x[i-1] * y[0] + x[i] * y[i-1] + x[0] * y[i];
    }
    return answer;
}

int main(){
    int n;
    cin>>n;
    vector<double> x(n,0);
    vector<double> y(n,0);
    for(int i = 0;i<n;i++){
        cin>>x[i];
        cin>>y[i];
    }
    double answer = solve(x,y,n) / 2;
    cout<<fixed;
    cout.precision(1);
    cout<<abs(answer)<<endl;
    return 0;
}


// #include<iostream>
// #include<vector>
// #include<math.h>
// using namespace std;
// typedef pair<double, double>P;

// double ccw(double x1, double x2, double x3, double y1, double y2, double y3) {
// 	double res = x1 * y2 + x2 * y3 + x3 * y1;
// 	res += (-y1 * x2 - y2 * x3 - y3 * x1);
// 	return res / 2;
// }

// int main() {
// 	int n; cin >> n;
// 	vector<P>arr(n);

// 	for (int i = 0; i < n; i++)
// 		scanf("%lf%lf", &arr[i].first, &arr[i].second);

// 	double res = 0;
// 	for (int i = 2; i < n; i++)
// 		res += ccw(arr[0].first, arr[i - 1].first, arr[i].first, arr[0].second, arr[i - 1].second, arr[i].second);

// 	printf("%.1lf", abs(res));
// 	return 0;
// }