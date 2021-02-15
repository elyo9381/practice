#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;
#define INF 987654321
#define hash 1000000007LL
typedef long long ll;
typedef pair<int,int> pii;
const int MAX = 51;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};

int r,c,t,cnt = 0;
int board[MAX][MAX];
int Cboard[MAX][MAX];

vector<pii> air;

void Copy_Board(int A[][MAX], int B[][MAX]){
    for(int i = 0; i<r; i++){
        for(int j = 0; j<c; j++){
            A[i][j] = B[i][j];
        }
    }
}

void expansion(){

    Copy_Board(Cboard,board);
    for(int i = 0; i<r; i++){
        for(int j = 0; j<c; j++){
            if(board[i][j] != 0 && board[i][j] != -1){
                int cnt = 0;
                int value = board[i][j] /5;

                for(int k = 0; k < 4; k++){
                    int nx = i + dx[k];
                    int ny = j + dy[k];

                    if(nx >=0 && ny >=0 && nx <r  && ny < c){
                        if(board[nx][ny] != -1){
                            Cboard[nx][ny] = Cboard[nx][ny] + value; 
                            cnt++;
                        }
                    }
                }
                Cboard[i][j] = Cboard[i][j] - (cnt * value);
            }
        }
    }

    Copy_Board(board,Cboard);
}

void airManage(){

    for(int idx = 0; idx<air.size(); idx++){

        if(idx == 0){
            for(int i = air[idx].first-1; i>0; i--){
                board[i][0] = board[i-1][0];
            }
            for(int i = 0; i<c-1 ; i++){
                board[0][i] = board[0][i+1];
            }

            for(int i = 1 ; i<=air[idx].first; i++){
                board[i-1][c-1] = board[i][c-1];
            }

            for(int i = c-1; i>1 ;i--){
                board[air[idx].first][i] = board[air[idx].first][i-1];
            }
            board[air[idx].first][1] = 0;
        }
        else {

            for(int i = air[idx].first+1; i < r-1 ; i++){
                board[i][0] = board[i+1][0];
            }
            for(int i = 0 ; i<c-1 ;i++){
                board[r-1][i] = board[r-1][i+1];
            }
            for(int i = r-1; i >= air[idx].first; i--){
                board[i][c-1] = board[i-1][c-1];              
            }
            for(int i = c-1; i>1; i--){
                board[air[idx].first][i] = board[air[idx].first][i-1];
            }

            board[air[idx].first][1] = 0;
        }
    }
}


int main(){

    cin >> r >> c >> t;

    for(int i = 0; i<r ;i++){
        for(int j = 0; j<c; j++){
            cin >> board[i][j];
            if(board[i][j] == -1){
                air.push_back(make_pair(i,j));
            }
        }
    }

    int sum = 0;
    while(1){

        if(cnt >= t) break;

        expansion();

        airManage();
        cnt++;   

    }

    for(int i = 0; i<r; i++){
        for(int j =0 ; j<c; j++){
            if(board[i][j] == -1) continue;
            sum += board[i][j];
        }
    }

    cout << sum << "\n";

    return 0;
}