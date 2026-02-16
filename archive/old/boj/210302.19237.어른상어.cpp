#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;
/**
 *  - 상어가 사는 공간에 더이상 물고기는 오지 않는다. - 다른상어..?
 *  - 상어는 1이상 m 이하의 자연수 번호가 붙어있고 모든번호는 서로 다름
 *  - 1의 번로를 가진 상어는 가장 강력해서 모두 쫓아낼수있다.
 *  - 상어는 상하좌우로 인접한 칸중 하나로 이동하고 자신의 냄새를 그칸에 뿌린다
 *  - 냄새는 상어가 k번 이동하고 나면 사라진다.
 * 
 *  방향결정은 인접한 칸중 냄새가 없는 칸으로 방향을 잡는다.
 *  else 자신의 냄새가 있는 칸의 방향으로 잡는다. 
 *  여러개 일때는 특정한 우선순위 ?? 
 * 
 *  상어의 방향은 입력으로 주어진다.
 * 
 *  모든 상어가 이동한 후 한 칸에 여러마리의 상어가 남아있으면, 가장작은 번호를 가진 상어를 제외하고 모두
 *  격자 밖으로 쫓겨난다. 
 * 
 * 상어가 보드 한 칸에 여러마리 존재할때를 접근도 하지 못햇는데 가장낮은 상어부터 움직이고 
 * 추후에 다른상어가 같은곳을 방문하면 이를 한칸에 여러마리가 존재한다고 생각한다. 
 * 
 */

const int dy[4] = { -1 , +1 , 0, 0};
const int dx[4] = {0, 0, -1, +1};

struct SHARK{
    int y,x,d;
    int priority[4][4];
};

int N, M , K, ret;

int board[20][20][3];
int newBoard[20][20][3];
SHARK shark[400];

void solve(){
    int time = 0;
    int kill_shark = 0;

    // K의범위가 1000이므로 1000번 동안 실행
    while(time <= 1000){
        ++time;

        memset(newBoard,0,sizeof(newBoard));


        /*
            newBoard를 통해서 상어의 이동을 체크한다. 
            그리고 우선순위 및 이동조건을 확인 및 비교하는것은 기존board와 비교하여 
            newBoard에 이동을 작성

            마지막에 다시 board에 newBoard를 복사한다. 
        */
        for(int y = 0; y < N ;  ++y){
            for(int x = 0; x < N; ++x){
                newBoard[y][x][0] = board[y][x][0];
                newBoard[y][x][2] = board[y][x][2];
                if(newBoard[y][x][2]> 0) {
                    --newBoard[y][x][2];
                }
                if(newBoard[y][x][2] > 0){
                    newBoard[y][x][1] = board[y][x][1];
                }
            }
        }


        for(int i = 0; i<M; i++){
            int cy = shark[i].y;
            int cx = shark[i].x;
            int cd = shark[i].d;

            // 잡아먹힌 상어를 의미함
            if(cy == -1){
                continue;
            }

            // move가능성
            bool is_move = false;
            
            // 빈칸이 존재할때 사방위에 냄새가 없을때
            for(int d = 0; d<4; d++){
                int nd = shark[i].priority[cd][d];
                int ny = cy + dy[nd];
                int nx = cx + dx[nd];
                if(ny < 0 || nx < 0 || ny >= N || nx >= N || board[ny][nx][2] != 0){
                    continue;
                }
                is_move = true;

                newBoard[cy][cx][0] = 0;
                if( newBoard[ny][nx][0] == 0){
                    newBoard[ny][nx][0] = i+1;
                    newBoard[ny][nx][1] = i+1;
                    newBoard[ny][nx][2] = K;

                    shark[i].y = ny;
                    shark[i].x = nx;
                    shark[i].d = nd;
                }
                else {
                    ++kill_shark;
                    shark[i].y = -1;
                }
                break;
            }

            // 사방위에 냄새가 있어 move하지 못할때
            if(is_move == false){
                    for(int d = 0; d<4; d++){
                        int nd = shark[i].priority[cd][d];
                        int ny = cy + dy[nd];
                        int nx = cx + dx[nd];
                        if(ny < 0 || nx < 0 || ny >= N || nx >= N ){
                            continue;
                        }

                        if(board[ny][nx][2] !=0 && board[ny][nx][1] != i+1){
                            continue;
                        }
                        newBoard[cy][cx][0] = 0;
                        if( newBoard[ny][nx][0] == 0){
                            newBoard[ny][nx][0] = i+1;
                            newBoard[ny][nx][1] = i+1;
                            newBoard[ny][nx][2] = K;

                            shark[i].y = ny;
                            shark[i].x = nx;
                            shark[i].d = nd;
                        }
                        else {
                            ++kill_shark;
                            shark[i].y = -1;
                        }
                        break;
                    }
            }
        }

        if(kill_shark == M-1){
            break;
        }

        for(int y = 0; y< N ; ++y){
            for(int x = 0 ; x< N ; x++){
                board[y][x][0] = newBoard[y][x][0];
                board[y][x][1] = newBoard[y][x][1];
                board[y][x][2] = newBoard[y][x][2];

            }
        }

    }

    //만약 1000번이 지났다면 상어가 남아있는것이므로 변수를 건들지 않는다.
    // 그리고 time이 천이하이면 현재의 시간을 ret에 넣는다. 
    if( time <= 1000){
        ret = time;
    }
}

int main(){
    cin >> N >> M >> K;

    /*
    상어와 보드에 어떤정보가 들어갈지 입력을 정의한다. 
    상어는 구조체로 x,y,d,priority[][]를 가진다.
    보드는 상어번호,냄새주인번호,냄새변수를가진다. 
    */
    for(int y = 0; y < N; ++y){
        for(int x = 0; x< N; x++){
            cin >> board[y][x][0];
            if(board[y][x][0] !=0){
                int shark_number = board[y][x][0] - 1;
                shark[shark_number].y = y;
                shark[shark_number].x = x;
                board[y][x][1] = board[y][x][0];
                board[y][x][2] = K;
            }
        }
    }

    // 방향에 의해서 여러 우선순위가 존재하므로 상어마다 우선순위를 체크하며 방향을 지시한다. 
    for(int i = 0; i<M; i++){
        cin >> shark[i].d;
        --shark[i].d;
    }

    for(int i = 0; i< M; i++){
        for(int d = 0; d < 4; ++d){
            cin >> shark[i].priority[d][0] >> shark[i].priority[d][1] >> shark[i].priority[d][2] >> shark[i].priority[d][3];
            --shark[i].priority[d][0];
            --shark[i].priority[d][1];
            --shark[i].priority[d][2];
            --shark[i].priority[d][3];

        }
    }

    ret = -1;
    solve();
    cout << ret ;
    return  0;
}
