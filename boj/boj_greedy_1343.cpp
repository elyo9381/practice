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
    폴리오미노 XXXX.XX 가 주어졌을때 4개짜리는 A로 2개짜리는 B로 바꿔야하는 
    문제였다. 
    여기서 주목할점은 .을 세어야한다. 
    idx를 변수를 두어서 cnt - idx를 하고 이것이 4보다 크면 A 아니면 B이다.
    

*/

string str;

void Input()
{
    cin >> str;
}

void Solution()
{   
    for(int i = 0; i<str.size();)
    {
        if(str[i] == '.')
        {
            i++;
            continue;
        }

        int cnt  = 0;
        for(int j = i; i<str.size() && str[j] =='X'; j++)
        {
            cnt++;
        }

        if(cnt%2)
        {
            cout << -1 <<endl;
            break;
        }
        int idx = 0;

        while(idx < cnt)
        {
            if(cnt - idx >=4 )
            {
                for(int k = 0; k<4; k++){
                    str[i+idx] = 'A';
                    idx++;
                }
            }
            else
            {
                for(int k =0; k<2; k++){
                    str[i+idx] = 'B';
                    idx++;
                }
            }
        }

        i+=cnt;
    }

    cout<<str<<"\n";

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