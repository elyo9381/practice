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

typedef pair<int, int> pii;

/*
    초기 입력은 스트링을 통해서 입력받았다 그리고 '0'을 빼줘서 
    int값으로 변형하였는데 
    처음부터 "1","0"을 int형으로 받아도 될거같다.

    pair를 사용하여 몇번째 바퀴이고 
    반시계로 가야하는지 시계로 가야하는지 체크하였다.

    조건에서 같은극일때는 움직임이없고 
    다른극일때는 반대반향으로 움직이는것은 방향 *= -1;을 통해서 구현하였다.

    deque를 이용해서 시계방향과 반시계반향의 
    입력과 삭제를 실행하고 바퀴의 순서는 q를 이용하여서 입력을 받았다. 

*/

deque<int> dp[5];
int k; 

void Input()
{
    for(int i =1; i<4; i++)
    {
        string s;
        cin >> s;

        for(int j=0; j < s.length(); j++)
            dq[i].push_back(s[j] - '0');
    }

}

void Solution()
{  
    cin >> k;   

    for(int i = 0; i< k; i++)
    {
        int num, dir;
        cin >> num >> dir;

        int idx = num;
        int tempDir = dir;
        queue<pair<int, int>> q;
        q.push({ idx, tempDir });

        while(1)
        {
            if(idx == 4)
                break;

            idx++;
            tempDir *= -1;
            if( dq[idx-1][2] != dq[idx][6])
                q.push({idx, tempDir});
            else 
                break;
        }

        idx = num;
        tempDir = dir;
        while(1)
        {
            if(idx ==1)
                break;

            idx--;
            tempDir *= -1;
            if( dq[idx +1][6] != dq[idx][2])
                q.push({idx, tempDir});
            else
                break;
        }

        while(!q.empty())
        {
            int cur = q.front().first;
            int rotate = q.front().second;
            q.pop();

            if(rotate == 1)
            {
                int temp = dq[cur].back();
                dq[cur].pop_back();
                dq[cur].pop_front(temp);
            }
            else
            {
                int temp = dp[cur].front();
                dq[cur].pop_front();
                dq[cur].pop_back(temp);
            }
        }
    }

    int result = 0;

    for (int i = 1; i < 5; i++)
             if (dq[i].front() == 1)
                     result += (int)pow(2, i - 1);

    cout << result << "\n";
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
