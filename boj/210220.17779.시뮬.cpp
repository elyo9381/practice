#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;
#define INF 987654321
#define hash 1000000007LL
typedef long long ll;
typedef pair<int,int> pii;
const int MAX = 21;

int n, sum = 0;

int bo[MAX][MAX];
int ch[MAX][MAX];
int tmp[MAX][MAX];


int solve(int x ,int y,int d1, int d2){
    memset(tmp,0,sizeof(tmp));
    tmp[x][y] = 5;

    // 경계선 그려 넣기 
    // (x,y), (x+1,y-1), ...., (x+d1,y-d1)
    // (x + d2 , y + d2), ...., (x+d2+d1, y+ d2 -d1)
    for(int i = 1; i<=d1; i++){
        tmp[x + i][y - i] = 5;
        tmp[x + d2 + i][y + d2 - i] = 5;
    }

    // (x + d1 , y - d1), ...., (x + d1 + d2, y-d1 +d2)
    for(int i = 1; i<=d2 ; i++){
        tmp[x+i][y+i] = 5;
        tmp[x+d1+i][y-d1+i] = 5;
    }

    // 1선거구 : 1 ≤ r < x+d1, 1 ≤ c ≤ y
    int aa = 0;
    for(int r = 1; r < x +d1; ++r){
        for(int c =1; c<=y; ++c){
            if(tmp[r][c] == 5){
                break;
            }
            aa+=bo[r][c];
        }
    }

    // 2선거구 : 1 ≤ r ≤ x+d2, y < c ≤ N
    int bb = 0;
    for(int r = 1 ; r <= x+d2 ; ++r){
        for(int c = n; c > y; --c){
            if(tmp[r][c] == 5){
                break;
            }
            bb+=bo[r][c];
        }
    }

    // 3선거구 : x+d1 ≤ r ≤ N, 1 ≤ c < y-d1+d2
    int cc = 0;
    for(int r = x+d1 ; r<=n ; ++r){
        for(int c = 1; c < y - d1 +d2 ; ++c){
            if(tmp[r][c] == 5){
                break;
            }
            cc += bo[r][c];
        }
    }

    // 4번 선거구: x+d2 < r ≤ N, y-d1+d2 ≤ c ≤ N
    int dd = 0;
    for(int r = x + d2 + 1; r<=n; ++r){
        for(int c = n; c >= y - d1 +d2; --c){
            if(tmp[r][c] == 5){
                break;
            }
            dd += bo[r][c];
        }
    }

    int ee = sum - aa - bb -cc - dd;
    
    int maxValue = max(aa,max(bb,max(cc,max(dd,ee))));
    int minValue = min(aa,min(bb,min(cc,min(dd,ee))));
    return (maxValue - minValue);
}


int main(){

    cin >> n ;

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            cin >> bo[i][j];
            sum += bo[i][j];
        }
    }
    
    int ret = 0x7fffffff;
    for(int x = 1; x<=n; x++){
        for(int y = 1; y<=n; y++){
            for(int d1 = 1; d1 <= n; d1++){
                for(int d2 = 1; d2 <=n ; d2++){
                    if(x + d1 + d2 > n) continue;
                    if(1 > y - d1) continue;
                    if(y + d2 > n) continue;
                    ret = min(ret,solve(x,y,d1,d2));
                }
            }
        }
    }

    cout <<  ret << "\n";
}