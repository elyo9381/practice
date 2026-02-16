#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

/*
	상태 트리를 그리는데 (2,2)기준으로 
	D(2,2) 시작하여 D(1,1) ,(1,0) ... 계속 내려간다
	행, 열이 0이 되면 한방향 더하기를 구성한다. 
	메모이제이션 dy 조건을 빼먹지 말자. 
	
	DFS의 전위순회방법으로 데이터가 불러온다는것을 상기하자. 
*/

using namespace std;
int arr[21][21], dy[21][21];
int DFS(int x, int y){
	// memoization의 조건
	if(dy[x][y] > 0 ) return dy[x][y];
	//(0,0)일때의 베이스조건
	if(x == 0 && y ==0) return arr[0][0];
	else{
		// 전위순위를 돌아야하므로 DFS()파라미터의 이전 DFS불러오면서 전위순회가 작동한다. 
		if( x == 0 ) return  dy[x][y] = DFS(x,y-1) + arr[x][y];
		else if ( y==0 ) return dy[x][y] = DFS(x-1,y) + arr[x][y];
		else return dy[x][y] = min(DFS(x-1,y),DFS(x,y-1)) + arr[x][y];
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	int n, cnt=0;
	cin>>n;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>arr[i][j];
		}
	}

	cout << DFS(n-1,n-1);
	return 0;
}