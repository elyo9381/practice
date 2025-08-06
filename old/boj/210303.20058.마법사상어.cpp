#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

struct FIREBALL{
    int y,x;
    int m,s,d;
}

const int dy = {-1,-1,0,1,1,1,0,-1};
const int dx = {0,1,1,1,0,-1,-1,-1};

int N, M , K;

vector<FIREBALL> ball;
vector<int> map[50][50];

void move(){
    vector<int> newMap[50][50];
    for(int i = 0; i< ball.size(); i++){
        int dir = ball[i].d;
        int speed = (ball[i].s % N);
        int ny = (ball[i].y + (dy[dir] * speed) + N ) % N;
        int nx = (ball[i].x + (dx[dir] * speed) + N ) % N;
        newMap[ny][nx].push_back(i);
        ball[i].y = ny;
        ball[i].x = nx;
    }

    for(int y= 0; y<N; y++){
        for(int x = 0; x<N; x++){
            map[y][x] = newMap[y][x];
        }
    }
}

void sum(){
    vector<FIREBALL> newBall;
    for(int y = 0; y<N; y++){
        for(int x = 0;  x<N; x++){
            if(map[y][x].size() == 0){
                continue;
            }
            if(map[y][x].size() == 1){
                int idx = map[y][x][0];
                newBall.push_back(ball[idx]);
                continue;
            }

            int sum_m = 0, sum_s = 0;
            bool odd = true, even = true;
            for(int i = 0; i<map[y][x].size(); i++){
                int idx = map[y][x][i];
                sum_m += ball[idx].m;
                sum_s += ball[idx].s;
                if(ball[idx].d % 2 == 0){
                    odd = false;
                }
                else {
                    even = false;
                }
            }

            if(sum_m/5 == 0){
                continue;
            }

            int cur_m = sum_m/5;
            int cur_s = sum_s/map[y][x].size();
            for(int i = 0; i<4; i++){
                if(odd || even){
                    newBall.push_back({y,x,cur_m,cur_s,i*2});
                }
                else {
                    newBall.push_back({y,x,cur_m,cur_s,i*2+1});
                }
            }
        }
    }

    ball=newBall;
}

int solve(){

    while(K--){

    move();
    sum();
    }

    int ans = 0;

    for(int i = 0; i<ball.size(); i++){
        ans += ball[i].m;
    }

    return ans;
}

int main(){

    cin >> N >> M >> K;
    for(int i = 0; i<M; i++){
        int y,x,m,s,d;
        cin >> y >> x >> m >> s >>d;
        --y,--x;
        ball.push_back({y,x,m,s,d});
        map[y][x].push_back(i);
    }

    int ret = solve();
    cout << ret ;
    return 0;
}