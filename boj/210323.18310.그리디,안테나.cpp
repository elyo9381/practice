#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

/**
 * 
 * 조건
 * 안테나로부터 모든집까지의 거리의 총합이 최소가 되도록 설치 
 * 논리적으로 동일한 위치에 여러개의 집이 존재하는것 가능 (1,3,3,3) 
 * 
 * 설계
 * 각집에서 다른집까지의 절대값을 구하고 
 * 이절대값이 가장 작은 놈을 구한다. 
 * 이때 값이 같은게 나오면 인덱스의 최소값을 출력한다. 
 * 인트형 넘어가는데 long long으로 하면 되려나...?
 * 
 * 디버그 
 * 물론 정답이 나온다. 하지만 시간초과가 뜬다. 
 * 모든 집까지의 최소 거리가 되게하는법은 중간의 집을 선택하는것이다. 
*/

long long MIN(long long a, long long b){
    return a < b ? a : b; 
}


long long n,absSum = 0, ret = 1e12, mIdx = 1e12;
int homes[200001];

int main(){

    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> homes[i];
    }

    sort(homes, homes+n);

    if(n % 2 ==1){
        cout << homes[n / 2] <<"\n";
    } 
    else {
        cout << homes[n / 2 -1] <<"\n";
    }

    // for(int i = 0; i<n; i++){
    //     for(int j = 0; j<n; j++){
    //         if(homes[i] == homes[j]) continue;
    //         absSum += abs(homes[i] - homes[j]);
    //     }
    //     if( ret >= absSum) {
    //         ret = absSum;
    //         mIdx = MIN(mIdx,homes[i]);
    //     }
    // }

    // cout <<  mIdx;
}