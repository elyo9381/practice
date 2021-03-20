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
 * 가장 왼쪽에서 정수만큼 떠렁진 거리만 물이샌다.
 * L인 테이프 무한개
 * 좌우 0.5간격줘야함
 * 
 * 테이프의 최소개수 구하는 프로그램 (테이프 겹치기 가능)
 * 
 * 설계
 * 좌우 0.5간격을 줘야한다.
 * 
*/

int n, l ;
vector<int> v;

int main(){

    cin >> n  >> l; 
    int cnt = 0;

    for(int i= 0; i<n; i++){
        int a;
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(), v.end());

    int min = 1;
    double tapeRange = v[0] - 0.5 + l;

    for(int i= 0; i<n; i++){
        if(tapeRange < v[i] + 0.5 ){
            tapeRange = v[i] - 0.5 + l;
            min++;
        }
    }

    cout << min << "\n";


}