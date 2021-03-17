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
 * - 여러 개의 로프를 병렬로 연결하면 각각의 로프에 걸리는 중량을 나눌 수 있다.
 * - 로프에는 모두 고르게 w/k만큰의 중량이 걸리게 된다. 
 * 
 * 설계 
 * 1,정렬후 최소값의 N배 해주면 될줄알았다. : fail
 *
 * debug
 * - 정렬후 최소값의 N배 하는데 n-1*(N)보다 n이 더 클수 있다. 
 * 생각할것.
*/

vector<int> arr;
int N;

int main(){

    int w = 0;

    cin >> N;
    for(int i = 0; i<N; i++){
        int a;
        cin >> a;
        arr.push_back(a);
    }
    
    sort(arr.begin(),arr.end());

    for(int i = 0; i<N; i++){
        if( w < arr[i] * (N-i)){
            w = arr[i] * (N-i);
        }
    }
    cout << w << "\n";
    
}