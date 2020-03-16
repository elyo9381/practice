#include <bits/stdc++.h>
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;

// #define endl '\n'
#define MAXN 5
#define pf1l(a) cout << a << '\n'
#define pf1(a) cout << a << ' '
#define sf1(a) cin >> a
#define rep(i,a,b) for(int i = a; i < b; i++)
#define pb(x) push_back(x)
#define sf2(a,b) cin >> a >> b

using namespace std;



int arr[MAXN];
int sum = 0;


void Input()
{

    for(int i = 0; i<MAXN; i++)
    {
        cin >> arr[i];
    }
}

void Solution()
{  
    for(int i = 0 ; i<MAXN; i++)
    {
        sum +=(arr[i] * arr[i]);
    }

    sum %= 10;

    cout << sum << endl;
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



