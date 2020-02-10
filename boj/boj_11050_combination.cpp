#include <bits/stdc++.h>
#define endl '\n'
#define MAXN 100001
using namespace std;

int n, k;


void Input()
{   
  cin >> n >> k;
}
void Solution()
{
    int ret = 1;
    for(int i =1; i<=n; i++) ret *=i;
    for(int i =1; i<=k; i++) ret /=i;
    for(int i =1; i<=n-k; i++)ret /= i;

    cout<< ret;

   
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
