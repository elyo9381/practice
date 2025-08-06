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
    dx 배열을 전역 변수로 두지 않는 경우는 계속해서 a,b값이 바뀌어서
    결과값에 영향을 미치기때문이다. 
    그래서 함수내부에 dx의 값을 설정하여서 
    왔다 갔다를 설정한다. 
*/
bool visited[100001];
int a, b, n, m;
 
void bfs(){
    queue<pair<int,int> > q;
    q.push({n, 0});
    visited[n] = true;
    int dx[] = { 1,-1,a,b,-a,-b,a,b };
    while (!q.empty()) {
        int cur = q.front().first;
        int time = q.front().second;
        q.pop();

        if (cur == m) {
            printf("%d\n", time);
            return;
        }
        
        int next;
        for (int i = 0; i < 8; i++) {
            if (i >= 6) {
                next = cur * dx[i];
            }
            else {
                next = cur + dx[i];
            }
            if (next >= 0 && next < 100001) {
                if (!visited[next]) {
                    q.push({next, time + 1});
                    visited[next] = true;
                }
            }
        }
    }
}
 
int main() {
    scanf("%d %d %d %d", &a, &b, &n, &m);
    bfs();
}
