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
 *  과일 하나를 먹으면 길이가 1만큼 늘어남
 *  과일의 높이는 hi이다.
 * 
 * 스네이크버드는 자신의 길이보다 작거나 같은 높이에 있는 과일들을 먹을 수 있습니다.
 * 
 * 스네이크버드의 처음 길이가 L일때 과일들을 먹어 늘릴 수 있는 최대 길이를 구하세요.
 * 
*/


int N,L,ret = 0;

int h[1001];



int main(){

    cin >> N >> L;

    for(int i= 0 ;i<N ; i++){
        cin >>  h[i];
    }

    sort(h, h+N);
    for(int i= 0; i<N; i++){
        if(h[i] <= L){
            ret = h[i];
            L+=1;
        }
    }   

    cout << L << "\n";


}