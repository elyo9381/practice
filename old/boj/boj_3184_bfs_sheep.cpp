#include <bits/stdc++.h>
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;

// #define endl '\n'
#define MAXN 254
#define pf1l(a) cout << a << '\n'
#define pf1(a) cout << a << ' '
#define sf1(a) cin >> a
#define rep(i,a,b) for(int i = a; i < b; i++)
#define pb(x) push_back(x)
#define sf2(a,b) cin >> a >> b

using namespace std;


/*

*/

bool vis[MAXN][MAXN];
char MAP[MAXN][MAXN];

int m,n,Twolf = 0, Tsheep= 0;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

queue<pair<int,int> > q;

void bfs(int a, int b)
{
    int wolf = 0, sheep = 0;
    q.push({a,b});
    vis[a][b] =true;

    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if(MAP[x][y] == 'v') wolf++;
        if(MAP[x][y] == 'o') sheep++;

        for(int i = 0; i<4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if( nx >= 0 && ny >= 0 && nx < n && ny < m)
            {
                if( MAP[nx][ny] != '#' && !vis[nx][ny])
                {
                    vis[nx][ny] =true;
                    q.push({nx,ny});
                }
            }
        }
    }

    if(sheep > wolf) Tsheep = Tsheep + sheep;
    else Twolf = Twolf + wolf;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin >> n >> m;

    for(int i = 0; i< n; i++)
    {
        for(int j = 0; j<m;j++)
        {
            cin >> MAP[i][j];
        }
    }


    for(int i = 0; i<n; i++)
    {
        for(int  j= 0 ; j<m; j++)
        {
            if(!vis[i][j])
            {
                bfs(i,j);
            }            
        }
    }

    cout << Tsheep << " " << Twolf <<endl;
}
