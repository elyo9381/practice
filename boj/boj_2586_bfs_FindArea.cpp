#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
 
#define endl "\n"
#define MAX 100
using namespace std;
 
int M, N, K, Area_Num;
int MAP[MAX][MAX];
bool Visit[MAX][MAX];
 
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
 
vector<int> Area_Size;
 
int Min(int A, int B) { if (A < B) return A; return B; }
 
void Initialize()
{
    memset(MAP, 0, sizeof(MAP));
    memset(Visit, false, sizeof(Visit));
}
 
void CheckInMap(int y, int x, int yy, int xx)
{
    x = M - x;
    xx = M - xx;
    for (int i = y; i < yy; i++)
    {
        for (int j = xx; j < x; j++)
        {
            MAP[j][i] = 1;
        }
    }    
}
 
void Input()
{
    // M 행의 개수 N열의 개수 K번 반복 
    cin >> M >> N >> K;
    for (int i = 0; i < K; i++)
    {
        int x, y, xx, yy;
        cin >> y >> x >> yy >> xx;
        CheckInMap(y,x,yy,xx);
    }
 
    // for (int i = 0; i < M; i++)
    // {
    //    for (int j = 0; j < N; j++)
    //    {
    //        cout << MAP[i][j] << " ";
    //    }
    //    cout << endl;
    // }
}
 
void BFS(int a, int b)
{
    int Size = 1;
    queue<pair<int, int>> Q;
    Q.push(make_pair(a, b));
    Visit[a][b] = true;
 
    while (Q.empty() == 0)
    {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
 
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
 
            if (nx >= 0 && ny >= 0 && nx < M && ny < N)
            {
                if (Visit[nx][ny] == false && MAP[nx][ny] == 0)
                {
                    Q.push(make_pair(nx, ny));
                    Visit[nx][ny] = true;
                    Size++;
                }
            }
        }
    }
    Area_Size.push_back(Size);
}
 
void Solution()
{
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (MAP[i][j] == 0 && Visit[i][j] == false)
            {
                Area_Num++;
                BFS(i, j);
            }
        }
    }
 
    cout << Area_Num << endl;
    sort(Area_Size.begin(), Area_Size.end());
    for (int i = 0; i < Area_Size.size(); i++)
    {
        cout << Area_Size[i] << " ";
    }
    cout << endl;
}
 
void Solve()
{
    Initialize();
    Input();
    Solution();
}
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
//    freopen("Input.txt", "r", stdin);
    Solve();
 
    return 0;
}
