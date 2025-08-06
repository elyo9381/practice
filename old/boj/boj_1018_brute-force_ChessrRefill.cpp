#include <bits/stdc++.h>
#define endl '\n'
#define MAXN 50
using namespace std;

// 체스판 다시칠하기는 . 구체적으로, 각 칸이 검은색과 흰색 중 하나로 색칠되어 있고, 변을 공유하는 두 개의 사각형은 다른 색으로 칠해져 있어야 한다
// 같은 색이 나올경우엔 다 칠하는 경우이므로 그경우만 다시칠하면 된다. 
// 그렇게 때문에 완전탐색 이고 for문을 이용하여서 풀수있는것이다. 
int M, N;
char MAP[MAXN][MAXN];
 
int Min(int A, int B) { if (A < B) return A; return B; }
 
void Input()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> MAP[i][j];
        }
    }
}

 
int Make_White_First(int x, int y)
{
    //x가 0일수도 잇고 1일수도 잇어
    //y도 0일수도 잇고 1일수도 잇어
    // why?? 맵을 타고 8*8을 만들수있어야하고 또한 이전과는 다르게 체크를 해야하기 떄문이다.
    int Cnt = 0;
 
    for (int i = x; i < x + 8; i++)
    {
        for (int j = y; j < y + 8; j++)
        {
            if (i == x || i == x + 2 || i == x + 4 || i == x + 6)
            {
                if (j == y || j == y + 2 || j == y + 4 || j == y + 6)
                {
                    if (MAP[i][j] != 'W') Cnt++;
                }
                else
                {
                    if (MAP[i][j] != 'B') Cnt++;
                }
            }
            else
            {
                if (j == y || j == y + 2 || j == y + 4 || j == y + 6)
                {
                    if (MAP[i][j] != 'B') Cnt++;
                }
                else
                {
                    if (MAP[i][j] != 'W') Cnt++;
                }
            }
        }
    }
    return Cnt;
}
 
int Make_Black_First(int x, int y)
{
    int Cnt = 0;
 
    for (int i = x; i < x + 8; i++)
    {
        for (int j = y; j < y + 8; j++)
        {
            if (i == x || i == x + 2 || i == x + 4 || i == x + 6)
            {
                if (j == y || j == y + 2 || j == y + 4 || j == y + 6)
                {
                    if (MAP[i][j] != 'B') Cnt++;
                }
                else
                {
                    if (MAP[i][j] != 'W') Cnt++;
                }
            }
            else
            {
                if (j == y || j == y + 2 || j == y + 4 || j == y + 6)
                {
                    if (MAP[i][j] != 'W') Cnt++;
                }
                else
                {
                    if (MAP[i][j] != 'B') Cnt++;
                }
            }
        }
    }
    return Cnt;
}
 
void Make_Chess()
{
    int White_First_Min;
    int Black_First_Min;
    int Total_Min = 9999;
 
    for (int i = 0; i < N; i++)
    {
        if (i + 8 > N) break;
        for (int j = 0; j < M; j++)
        {
            if (j + 8 > M) break;
 
            White_First_Min = Make_White_First(i, j);
            Black_First_Min = Make_Black_First(i, j);
            Total_Min = Min(Total_Min, Min(White_First_Min, Black_First_Min));
        }
    }
    cout << Total_Min << endl;
}
 
void Solution()
{
    Make_Chess();
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
 
    //    freopen("Input.txt", "r", stdin);
    Solve();
 
    return 0;
}


// koosaga code 

#include <cstdio>
#include <algorithm>
using namespace std;
char str[51][51];
int n, m;

int trial(int x, int y){
    int cnt = 0;
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(str[i + x][j + y] != ((x + i + y + j) % 2 == 0? 'W' : 'B')){
                cnt++;
            }
        }
    }
    cout<< cnt<<endl;
    return min(64 - cnt, cnt);
}

int main(){
    int ret = 1e9;
    scanf("%d %d",&n,&m);
    for(int i=0; i<n; i++){
        scanf("%s",str[i]);
    }
    for(int i=0; i+7<n; i++){
        for(int j=0; j+7<m; j++){
            ret = min(ret,trial(i,j));
        }
    }
    printf("%d",ret);
}