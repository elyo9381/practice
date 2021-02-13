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
const int MAX = 11;

int n,m,K, cnt = 0;
int board[MAX][MAX];
int addboard[MAX][MAX];

vector<int> wboard[MAX][MAX];

int dx[] = {-1,-1,-1,0,0,1,1,1};
int dy[] = {-1,0,1,-1,1,-1,0,1};

int main(){

    cin >> n >> m >> K;

    // board를 입력받는다. 
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            cin >> addboard[i][j];
            board[i][j] = 5;
        }
    }

    // board 한칸에 여러개의 나무가 올수있어서 
    // 2차원 인접리스트를 설정하였다. >> vector<int> wboard[MAX][MAX];
    for(int i= 1 ; i<=m; i++){
        int a,b,c;
        cin >> a>>b>>c;
        wboard[a][b].push_back(c);
    }


    // k번동안 진행
    while(1)
    {
        if(cnt>=K) break;
        //봄&여름
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=n ; j++){
                // wboard를 2차원 인접리스트로 설정하여서 값이 없을때는 패스해야됨
                if(wboard[i][j].size() == 0) continue;
                
                int DieWoodNutrition = 0;
                vector<int> Temp;

                // 가장 작은 나이부터 시작하길 원하는 정렬
                sort(wboard[i][j].begin(),wboard[i][j].end());

                for(int k = 0; k < wboard[i][j].size(); k++){
                    int Age = wboard[i][j][k];

                    if(board[i][j] >= Age){
                        // board에서 나이만큼 뺌
                        board[i][j] = board[i][j] - Age;
                        Temp.push_back(Age+1);
                    } else {
                        // board에서 빼지 못 하므로 죽은 나무로 판명
                        DieWoodNutrition = DieWoodNutrition + (Age/2);
                    }
                }

                // 나무들의 나이가 업데이트 되고 업데이트 되지 못한 나무도 있으므로 
                // 초기화 시키고 다시 저장
                wboard[i][j].clear();
                for(int k = 0; k<Temp.size(); k++){
                    wboard[i][j].push_back(Temp[k]);
                }
                // 죽은 나무들의 양분을 저장 
                board[i][j] += DieWoodNutrition;
            }
        }

        // 가을
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=n; j++){
                if(wboard[i][j].size() == 0) continue;
                for(int k = 0; k < wboard[i][j].size(); k++){
                    int Age = wboard[i][j][k];

                    if(Age % 5 == 0){
                        for(int a = 0; a<8; a++){
                            int nx = i +dx[a];
                            int ny = j +dy[a];

                            if(nx <0 || ny <0 || nx >=n || ny >=n ) continue;
                            wboard[nx][ny].push_back(1);
                        }
                    }
                }
            }
        }
        // 겨울

        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=n; j++){
                board[i][j] += addboard[i][j];
            }
        }

        cnt++;
    }
    int ans = 0;

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            ans += wboard[i][j].size();
        }
    }

    cout << ans <<"\n";
}