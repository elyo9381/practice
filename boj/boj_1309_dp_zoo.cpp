



#include <bits/stdc++.h>
// #include <vector>
using namespace std;

/* */
const int mod =9901;
const int maxn = 100000;

long long dp[maxn+1][3];

int buf[maxn+1];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;

    cin>>t;



    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[0][2] = 0;

    dp[1][0] = 1;
    dp[1][1] = 1;
    dp[1][2] =1;
    
    // dp[2][0] = 3;
    // dp[2][1] = 2;
    // dp[2][2] =2;

    for(int i=2; i<=t;i++){
        dp[i][0] = (dp[i-1][0] + dp[i-1][1] +dp[i-1][2]) % mod;
        dp[i][1] = (dp[i-1][0] + dp[i-1][2]) % mod;
        dp[i][2] = (dp[i-1][0] + dp[i-1][1]) % mod;
    }


    cout<< (dp[t][0] + dp[t][1]+dp[t][2]) % mod << endl;

}



