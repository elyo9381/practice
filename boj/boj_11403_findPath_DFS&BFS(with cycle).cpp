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
		if(dvis[point][i] == false && MAP[y][i] ==1)
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


