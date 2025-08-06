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

int r,c,k , ans = 0;
int MAP[MAX][MAX];
int Number_Cnt[MAX];

void Find(){

    int Time = 0;
    int R = 3;
    int C = 3;

    while(1){
        if(MAP[r][c] == k){ ans = Time ; break;}
        if(Time > 100) { ans = -1; break;}


        // 배열에서 가장 긴 배열을 찾기 위한 백터
        vector<int> Size;
        if(R >= C) {

            // 2차원 배열에서 ROW만큼 탐색
            for(int i = 1; i<= R; i++){
                // 카운트한 횟수와 수를 pair에 저장
                vector<pair<int,int> > v;
                // 카운트 백터 여러번 사용하므로 초기화
                memset(Number_Cnt,0,sizeof(Number_Cnt));
                // 카운트를 한다.
                for(int j = 1; j<=C; j++){
                    Number_Cnt[MAP[i][j]]++;
                } 

                // 카운터 백터에서 0이 아닐때 pair에 저장
                for(int j = 1; j< MAX; j++){
                    if(Number_Cnt[j] ==0) continue;
                    v.push_back(make_pair(Number_Cnt[j],j));
                }

                // 정렬하는데 횟수,수 이거나 수,횟수이거나 같다 
                // 순서는 같으나 퍼스트, 세컨드가 다른것이다.
                sort(v.begin(), v.end());
                // 해당 ROW를 0 으로 셋팅 
                // why? 원래 긴 배열이 존재하다가 짧은 배열이 올수도 있으므로 
                // 그전에 데이터를 모두 지우기 위해 
                for(int j = 1; j<= C; j++) MAP[i][j] = 0;
                
                // 인덱스를 설정하여 piar백터의 값을 MAP에 저장한다. 
                // 인덱스가 삽입한 배열의 길이가 된다. 
                int Idx = 1;
                for(int j = 0; j< v.size(); j++){
                    MAP[i][Idx++] = v[j].second;
                    MAP[i][Idx++] = v[j].first;
                }
                Idx--;
                Size.push_back(Idx);
            }
            // 정렬해서 가장 긴 삽입 배열의 길이를 반환
            sort(Size.begin(), Size.end());
            C = Size.back();
        } else {
            for(int i =1; i<=C; i++){
                vector<pair<int,int> > v;
                memset(Number_Cnt, 0 , sizeof(Number_Cnt));
                 for(int j = 1; j<=R; j++){
                    Number_Cnt[MAP[j][i]]++;
                } 
                for(int j = 1; j<MAX ; j++){
                    if(Number_Cnt[j] != 0){
                        v.push_back(make_pair(Number_Cnt[j],j));
                    }
                }
                sort(v.begin(),v.end());
                for(int j = 1; j<=R; j++) MAP[j][i] = 0;
                int Idx = 1;
                for(int j = 0; j<v.size(); j++){
                    MAP[Idx++][i] = v[j].second;
                    MAP[Idx++][i] = v[j].first;
                }
                Idx--;
                Size.push_back(Idx);
            }
            sort(Size.begin(), Size.end());
            R = Size.back();
        }
        Time +=1;
    }
}


int main(){

    cin >>  r >> c >> k;

    for(int i = 1 ; i<=3; i++){
        for(int j = 1; j<=3; j++){
            cin >> MAP[i][j];
        }
    }


    if(MAP[r][c] == k){
        ans = 0;
        cout << ans << '\n';
        return 0;
    }

    Find();
    cout << ans <<'\n';

}