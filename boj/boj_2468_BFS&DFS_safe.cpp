// #include <iostream>
// #include <cstring>
// #include <queue>
// #include <vector>


// #define endl "\n"
// #define MAX 100

// using namespace std;

// int N, Max_Height_Area, Answer, Num_Area;
// int MAP[MAX][MAX], C_MAP[MAX][MAX];
// bool Visit[MAX][MAX];

// int dx[] = {0,0,1,-1};
// int dy[] = {1,-1,0,0};

// vector<pair<int,int> > V;

// int max(int a,int b) { if(a>b) return a; return b;}

// void BFS(int a, int b)
// {
//     queue<pair<int,int> > Q;
//     Q.push(make_pair(a,b));
//     Visit[a][b] = true;
//     Num_Area++;

//     while(!Q.empty())
//     {
//         int x = Q.front().first;
//         int y = Q.front().second;
//         Q.pop();

//         for(int  i = 0; i<4; i++)
//         {
//             int nx = x+ dx[i];
//             int ny = y + dy[i];

//             if(nx >=0 && ny >= 0 && nx< N && ny< N)
//             {
//                 if(!Visit[nx][ny] && C_MAP[nx][ny] != 0)
//                 {
//                     Q.push(make_pair(nx,ny));
//                     Visit[nx][ny] = true;
//                 }
//             }
//         }
//     }
// }

// int main()
// {

//     cin >> N; 
    
//     Max_Height_Area = 0;
//     for(int i = 0; i<N; i++)
//     {
//         for(int j = 0 ; j<N;j++){
//             cin >> MAP[i][j];
//              if (MAP[i][j] > Max_Height_Area)   
//                 Max_Height_Area = MAP[i][j];

//             C_MAP[i][j] = MAP[i][j];
//         }
//     }

//     for(int H = 0; H< 100; H++)
//     {
//         Num_Area = 0;
//         V.clear();
//         memset(Visit, false,sizeof(Visit));
//         if(H > Max_Height_Area) break;

//         for(int i = 0; i< N; i++)
//         {
//             for(int  j = 0; j< N; j++)
//             {
//                 if( C_MAP[i][j] <= H) C_MAP[i][j] = 0;
//                 // else V.push_back(make_pair(i,j));
//             }
//         }

//         for(int i = 0; i<N; i++)
//         {
//             for(int j = 0; j<N; j++)
//             {
//                 if(!Visit[i][j] && C_MAP[i][j] != 0)
//                     BFS(i,j);
//             }
//         }

//         Answer = max(Answer, Num_Area);
//     }
//     cout << Answer <<endl;
    
//     return 0;
// }


#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX = 100;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int N;
int area[MAX][MAX];
int temp[MAX][MAX];

bool visit[MAX][MAX];
void copy(int depth)
{        for (int i = 0; i < N; i++)
                 for (int j = 0; j < N; j++)
                         if (area[i][j] > depth)
                                 temp[i][j] = area[i][j];
}


void DFS(int x, int y)
{
    visit[x][y] = true;

    for(int  i =0; i<4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx >=0 &&  ny >= 0 && nx < N && ny < N)
            if(!vis[nx][ny] && temp[nx][ny] != 0)
                DFS(nx,ny);
    }
}

int main()
{
    cin >> N;

    for(int  i =0; i<N; i++)
    {
        for(int  j = 0; j<N; j++)
        {
            cin > area[i][j];
        }
    }
    
    inretsult = 1;

    for(int depth =1; i<= MAX; depth++)
    {
        memset(visit,false, sizeof(visit));
        memset(temp, 0, sizeof(temp));

        copy(depth);

        int cnt = 0;

        for(int  i = 0; i< N; i++)
        {
            for(int j  = 0; j< N; j++)
            {
                if(!visit[i][j] && temp[i][j])

                {
                    DFS(i,j);
                    cnt++;
                }
            }
        }
        result = max(result,cnt);
    }
    cout << result <<endl;

}