#include <bits/stdc++.h>
#define endl '\n'
#define MAXN 1002
using namespace std;

int n, k;
int mod = 10007;
int d[MAXN][MAXN];

void Input()
{   
  cin >> n >> k;
}

void Solution()
{
    for(int i = 1; i<= 1000; i++){
        d[i][0] = d[i][i] = 1;
        for(int j = 1; j< i; j++){
            d[i][j] = (d[i-1][j] + d[i-1][j-1])%mod;
        }
    }
    cout<< d[n][k];   
}

void Solve()
{
    Input();
    Solution();
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solve();
    return 0;
}
