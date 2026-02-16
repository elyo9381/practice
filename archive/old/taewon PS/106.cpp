#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

/*
	냅색 알고리즘 
	dy 배열의 의미를 알아야한다. 
	인덱스 j의 의미는 가방의 j라는 무게까지 가방에 담을수있을때  
	가방에 담을수있는 보석이 최대의 가치 
*/
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); 
	int n,m,w,v;
	cin >> n >> m;
	vector<int> dy(m+1,0);
	for(int i = 0; i<n; i++){
		cin >> w >> v;
		for(int  j = w; j<=m ; j++){
			// dy배열에 기존값과 보석을담을수있는 최대값을 더하고 비교합니다. 
			dy[j] = max(dy[j], dy[j-w] + v);
		}
	}
	cout << dy[m];
	return 0;
}

/*	입력예제
	4 11
	5 12 
	3 8 
	6 14
	4 8
	출력예제
	28
*/

