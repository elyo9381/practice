#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

/*
    dp를 통한 최단거리 및 최소 비용 등을 구할수있다. 
    0행 , 0열 을 dy 넣는다.  

*/
using namespace std;
int arr[21][21], dy[21][21];
int main(){
	ios_base::sync_with_stdio(false);
	int n, cnt=0;
	cin>>n;
	// 입력을 받는다.
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>arr[i][j];
		}
	}
	// 초기 (0,0)은 arr 이나 dy도 같은느낌을 준다.
	dy[0][0]=arr[0][0];
	// 배열에서의 dy는 ,up,left,up&left, up&left,middle등을 관련지어 규칙을찾는다.
	// 여기는 up-down, left-right의 더하기규칙
	for(int i=1; i<n; i++){
		dy[0][i]=dy[0][i-1]+arr[0][i];
		dy[i][0]=dy[i-1][0]+arr[i][0];
	}
	// 여기는 corner(diagonel)중에 최소값의 더하기규칙
	for(int i=1; i<n; i++){
		for(int j=1; j<n; j++){
			dy[i][j]=min(dy[i-1][j], dy[i][j-1])+arr[i][j];
		}
	}
	cout<<dy[n-1][n-1];
	return 0;
}