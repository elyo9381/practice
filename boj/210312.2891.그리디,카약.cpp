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
 * 
 * 조건
 * - 일부팀은 카약을 하나더 경기장에들고옴
 * - 자신 바로 다음이나 전 팀만 카약 빌려줌
 * - 원래 카약이 손상되었다면, 여분의 카약으로 경기출전이고 
 *   이 카약을 다른팀에게 대여 못함
 * 
 * 설계 
 * - 입력 N,S,R 
 * N 팀의수, S 카약이 손상된 팀의수, R 카약을 하나더 가져온팀의수
 * 
 * 고장난 배 양쪽 옆에 여분이 있다면 누가줄것인지 로직을 정해야한다. 
 * 이때 한쪽만 정하는것이 좋다.
 * 1은 왼쪽이 없으므로 순차적으로 오른쪽에서 여분을 가져다 쓰고 여분을 삭제한다.
 * 
*/

int N,S,R,ret = 0;

bool shipBreak[11];
bool anotherShip[11];

int main(){

    cin >> N >> S >> R;

    for(int i = 1; i<=S; i++){
        int ship;
        cin >> ship;
        shipBreak[ship] = true;
    }

    for(int i = 1; i<=R; i++){
        int ship;
        cin >> ship;
        anotherShip[ship] = true;
    }

    for(int i = 1; i<=N; i++){
        if(shipBreak[i] && anotherShip[i-1]) shipBreak[i] = false;
        if(shipBreak[i] && anotherShip[i+1]){
            shipBreak[i] = false;
            anotherShip[i+1] = false;
        }
    }
    int res = 0;
    for(int i = 1; i<=N; i++){
        if(shipBreak[i]){
            res +=1; 
        }
    }

    cout << res ;


}