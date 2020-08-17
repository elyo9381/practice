#include <bits/stdc++.h>
using namespace std;
	int arr[15][15];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int t,k,n;
	cin >> t;

	for(int i = 1; i<15; i++){
		arr[0][i] = i;
	}

	for(int i = 1; i<15; i++){
		for(int j = 1; j<15; j++){
			arr[i][j] = arr[i-1][j] + arr[i][j-1];
		}
	}
	while(t){

		cin >> k >> n;
		cout << arr[k][n] << "\n";
		t--;
	}
}

/*
입력예제
2
1
3
2
3
출력예제
6
10
*/
