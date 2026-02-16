
#include <bits/stdc++.h>
// #include <vector>
using namespace std;

/* 점화식 구성은 잘하였으나 
type에서 int형은 범위를 벗어나게 된다. 
그렇기 떄문에 long long 을 한다. 

알고리즘 풀면서 고려할것 변수의 형을 */
const int mod =10007;
const int maxn = 100;

long long dp[maxn+1]= {0,};

int buf[maxn+1];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin>> T;


    while(T--)
    {
        int n;
        cin >> n;
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        dp[3] = 1;
        dp[4] = 2;
        dp[5] = 2;
        for(int i = 6; i<=n; i++)
        {
            dp[i] = dp[i-1] + dp[i-5];
            // dp[i] = dp[i-2] + dp[i-3];
        }
        
        cout << dp[n] << "\n";

    }

}



