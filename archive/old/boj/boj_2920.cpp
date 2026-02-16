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
string str;
int arr[9];
int asce[9]={1,2,3,4,5,6,7,8};
int desce[9]={8,7,6,5,4,3,2,1};

void Input()
{
    for(int i = 0; i<8; i++)
    {
        cin >> arr[i];
    }
}

void Solution()
{ 
    int idx = 0, idx2 =0;
    for(int i = 0; i<8; i++){
        if( arr[i] == asce[i]){
            idx++;
        }
        else if( arr[i] == desce[i]){
            idx2++;
        }
    }

    if(idx == 8) cout << "ascending" <<endl;
    else if(idx2 == 8) cout << "descending" <<endl;
    else cout << "mixed" <<endl;

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

