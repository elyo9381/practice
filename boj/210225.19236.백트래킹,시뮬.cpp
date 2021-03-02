#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int ret;
/*
 인덱스 배열과 인포메이션 배열을 이용한 정보 표현방법을 사용함 !!
*/
struct FISH {
    int y , x;
    int dir;
};

const int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dx[8] = { 0, -1, -1, -1, 0 , 1, 1, 1};

void solve(int board[4][4], FISH fish[], int shark_y, int  shark_x, int sum){
    int candiBoard[4][4];
    FISH candiFish[16];
    for(int y = 0; y < 4; y++){
        for(int x = 0; x < 4; x++){
            candiBoard[y][x] = board[y][x];
        }
    }

    for(int i = 0; i < 16; i++){
        candiFish[i] = fish[i];
    }

    //eat
    int fishNumber = candiBoard[shark_y][shark_x];
    int sharkDir = candiFish[fishNumber].dir;
    candiFish[fishNumber].y = -1;
    candiFish[fishNumber].x = -1;
    candiFish[fishNumber].dir = -1;
    candiBoard[shark_y][shark_x] = -1;

    sum += (fishNumber +1);
    if(ret < sum) {
        ret = sum;
    }

    //fish move
    for(int f = 0; f < 16; ++f){
        if(candiFish[f].y == -1) {
            continue;
        }

        int cy = candiFish[f].y;
        int cx = candiFish[f].x;
        int cd = candiFish[f].dir;

        int ny = cy + dy[cd];
        int nx = cx + dx[cd];
        int nd = cd;

        // 범위 벗어났을때 왼쪽 45도 rotation
        while( ny < 0 || ny >= 4 || nx < 0 || nx >=4 || (ny == shark_y && nx == shark_x)) {
            nd = (nd + 1) % 8;
            ny = cy + dy[nd];
            nx = cx + dx[nd];
        }

        // !(상어를 만났을때 && 빈칸을 만남)
        if(candiBoard[ny][nx] != -1){
            int target = candiBoard[ny][nx];
            candiFish[target].y = cy;
            candiFish[target].x = cx;
            candiFish[f].y = ny;
            candiFish[f].x = nx;
            candiFish[f].dir = nd;

            candiBoard[ny][nx] = f;
            candiBoard[cy][cx] = target;
        } 
        else { // 빈칸을 만나면 빈칸에 물고기를 이동시킨다.
            candiFish[f].y = ny;
            candiFish[f].x = nx;
            candiFish[f].dir = nd;

            candiBoard[ny][nx] = f;
            candiBoard[cy][cx] = -1;
        }
    }

    // shark move 
    for(int step = 1; step < 4; ++step){
        int ny = shark_y + dy[sharkDir] * step;
        int nx = shark_x + dx[sharkDir] * step;
        if(ny < 0 || ny >=4 || nx < 0 || nx >=4) {
            break;
        }
        if(candiBoard[nx][ny] != -1) {
            solve(candiBoard, candiFish,ny,nx,sum);
        }
    }

}


int main(){

    // 인덱스를 활용한 보드와 객체의 정보를 내포하는 fish 배열이 존재한다. 
    FISH fish[16];
    int board[4][4];

    for(int y = 0; y<4; y++){
        for(int x = 0; x< 4; ++x){
            int a, b;
            cin >> a >> b;
            --a, --b;
            fish[a].y = y;
            fish[a].x = x;
            fish[a].dir = b;
            board[y][x] = a;
        }
    }

    ret = 0;
    solve(board, fish, 0, 0, 0);
    cout << ret << "\n";


   
}