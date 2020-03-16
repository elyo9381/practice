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




int n,sum = 0;


void Input()
{
    cin >> n;

}

int Solution()
{  
    if(n % 4 == 0)
    {
        if(n%100 != 0 || n%400 ==0)
        {
            return 1;
        }
    }
    return 0;
} 

void Solve()
{
    Input();
    cout<<Solution()<<endl;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solve();
    return 0;
}

