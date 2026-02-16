#include <iostream>
#include <cstdio>
#include <vector>
 
#define max(a,b)(a > b ? a : b)
#define MAX_N 52
#define MAX_V 102
using namespace std;
 
vector<int> adj[MAX_V];
vector<int> aMatch;
vector<int> bMatch;
 
int map[MAX_N][MAX_N];
int visit[MAX_V];
int visitCnt;
 
int Left[MAX_N][MAX_N];
int Right[MAX_N][MAX_N];
 
int n, m;
 
void fillLeft();
void fillRight();
void checkLeftandRight();

/*
    시뮬 + 이분매칭으로 풀이하였고 crocus의 방법으로 풀었다.
    시뮬을 통해서 어떻게 입력할지를 결정하였다. 
    비숍은 대각선으로만 이동하고 하나밖에 올수없는 성질을 이용하여 
    이분매칭하였다. 입력은 그래프 형식으로 받았으며 n을 입력받아 다시 n,m을
    설정하여 이분매칭에 필요한 파라미터를 구하였고
    배열에 비숍이 존재할수있는 입력값을 얻기 위해서 
    (tmpy<= n)
        map[tmpy++][tmpx++] = cnt를 이용하여 대각선에 값을 넣었다. 
*/
 
bool dfs(int a)
{
    if (visit[a] == visitCnt)
        return false;
 
    visit[a] = visitCnt;
 
    for (int next = 0; next < adj[a].size(); next++)
    {
        int b = adj[a][next];
 
        if (bMatch[b] == -1 || dfs(bMatch[b]))
        {
            aMatch[a] = b;
            bMatch[b] = a;
 
            return true;
        }
    }
 
    return false;
}
 
int bipartiteMatch()
{
    aMatch = vector<int>(n + 1, -1);
    bMatch = vector<int>(m + 1, -1);
 
    int size = 0;
 
    for (int a = 1; a <= n; a++)
    {
        visitCnt++;
        size += dfs(a);
    }
 
    return size;
}
 
int main()
{
    scanf("%d", &n);
 
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &map[i][j]);
 
    fillLeft();
    fillRight();
     //checkLeftandRight();
 
    // 1일때만 간선 연결(0일때는 벽이니)
    int maxL = 0, maxR = 0;
 
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (map[i][j] == 1)
            {
                adj[Left[i][j]].push_back(Right[i][j]);
 
                maxL = max(maxL, Left[i][j]);
                maxR = max(maxR, Right[i][j]);
            }
 
    // 이분매칭에 이용 될 n과 m은 maxL, maxR로 교체된다.
    n = maxL;
    m = maxR;    
 
    int get = bipartiteMatch();
    printf("%d", get);
 
    return 0;
}
 
 
void fillLeft()
{
    int y = 1;
    int x = n;
    int cnt = 1;
 
    // 오른쪽 위 시작 기준 대각선은 총 n번 반복
    for (int k = 0; k < 2*n-1; k++)
    {
        int tmpy = y;
        int tmpx = x;
        
        //2차원 배열의 대각선에 같은 값을 계속 넣는 방법 (오위 to 왼아)
        while (tmpy <= n)
            Left[tmpy++][tmpx++] = cnt;
 
        cnt++;
        x--;
    }
}
 
void fillRight()
{
    int y = n;
    int x = n;
    int cnt = 1;
 
    // 오른쪽 아래 시작 기준 대각선은 총 n번 반복
    for (int k = 0; k < 2*n-1; k++)
    {
        int tmpy = y;
        int tmpx = x;
        
        //2차원 배열의 대각선에 같은 값을 계속 넣는 방법(오아 to 왼위)
        while (tmpy > 0)
                Right[tmpy--][tmpx++] = cnt;
 
        cnt++;
        x--;
    }
}
 
void checkLeftandRight()
{
    cout << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << Left[i][j] << " ";
        cout << endl;
    }
 
    cout << endl;
 
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << Right[i][j] << " ";
        cout << endl;
    }
}


