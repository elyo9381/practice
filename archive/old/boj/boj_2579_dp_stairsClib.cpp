
#include <bits/stdc++.h>
// #include <vector>
using namespace std;

/* */
const int mod =10007;
const int maxn = 1000;

int dp[maxn+1][3] = {0,};
int d[maxn+1] = {0,};
int buf[maxn+1];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;

    cin>> T;

    for(int i =1; i<=T;i++)
        cin >> buf[i];


    dp[1][1] = buf[1];

    dp[2][1] = buf[2];
    dp[2][2] = dp[1][1] + buf[2];

    
    
    // why 3부터 하냐
    // XOO일때도 있으니 3부터 돌아야한다. 
    // 나는 XOXO , OOXO경우만 생각했음
     

    for(int i = 3; i<=T; i++)
    {
        dp[i][1] = max(dp[i-2][1],dp[i-2][2]) + buf[i];
        dp[i][2] = dp[i-1][1] +buf[i];
    }

    d[1] = buf[1];
    d[2] = d[1] + buf[2];

    for(int i =3; i<=T; i++)
    {
        d[i] = max(d[i-2]+buf[i],d[i-3]+buf[i-1]+buf[i]);
    }


    cout<< d[T] <<"\n";
    // cout<< max(dp[T][1],dp[T][2])<<"\n";
}

