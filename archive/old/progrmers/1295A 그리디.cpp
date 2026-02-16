#include <bits/stdc++.h>
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;

// #define endl '\n'
#define MAXN 999
#define pf1l(a) cout << a << '\n'
#define pf1(a) cout << a << ' '
#define sf1(a) cin >> a
#define rep(i,a,b) for(int i = a; i < b; i++)
#define pb(x) push_back(x)
#define sf2(a,b) cin >> a >> b

using namespace std;

int t, n;


void Input()
{
    cin >> t;

}

void Solution()
{ 
   for(int i = 0; i<t; i++){
    cin >> n;
    if( n %2 ==1){
        cout << 7 << "";
        n-=3;
    }

    while(n>0)
    {
        cout<< 1<< "";
        n -=2;
    }
    
    cout << endl;

   }
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