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
 cin >> str;을
 하면 안된다. 
 문장을 다 못받아오는것같다 
 위의결과는 Union만 받아와서 안된다
 즉 공백을 받지 못하므로 
 getline등으로 공백을 받아야한다.
 scanf(" %[^\n]", str); c언어 공백 받는법 str는 char배열 !

*/

int n, m,cnt = 0;
string str;
char arr[4] = {'U','C','P','C'};

void Input()
{
  
}

void Solution()
{   
    int idx = 0;
   getline(cin,str);

   for( int i = 0; i<str.size(); i++)
   {
    if( idx == 4)
        break;
    else if ( str[i] == arr[idx])
        idx++;
   }
   if(idx == 4)
    cout << "I love UCPC"; 
   else 
    cout << "I hate UCPC";

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

