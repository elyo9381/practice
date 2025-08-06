#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

/**
 * 
 * 조건
 * 1 배치된 말중 임의의 2개의 말을 골라 서로의 위치를 바꾼다.
 * 2 말 1개를들어 뒤집어 놓아 색상을 변경한다. 
 * 
 * 목표상태에 도달하는 최소횟수
 * 
 * 설계
 * 인접한 WB를 바꿔주는 방향으로 설계했는데 fail
 * 임의의 2개이다. 바꿔야한다.
 * 
 * debug
 * 임의의2개를 어떻게 바꿀것인가? W/B, B/W의 갯수를 셌다.
 * W/B , B/W가 하나씩 존재해야 1번조건을 사용할수있기 때문이다. 
 * 그렇기 때문에 각각 1개가 있다면 1번조건을 사용할수있는것으로 판단하고
 * 2,1씩으로 상대적으로 갯수가 많다는것은 1번과 2번 조건이 사용된다는 의미이다.
 * 
 *
*/


int main(){
    
    int n,t;

    cin >> t;

    while(t--){
        cin >> n;
        string it,ot;
        cin >> it >> ot;
        int cnt1 = 0, cnt2 = 0;

        for(int i= 0; i<n ;i++){
            if(it[i] == ot[i]){
                continue;
            }
            if(it[i] == 'W'){
                if(it[i] != ot[i]){
                    cnt1++;
                }
            }
            if(it[i] =='B'){
                if(it[i] != ot[i]){
                    cnt2++;
                }
            }
        }
        int maxc = max(cnt1, cnt2);
        cout << maxc << "\n";
    }
}