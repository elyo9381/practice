#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

#define MAXN 100
using namespace std;


int N;
int MAP[MAXN][MAXN];
int Answer[MAXN][MAXN];

bool bvis[MAXN];
bool dvis[MAXN][MAXN];
queue<int> q;

void Input()
{
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		for(int j= 0; j<N; j++)
		{
			cin >> MAP[i][j];
		}
	}
}

// void bfs(int a)
// {
// 	q.push(a);
// 	while(!q.empty())
// 	{
// 		int cur = q.front();
// 		q.pop();
// 		for(int i = 0; i<N; i++)
// 		{
// 			if(MAP[cur][i] == 1 && !bvis[i])
// 			{
// 				q.push(i);
// 				bvis[i] = true;
// 				Answer[a][i] = 1;
// 			}
// 		}
// 	}
// }

void dfs(int point, int x, int y)
{
	dvis[point][y] = true;
	Answer[point][y] = 1;

	for(int  i= 0; i <N; i++)
	{
		if(dvis[point][i] == false && MAP[y][i] == 1)
			dfs(point,y,i);
	}

}

void Solution()
{
	for(int  i = 0; i<N ; i++)
	{
		for(int j = 0; j < N ; j++)
		{
			if(dvis[i][j] == false && MAP[i][j] == 1)
				dfs(i,i,j);
		}
	}

	// for(int i = 0; i<N; i++)
	// {
	// 	bfs(i);
	// 	memset(bvis, false, sizeof(bvis));
	// }

	for(int i = 0; i<N; i++)
	{
		for(int j= 0; j<N; j++)
		{
			cout << Answer[i][j]<< " ";
		}
		cout << endl;
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


// void dfs(int x, int y)
// {
//     if(!rchk[idx][y]) rchk[idx][y] = true;
//     if(chk[x][y]) chk[x][y] = true;
//     for(int i = 0; i<v[x].size(); i++)
//     {
//         if(chk[x][v[y][i]]) continue;
//         dfs(y,v[y][i]]);
//     } 
// }

// 아하 그래프도 인접행렬 식으로 받아올수있구나 
// 조건물을 사용하여서 조건에 해당하는 글자 혹은 문자일때 
// 이중포문을 설정하여 i번째에 j가 연결된 형태로 표현이 
// 가능하다는걸 알게 되었다. 

// 그리고 

// dfs에서 인덱스를 저런식으로 받고 나서 chk[x][v[y][i]]
// 식으로 인덱스를 받는다면 2차원배열에서 i,j검사중에
// j에 해당하는 인덱스의 (j+1,k)의검사가 가능하겠구나
// 사이클 형식의 review가 가능한것이었어 그렇구나

// scanf("%d", &n);

// memset

// for(i,1,n+1)
// {
//     for(j,1,n+1)
//     {
//         scanf("%d", &d);
//         if(d==1) v[i].push_back(j);
//     }
// }


// for(i,1,n+1)
// {
//     for(j,1,n+1)
//     {
//         memset(chk,false, sizeof(chk));
//         idx= i;
//         dfs(i, v[i][j]);
//     }
// }