#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> dp(n,2000);
    dp[3] = dp[5] = 1;
    for(int i = 6; i<=n; i++){
        dp[i] = min(dp[i-3],dp[i-5])+1;
    }
    if(dp[n] >=2000) cout << ("-1");
    else cout << dp[n];
}