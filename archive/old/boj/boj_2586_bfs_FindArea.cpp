#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
 
#define endl "\n"
#define MAX 100
using namespace std;



/* CheckInMap 에서는 문제 모양 그대로를 입력 받았다
scanf("%d %d %d %d",&p,&q,&r,&s);
        for (int j=p; j<r; j++) {
            for (int k=q; k<s; k++) {
                a[j][k] = 1;
            }
        }
구사과 코드이고 꼭 같은 모양이 아니더라도 
모습만 같으면 된다 코드를 참고하자.

*/
 
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
