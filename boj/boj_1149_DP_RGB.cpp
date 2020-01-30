#include <bits/stdc++.h>

#define endl '\n'
#define MAXN 1000

using namespace std;

typedef long long ll;

int dp[MAXN][3];
int s[MAXN][3];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;

	cin >> n ;
	for(int i =0; i <n ; i++)
		cin >> s[i][0] >> s[i][1] >> s[i][2];


	dp[0][0] = s[0][0];
	dp[0][1] = s[0][1];
	dp[0][2] = s[0][2];

	for(int i =1; i<n; i++)
	{
		dp[i][0] = min(dp[i-1][1],dp[i-1][2]) + s[i][0];
		dp[i][1] = min(dp[i-1][0],dp[i-1][2]) + s[i][1];
		dp[i][2] = min(dp[i-1][0],dp[i-1][1]) + s[i][2];
	}

	cout<< min(min(dp[n-1][0],dp[n-1][1]),dp[n-1][2]);
}