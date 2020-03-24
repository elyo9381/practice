#include <iostream>
#include <cstring> // 문자열관련 처리
#include <vector>	
#include <algorithm> // avg,max...
#include <queue>
#include <utility> // pair ..


#define MAXN 102
using namespace std;

// 큐에 시작 좌표를 넣었고 그것을 통해서 
// 배열에 저장되어 있는 다음 좌표랑 거리 비교를 한다.
// 맥주 한박스(20)으로 갈수있는거리가 1000이므로 

// 그래서 좌표를 더한값이 1000보다 작으면
// 갈수있는 맥주를 먹으면서 갈수있는 방향인것이고 
// 다음좌표를 큐에 넣어서 큐가 비어있는 상황을 만들지 않고 
// 목적지 까지 갈수있는것이다.

int t,n,ans;
int chk[MAXN];
int arr[MAXN][2];
queue<pair<int,int> > q ;

void bfs()
{
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if( x == arr[n+1][0] && y == arr[n+1][1]){
            ans = 1;

            return;
        }

        int ny,nx;

        for(int i = 1; i< n+2; i++)
        {
            nx = abs(x - arr[i][0]);
            ny = abs(y - arr[i][1]);

            if(chk[i] == 0 && nx + ny <=1000)
            {
                chk[i] = 1;
                q.push(make_pair(arr[i][0], arr[i][1]));
            }
        }
    }
}

void Input()
{
    cin >> t;
}
void Solution()
{
    for(int i = 0; i<t; i++)
    {
        while(!q.empty())
        {
            q.pop();
        }
            memset(chk, 0, sizeof(chk));
            memset(arr, 0, sizeof(arr));

            ans = 0;

            cin >> n;
            for(int i = 0; i< n+2; i++)
            {
                cin >> arr[i][0] >> arr[i][1];
            }

            q.push(make_pair(arr[0][0],arr[0][1]));
            bfs();

        if(ans == 1)cout << "happy" << "\n";
        else cout << "sad" <<  "\n";
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
    cin.tie(NULL); cout.tie(NULL);
 
    //freopen("Input.txt", "r", stdin);
    Solve();
 
    return 0;
}

