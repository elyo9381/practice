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
 * - 연속하는 20일중 10만 사용 가능
 * - 28휴가시작 
 * - 며칠동안 캠핑장 사용가능 한가?
 * 
 * - p일중, L일동안만 사용가능 , v일짜리 휴가 시작
 * ? 캠핑장 최대 며칠동안 사용가능 한가 ? 
 *  
 * 설계 
 * - 입력 
 * - p일중 L일 동안만 사용가능하니 사용하지 않는날을 구하여
 * - V일에서 사용하지 않는날을빼면 최대 사용가능 한 날이다. 
 * fail
 * 
 * debug
 * 5 8 15 의경우 10일 사용할수있는데 내코드는 12일 나옴
 * P-L을 해야하는것이 아니라 나머지연산으로 풀어야함
 * 
*/

int L,P,V, ret;

int main(){
    int idx = 0;

    while(1){
        idx++;
        cin >> L >> P >> V;
        if( L == 0 && P == 0 && V == 0) {    
            break;
        }

        int modDay = V%P;
        int maxDay = V/P;
        if(modDay >= L){
            ret = maxDay * L + L;
        }
        if(modDay < L){
            ret = maxDay * L + modDay;
        }

        cout << "Case " << idx << ": " << ret << "\n";

    }

}
