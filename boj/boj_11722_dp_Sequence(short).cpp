#include <bits/stdc++.h>
// #include <vector>
using namespace std;

/* */
const int mod =10007;
const int maxn = 1000;

// int dp[maxn+1] = {0,};
// int buf[maxn+1];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;

    cin>> T;
    

    vector<int> dp(T);
    vector<int> buf(T);


    for(int i =0; i<T; i++)
    {
        cin >> buf[i];
    }

    for(int i =0; i<T;i++)
    {

        dp[i] = 1;
        for(int j = 0; j<i; j++)
        {
            if(buf[j]>buf[i] && dp[j]+1>dp[i] )
            {
                dp[i] = dp[j]+1;

            }
        }
    }

    cout<< *max_element(dp.begin(), dp.end())<<"\n";

}