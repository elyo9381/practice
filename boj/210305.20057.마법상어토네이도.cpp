#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;


int N;
int A[500][500];

const int dy[]= {0,1,0,-1};
const int dx[]= {-1,0,1,0};
const int rat[9] = {1,1,2,7,7,2,10,10,5};

const int blowY[4][10]={
	{-1,1,-2,-1,1,2,-1,1,0,0},
	{-1,-1,0,0,0,0,1,1,2,1},
	{-1,1,-2,-1,1,2,-1,1,0,0},
	{1,1,0,0,0,0,-1,-1,-2,-1}
};
const int blowX[4][10]={
	{1,1,0,0,0,0,-1,-1,-2,-1},
	{-1,1,-2,-1,1,2,-1,1,0,0},
	{-1,-1,0,0,0,0,1,1,2,1},
	{-1,1,-2,-1,1,2,-1,1,0,0}
};

// (y,x)의 범위 표시하기 위함 함수
bool inRange(int y, int x){
    return y>=0 && x>=0 && y<N && x<N;
}


/**
 * 모래가 흐날리는것은 직접 값대입으로 하면 편하다. 
 * 반복적인 수가 아니므로 탐색할일이 없다.
 * 비율을 배열로 정의하고 같은 순서로 모래를 날린다. 
 * 이때 매번 범위를 체크하여 범위밖으로 날아간 모래의 합을 변수에 체크한다. 
 * 
*/
int blowSand(int y, int x ,int dir){
    if( y < 0 || x < 0) return 0;

    int ret = 0, init = A[y][x];

    for(int i = 0; i < 10 ; i++){
        int sand; 
        if(i != 9){
            sand = init*rat[i]/100;
            A[y][x] -= sand;
        }
        else sand = A[y][x];

        int by = y + blowY[dir%4][i];
        int bx = x + blowX[dir%4][i];

        if(!inRange(by,bx)){
            ret+=sand;
            continue;
        }
        
        A[by][bx] += sand;
    }

    A[y][x] = 0;

    return ret;
}


/**
 * 달팽이 모양으로 돌아야한다. 
 * 가운데에서부터 1씩 증가하고 2번반 복한다. 
 * 2번 반복하는 것은 double 0.5번 증가하는 것으로 진행하였고
 * 토네이도는 1씩 증가하는것은 i를 정수형으로 변환하거나 반내림하면 된다 
 * 
 * 방향은 서 남 동 북 방향을 반복한다. 
*/
int solve(){

    int ret = 0, y = N/2 , x = N/2, dir = 0;

    for(double i = 1.0; i <= N ; i+=0.5){
        for(int j = 0; j < (int)i; j++){
            y += dy[dir%4];
            x += dx[dir%4];

            ret += blowSand(y,x,dir);
        }
        dir++;
    }

    return ret++;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            cin >> A[i][j];
        }
    }

    cout << solve();

    return 0;

}