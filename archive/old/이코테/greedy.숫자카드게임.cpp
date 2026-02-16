#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

/*
 1. n*m은 행,열이다.
 2.열을 선택하고 선택한 열의 최소값구한다.
 3. 선택된 행의 카드를 선택하고 이후에 해당 행에서 가장 작은숫자가 낮은 카드를 뽑을 것을 고려해
 가장높은 숫자카드를 뽑을수있도록 전략을 짠다.

 입력 
 3 3 
 3 1 2 
 4 1 4 
 2 2 2 

 출력 
 2
*/

int arr[100][100];

int main(){

	int n, m;
	int res = 0

	for(int i = 0; i<n; i++){
		int minx = 2147000000;
		for(int j = 0; j<m; j++){
			cin >> arr[i][j];
			minx = min(minx,arr[i][j]);
		}
		res = max(res, minx);
	}

	cout << res <<'\n';
}

}