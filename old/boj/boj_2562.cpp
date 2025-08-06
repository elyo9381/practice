#include <bits/stdc++.h>
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;

// #define endl '\n'
#define MAXN 101
#define pf1l(a) cout << a << '\n'
#define pf1(a) cout << a << ' '
#define sf1(a) cin >> a
#define rep(i,a,b) for(int i = a; i < b; i++)
#define pb(x) push_back(x)
#define sf2(a,b) cin >> a >> b

using namespace std;


vector<int> v;

int a, arr[MAXN];


void Input()
{

    for(int i= 0; i<9; i++){

      cin >> arr[i];
    }
    
}

void Solution()
{   
    int idx = 0, max = 0;
    for(int i = 0 ; i<9; i++)
    {
        if( max < arr[i]){
            max = arr[i];
        }
    }
      cout<< max <<endl;
    for(int i = 0; i<9; i++)
    {
        if( arr[i] == max){

            cout << i+1<<endl;
            break;
        }
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

