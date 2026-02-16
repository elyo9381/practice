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
 * 레벨을 난이도순으로 배치 하지만, 쉬운레벨이 어려운 레벨보다 점수를 많이 받는 경우 존재
 * 특정레벨의점수감소 
 * 
 * 각레벨을 클리어할때 얻는 점수가 주어질때, 몇번 감소 시키면 되는지 프로그램 작성
 * 
 * 설계
 * 
 * 각 레벨은 다음레벨보다 클리어시 주는 점수가 낮아야한다. 
 * 그러므로 인덱스별 확인을 통해서 -1 낮게 뺄샘한다.
 * 
*/

int N;
vector<int> v;

int main(){

    int ret = 0 ;
    
    cin >> N ;

    for(int i = 0; i<N ; i++){
        int levelIndex;
        cin >> levelIndex;
        v.push_back(levelIndex);
    }

    for(int i = N-1; i>=0; i--){
        
        if(v[i-1] >= v[i]){
            int hap = (v[i-1] - v[i]) + 1;
            v[i-1] -= hap;
            ret += hap;
        }
    }

    cout << ret << "\n";
}