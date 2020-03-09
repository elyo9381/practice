#include <bits/stdc++.h>
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define endl '\n'
#define MAXN 1001
#define pf1l(a) cout << a << '\n'
#define pf1(a) cout << a << ' '
#define sf1(a) cin >> a
#define rep(i,a,b) for(int i = a; i < b; i++)
#define pb(x) push_back(x)
#define sf2(a,b) cin >> a >> b

using namespace std;

/*
    N 다리를 건너는 트럭의수
    W 다리의 길이
    L 다리의 최대 하중
    위와 같이 입력을 받고 queue를 통해서 최대하중에 넘으면
    0를 더해주어서 논리적 데이터를 설정하면된다.
    이때 cnt 또한 같이 늘려준다. 

    구현 문제 다양하게 구현할수있다.

*/

int N, W, L;
int arr[MAXN];
int sum  = 0, cnt = 0;
queue<int> q;

void Input()
{
    cin >> N >> W >> L;
}

void Solution()
{  
    while(N--){
        int d; cin >> d;

        while(true){
            if(q.empty()){
                q.push(d);
                cnt++;
                sum += d;
                break;
            }
            else if (q.size() == W){
                sum -= q.front(); q.pop();
            }
            else {
                if(sum + d> L){
                    q.push(0);
                    cnt++;
                }
                else {
                    q.push(d);
                    cnt++;
                    sum += d;
                    break;
                }
            }
        }
    }
    cout<< cnt + W << endl;

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
