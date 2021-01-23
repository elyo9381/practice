#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
#define hash 1000000007LL;
typedef long long ll;
typedef pair<int,int> pii;
const int MAX = 100001;


/*
    dp의 접근임을 생각해냈다. 
    또한 바텀엄으로 1 to n까지의 각 i의 수식을 작성하였지만 
    점화식을 세우지 못하였다.

    나는 너무 간단한 점화식  d[i] = d[i-1] + d[i-2] +1;
    등의 점화식만 생각하여 d[i] = d[i - j*j] + 1등의 점화식을 생각치 못하였다. 
    이러한 점을 고치자! 생각하자 생각해!!

 */

int main(){

 	ios::sync_with_stdio(false);
    cin.tie(0);


	int n;
	int INF = 1e9;
	cin >> n;

	vector<int> dp(n+1);

	dp[1] = 1;

	for(int i = 2; i<=n; i++){
		int minx = INF;
		for(int j = 1; j*j<=i; j++){
			int tmp = i - j*j;
			minx = min(minx,dp[tmp]);
		}
		dp[i] = minx + 1;
	}

	cout << dp[n] << '\n';
}