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
const int MAX = 101;

const int dx[] = {0,-1,0,1};
const int dy[] = {1,0,-1,0};

int end_x, end_y;
int n,x,y,d,g,ret;

bool board[MAX][MAX];

vector<int> dragon;


// 세대를 표현하기 위한 함수 
void dragon(vector<int> &v){

    int len = v.size();
    
    for(int i =len -1; i>=0; i--){
        int dir = (v[i] + 1 )%4;

        end_x += dx[dir];
        end_y += dy[dir];

        board[end_x][end_y] = true;

        v.push_back(dir);
    }
}


int main(){

    cin >> n;

    for(int i = 0 ;i<n; i++){
        cin >> y >> x >> d >>g;

        // i번째마다 새로운 드래곤커브를 입력받으므로 초기화
        dragon.clear();

        // 최초 받은 d 방향을 기준으로 x,y 초기 끝점 설정
        end_x = x + dx[d];
        end_y = y + dy[d];

        board[end_x][end_y] = true;

        //  g-1세대를 표현하기위한 백터
        dragon.push_back(d);

        // 세대별 루프 
        for(int i = 0; i<g; i++){
            make_generation(dragon);
        }
    }


    // 배열 탐색
    for(int i = 0; i<100; i++){
        for(int j = 0; j<100; j++){
            if(board[i][j] && board[i][j+1]&& board[i+1][j]&& board[i+1][j+1])
                ret++;
        }
    }

    cout << ret << "\n";
}
