#include <bits/stdc++.h>
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;

// #define endl '\n'
#define MAXN 1001
#define pf1l(a) cout << a << '\n'
#define pf1(a) cout << a << ' '
#define sf1(a) cin >> a
#define rep(i,a,b) for(int i = a; i < b; i++)
#define pb(x) push_back(x)
#define sf2(a,b) cin >> a >> b

using namespace std;

/*
    그리디 문제이고 2명당 1명이 팀을 이루어야한다.
    하지만 전체 인원에서 k명은 꼭 대회에 나가야한다.
    그렇기 때문에 남자에서 혹은 여자에서 빼주어야하고 
    이때 최적의 방법을 통해서 빼야 최대로 많은 팀을 구성
    할수있게 된다. 

    2명당 1명이 되므로 최소값을 구해주었다. 
    그리고 전체에서 뺀경우를 계산하여 최적의 값을 구한다.
*/

int m, t, n, mx = 0;
string str;
int arr[MAXN];
double avg = 0;


void Input()
{
    cin >> n >>  m >> t;
    cout << min(min(n/2,m),(m+n-t)/3);
}

void Solution()
{
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



