// #include <cstdio>
// #include <cstdlib>
// #include <iostream>
// #include <sstream>
// #include <algorithm>
// #include <string>
// #include <vector>
// #include <queue>

// using namespace std;
// #define INF 987654321
// #define hash 1000000007LL
// typedef long long ll;
// typedef pair<int,int> pii;
// const int MAX = 1001;


// struct CCTV{
//     int x,y,type;
// };

// int n,m, ans =1e9, map[8][8];
// int cctv_size = 0;

// CCTV cctv[8];

// const int rotation[] = {0,4,2,4,4,1};

// void map_cpy(int desc[8][8] , int src[8][8]){
//     for(int x = 0; x<n; x++){
//         for(int y = 0; y<m ; y++){
//             desc[x][y] = src[x][y];
//         }
//     }
// }


// void update(int dir, CCTV cctv){

//     dir %= 4;

//     if(dir == 0){ // 동
//         for(int y = cctv.y+1 ; y < m; ++y){
//             if(map[cctv.x][y] == 6) break;
//             map[cctv.x][y] = -1;
//         }
//     } else if(dir == 1){ // 북
//         for(int x = cctv.x-1 ; x >= 0; --x){
//             if(map[x][cctv.y] == 6) break;
//             map[x][cctv.y] = -1;
//         }
//     } else if(dir == 2){ // 서
//         for(int y = cctv.y-1 ; y >= 0; --y){
//             if(map[cctv.x][y] == 6) break;
//             map[cctv.x][y] = -1;
//         }
//     } else if(dir == 3){ // 남
//         for(int x = cctv.x+1 ; x < n; ++x){
//             if(map[x][cctv.y] == 6) break;
//             map[x][cctv.y] = -1;
//         }
//     }
// }


// void dfs(int cctv_idx){
//     if(cctv_idx == cctv_size){
//         int cnt = 0;
//         for(int i = 0; i<n; i++){
//             for(int j = 0; j<m; j++){
//                 if(map[i][j] == 0)
//                     cnt++;
//             }
//         }
//         if(ans > cnt) ans = cnt;
//         return;
//     }
//     int backup[8][8];
//     int type = cctv[cctv_idx].type;

//     for(int i = 0; i < rotation[type]; i++){
//         map_cpy(backup,map);

//         if(type == 1){
//             update(i,cctv[cctv_idx]);
//         }
//         else if(type == 2){
//             update(i,cctv[cctv_idx]);
//             update(i+2,cctv[cctv_idx]);
//         }
//         else if(type == 3){
//             update(i,cctv[cctv_idx]);
//             update(i+1,cctv[cctv_idx]);
//         }
//         else if(type == 4){
//             update(i,cctv[cctv_idx]);
//             update(i+1,cctv[cctv_idx]);
//             update(i+2,cctv[cctv_idx]);
//         }
//         else if(type == 5){
//             update(i,cctv[cctv_idx]);
//             update(i+1,cctv[cctv_idx]);
//             update(i+2,cctv[cctv_idx]);
//             update(i+3,cctv[cctv_idx]);

//         }

//         dfs(cctv_idx+1);

//         map_cpy(map,backup);
//     }
// }

// int main(){

//     ios::sync_with_stdio(false);
//     cin.tie(0); cout.tie(0);

//     cin >> n >> m;

//     for(int i = 0 ; i<n; i++){
//         for(int j = 0; j < m; j++){
//             cin >> map[i][j];
//             if(map[i][j] != 0 &&  map[i][j] !=6){
//                 cctv[cctv_size].x = i;
//                 cctv[cctv_size].y = j;
//                 cctv[cctv_size].type = map[i][j];
//                 ++cctv_size;
//             }
//         }
//     }

//     dfs(0);
//     cout << ans << "\n";

// }


#include <iostream>

using namespace std;

int dr[4] = {-1,0,1,0};
int dc[4] = {0,1,0,-1};

int csize[6] = {0,4,2,4,4,1};
int camera[6][4] = {{},{0},{1,3},{0,1},{0,1,3},{0,1,2,3}};
int dcnt[6] = {0,1,2,2,3,4};

int map[8][8] ,n,m;
int MIN(int i1,int i2){return i1<i2 ? i1: i2;}
int getNum(){
    int res = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m;j++){
            res +=map[i][j] == 0;
        }
    }
    return res;
}

int dfs(int r, int c){
    if(r==n) return getNum();

    int next[2] = {r,c+1};
    if(next[1] == m){
        next[0]++;
        next[1] = 0;
    }
    int res = 0x3f3f3f3f;

    if(map[r][c] > 0 && map[r][c] !=6){
        int ca = map[r][c];

        for(int rot = 0; rot < csize[ca]; rot++){
            
            // map에 채우고 
            for(int d = 0; d< dcnt[ca]; d++){
                int p[2] = {r,c};
                int dir = (rot + camera[ca][d])%4;

                while(p[0] < n && p[1] <m && p[0] >=0 && p[1] >=0){
                    if(map[p[0]][p[1]] == 6) break;

                    if(map[p[0]][p[1]] <= 0)
                        map[p[0]][p[1]]--;

                    p[0] += dr[dir];
                    p[1] += dc[dir];
                }
            }

            res = MIN(res, dfs(next[0],next[1]));

            // map 원상복구
            for(int d = 0; d < dcnt[ca]; d++){
                int p[2] = {r,c};
                int dir = (rot + camera[ca][d]) %4;

                while(p[0] >= 0 && p[1] >=0 && p[0] <n &&p[1] <m ){
                    if(map[p[0]][p[1]] == 6) break;

                    if(map[p[0]][p[1]] <= 0)
                        map[p[0]][p[1]]++;

                    p[0] += dr[dir];
                    p[1] += dc[dir];
                    
                }
            }
        }
    }else{
        res = dfs(next[0], next[1]);
    }
    return res;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> map[i][j];
        }
    }
    cout << dfs(0,0);

    return 0;
}