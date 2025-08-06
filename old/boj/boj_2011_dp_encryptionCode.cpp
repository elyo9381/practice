
#include <bits/stdc++.h>
// #include <vector>
using namespace std;

/* */
const int mod =1000000;
const int maxn = 5000;

long long dp[maxn+1]= {0,};

int buf[maxn+1];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int len;
    string s;
    cin>> s;

    len = s.length();

    for(int i = 1; i<=len; i++){
        buf[i] = s[i-1] -'0';
    }


    dp[0] = 1;

    for(int i = 1; i<=len; i++){
        if(buf[i] >=1 && buf[i] <=9){
            dp[i] = (dp[i-1]+dp[i])%mod;
        }

        if(i==1) continue;

        int tmp = buf[i] + buf[i-1] *10;
        if(tmp >=10 && tmp <=26){
            dp[i] = (dp[i-2]+dp[i]) % mod;
        }
    }

    for(int i =1; i< len; i++)
    {
        cout<< "dp["<< i << "] = " << dp[i] <<"\n";
    }


    cout<< dp[len] <<"\n";


}


