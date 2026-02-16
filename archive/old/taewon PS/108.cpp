#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

/*
	냅색 알고리즘 
	dy 배열의 의미를 정해야한다. 
	j가 무엇을 상징할지 정해야하고, 초기값을 정하는것을 잊지말자 
	여기서 j는 시간에 얻는 최대점수이다. 
	여기서 한 유형당 한개만 풀수있는 조건이 있다. 이말은 모든경우를 테스트해볼수없다는 이야기이다.
	그렇다면 20까지의 배열을 5번 모두 확인해여야한다. 그러므로 2차원 배열이 필요하다. 

	하지만 2차원 배열을 사용하면 공간복잡도가 장난 아니다.. 1차원으로 풀수있을까??
	1차원으로 배열 뒤에서부터 제한시간에 풀수있는 점수를 확인하면 중복되지 않고 체크할수있다.

	dy[j]  = max(dy[j], dy[j-pt]+ps;
*/
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	int n,m , ps, pt;
	cin >> n >> m ;
	vector<int> dy(m+1,0);
	for(int  i = 0; i<n; i++){
		cin >> ps >> pt;
		for(int j = m; j >= pt; j--){
			dy[j] = max(dy[j],dy[j-pt]+ps);
		}
	}
	cout << dy[m];
	return 0;
}

/*	입력예제
	5 20
	10 5
	25 12
	15 8 
	6 3 
	7 4
	출력예제
	41
*/

