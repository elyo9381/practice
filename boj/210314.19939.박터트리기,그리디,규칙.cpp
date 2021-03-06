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
 * N개의 공 K 개의 바구니 나눠 담는다.
 * 
 * N의 공을 K개의 바구니에 빠짐없이 나누어 담는데, 
 * 최소 하나의 공이 있어야한다. 바구니는 공의개수가 달라야한다. << 가장 중요한 조건 
 * N개의 공을 K개의 바구니에 빠짐없이 나누어 담아야한다.
 * 각바구니엔 하나 이상 공이 있어야하고, 바구니에 담긴공의 개수는 모두 달라야한다.
 * 
 * max와 min의 차이가 최소가 되도록 담을것이다.
 * 
 * N개의 공을 K개 바구니에 나눠 담을때, 나눠 담을 수 있는지, 가장 많이 담긴 바구니와 가장 적게
 * 담긴 바구니와 가장 적게 담긴 바구니의 공의 개수 차이를 계산해서 출력하는 프로그램을 작성하시오. 
 * 
 * debug
 * - 서로 다르며 1개이상 담으려면 1,2,3 이여야 한다
 * - 루프를 돌리며 직접 구현하려고 하면 복잡하고 수학적인 규칙을 찾는게 좋다.
 * - 3개가지 수는 1,2,3 과 같은 식으로 각수의 차이도 모두 다르므로 최소값과 최대값을 기준으로 미리 정해놓는다.
 * 
 * 
*/


int N, K ,ret,sum = 0;

int main(){

    cin >> N  >> K ;

    for(int i = 1; i<=K ; i++){
        sum += i;
    }
    
    N -= sum; 

    if(N < 0) {
        cout << -1;
    } 
    else {
        if( N % K == 0){
            cout << K-1;
        } 
        if(N % K != 0){
            cout << K;
        }
    }

    

}