#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

/*
	냅색 알고리즘 
	dy 배열의 의미를 정해야한다. 
	j가 무엇을 상징할지 정해야하고, 초기값을 정하는것을 잊지말자 
	여기서 j는 coin을 사용해 거슬러줄 금액이다. 
*/
using namespace std;

int main(){
	int n,money;
	cin >> n ;
	vector<int> coin(3+1);
	for(int i = 1; i<=n; i++) cin >> coin[i];
	cin >> money;
	vector<int> dy(money+1,1000);
	// 출발점 초기화 0원을 거슬러주는데는 0원이므로 
	dy[0] = 0;
	for(int i = 1; i<=n; i++){
		// coin[i]는 coin배열 안의 값을 넣어야하므로 이렇게 지정한다. 
		for(int  j = coin[i]; j<=money ; j++){
			// dy배열에 기존값과 보석을담을수있는 최대값을 더하고 비교합니다. 
			dy[j] = min(dy[j],dy[j- coin[i]] + 1);
		}
	}
	cout << dy[money];
	return 0;
}

/*	입력예제
	3
	1 2 5
	15
	출력예제
	3
*/

