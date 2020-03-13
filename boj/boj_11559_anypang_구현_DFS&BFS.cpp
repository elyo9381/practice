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

/*
    
*/


char MAP[12][6];
bool visit[12][6];

int boom_cnt = 0;
int temp_cnt = 0;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

vector<pair<int, int> > Boom_tmp, Boom_vec;

void Input()
{
    for(int i  = 0; i<12; i++)
        for(int j =0; j<6; j++)
            cin >> MAP[i][j];
}

void DFS(int x, int y)
{
    for(int i =  0; i< 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >= 12 || ny >= 6) continue; //범위를 넘어갔다면
        if(MAP[nx][ny] == '.') continue; // 빈공간이라면 
        if(visit[nx][ny] == true) continue; // 방문하지 않았다면
        if(MAP[x][y] != MAP[nx][ny] ) continue; // 같은 색상이 아니면

        // 같은색상이면 같은색임의 cnt를 올린다.
        // 그리고  방문여부를 트루로한다.
        // Boom_tmp에는 같은 색상이 4개이상되면 터트려야하므로
        // 4개 이상인지 확인하기 위해서 Boom_tmp에 넣는다.  
        temp_cnt++; 
        visit[nx][ny] = true;
        Boom_tmp.push_back(make_pair(nx,ny));
        DFS(nx,ny);
    }
}
void Solution()
{  
   bool Flag;
   int Answer = 0;

   while(1)
   {
        Flag = false;
        memset(visit, false, sizeof(visit));
        Boom_vec.clear();

        for(int i = 0; i<12; i++)
        {
            for(int j =0; j< 6; j++)
            {
                if(MAP[i][j] != '.' && visit[i][j] == false)
                {
                    temp_cnt = 1;
                    Boom_tmp.push_back(make_pair(i,j));
                    visit[i][j] = true;
                    DFS(i,j);

                    if(temp_cnt >= 4)
                    {
                        Flag =  true; // 연쇄를 체크하는 Flag이다.

                        for(int i =0; i<Boom_tmp.size(); i++)
                        {
                            //Boom_vec는 4개이상된 색상을 터트리기 위해서 
                            // 다시 다른 배열에 넣고 Boom_tmp는 또 다른 색상을 찾기위해서
                            // 초기화 한다. 
                            Boom_vec.push_back(Boom_tmp[i]);
                        }
                    }
                    Boom_tmp.clear();
                }
            }
        }

        // 색이 있던곳에는 빈공간으로 표기하고 
        for(int i = 0; i<Boom_vec.size(); i++)
        {
            int x = Boom_vec[i].first;
            int y = Boom_vec[i].second;

            MAP[x][y] = '.';
        }

        // 아래서부터 정렬하면된다. 
        // 색상이 있을때 하나식 while(1)을통해서 하나식 내리면 된다.
        for(int i= 10; i>=0; i--)
        {
            for(int j = 0; j<6 ;j++)
            {
                if(MAP[i][j] =='.') continue;
                int tmp = i;

                while(1)
                {
                    if(tmp == 11 || MAP[tmp+1][j] != '.') break;
                    MAP[tmp+1][j] = MAP[tmp][j];
                    MAP[tmp][j] = '.';
                    tmp++;
                }
            }
        }

   if(Flag == true) Answer++; // Flag가 true이면 true가 된다. 
   else break;
}

cout << Answer << endl;

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


// char MAP[12][6];
// bool visit[12][6];


// int dx[] = {0,0,1,-1};
// int dy[] = {1,-1,0,0};


// void Input()
// {
//     for(int i = 0; i<12; i++)
//         scanf("%s",MAP[i]);
// }

// vector<pii> getColor(char color)
// {
//     vector<pii> vc;
//     for(int i = 0; i <12; i++)
//         for(int j = 0; j<6; j++)
//             if( MAP[i][j] == color)
//                 vc.push_back({i,j});

//     return vc;
// }

// bool bfs(char color, vector<pii> vc)
// {
//     queue<pii> q;
//     bool chk =  false;

//     for( int i =0; i< vc.size(); i++)
//     {
//         int x = vc[i].first;
//         int y = vc[i].second;

//         q.push({x,y});
//         int cnt = 0;
//         memset(visit, 0, sizeof(visit));

//         while(!q.empty())
//         {
//             int hx = q.front().first;
//             int hy = q.front().second;

//             q.pop();

//             if(visit[hx][hy])
//                 continue;

//             visit[hx][hy] = true;
//             cnt++;
//             for( int j = 0; j < 4; j++)
//             {
//                 int ny = hy + dy[j];
//                 int nx = hx + dx[j];

//            if ((0 <= ny && ny < 12 && (0 <= nx && nx < 12)) && MAP[nx][ny] == color)
//                     q.push({ nx,ny });

//             }
//         }

//         if( cnt >= 4)
//         {
//             for(int i = 0; i< 12; i++)
//                 for(int j =0; j< 6 ; j++)
//                     if(visit[i][j])
//                     {
//                         MAP[i][j] = '.';
//                         chk= true;
//                     }
//         }
//     }

//     if(chk)
//         return true;
//     else
//         return false;
// }

// void Solution()
// {  
//   int combo = 0;

//   while(1)
//   {
//     bool isEvent = false;

//     vector<pii> vcR = getColor('R');
//     vector<pii> vcG = getColor('G');
//     vector<pii> vcB = getColor('B');
//     vector<pii> vcP = getColor('P');
//     vector<pii> vcY = getColor('Y');

//     bool r = bfs('R', vcR);
//     bool g = bfs('G', vcG);
//     bool b = bfs('B', vcB);
//     bool p = bfs('P', vcP);
//     bool y = bfs('Y', vcY);

//     if(r || g || b || p || y)
//         isEvent = true;

//     if(isEvent)
//         combo++;
//     else
//         break;

//     //재정렬
//     for(int t = 0; t < 12; t++)
//         for(int i =0; i<12; i++)
//         {
//             for( int j = 0; j<6; j++)
//             {
//                 if( MAP[i][j] != '.' && MAP[i+1][j] =='.')
//                 {
//                     MAP[i+1][j] = MAP[i][j];
//                     MAP[i][j] = '.';
//                 }
//             }
//         }
//   }
//   cout << combo <<endl;
// }
