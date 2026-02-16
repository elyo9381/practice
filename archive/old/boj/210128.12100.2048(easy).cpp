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
const int MAX = 1000001;

int board[21][21];
int n , maxBlock;

void shift(int type){
    queue<int> q;

    switch(type){
        case 0:
            for(int i = 0; i<n; i++){
                for(int j = 0; j<n; j++){
                    if(board[i][j])
                        q.push(board[i][j]);
                    board[i][j] = 0;
                }

                int idx = 0;
                while(!q.empty()){
                    int data = q.front();
                    q.pop();

                    if(board[i][idx] == 0)
                        board[i][idx] = data;
                    else if( board[i][idx] == data){
                        board[i][idx] *=2;
                        idx++;
                    } else{
                        idx++;
                        board[i][idx] = data;
                    }
                }
            }
            break;
        case 1:
            for(int i = 0; i<n; i++){
                for(int j = n-1; j>=0; j--){
                    if(board[i][j])
                        q.push(board[i][j]);
                    board[i][j] = 0;
                }

                int idx = n-1;
                while(!q.empty()){
                    int data = q.front();
                    q.pop();

                    if(board[i][idx] == 0)
                        board[i][idx] = data;
                    else if( board[i][idx] == data){
                        board[i][idx] *=2;
                        idx--;
                    } else{
                        idx--;
                        board[i][idx] = data;
                    }
                }
            }
            break;
        case 2:
            for(int i = 0; i<n; i++){
                for(int j = 0; j<n; j++){
                    if(board[j][i])
                        q.push(board[j][i]);
                    board[j][i] = 0;
                }

                int idx = 0;
                while(!q.empty()){
                    int data = q.front();
                    q.pop();

                    if(board[idx][i] == 0)
                        board[idx][i] = data;
                    else if( board[idx][i] == data){
                        board[idx][i] *=2;
                        idx++;
                    } else{
                        idx++;
                        board[idx][i] = data;
                    }
                }
            }
            break;
        case 3:
            for(int i = 0; i<n; i++){
                for(int j = n-1; j>=0; j--){
                    if(board[j][i])
                        q.push(board[j][i]);
                    board[j][i] = 0;
                }

                int idx = n-1;
                while(!q.empty()){
                    int data = q.front();
                    q.pop();

                    if(board[idx][i] == 0)
                        board[idx][i] = data;
                    else if( board[idx][i] == data){
                        board[idx][i] *=2;
                        idx--;
                    } else{
                        idx--;
                        board[idx][i] = data;
                    }
                }
            }
            break;
    }
}
void DFS(int L){
    if(L == 5){
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                maxBlock = max(maxBlock,board[i][j]);
            }
        }
		return;
    }

    int copyBoard[21][21];
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n ;j++){
            copyBoard[i][j] = board[i][j];
        }
    }

    for(int i = 0; i<4; i++){
        shift(i);
        DFS(L+1);
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n;j++){
                board[i][j] = copyBoard[i][j];
            }
        }
    }
}

int main(){
    cin >> n;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin >> board[i][j];;
        }
    }

    DFS(0);

    cout << maxBlock << '\n';
}