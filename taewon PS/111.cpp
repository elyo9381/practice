#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

/* 	위상 정렬
	일의 선후관계를 유지하면서 전체일의 순서를 짜는 알고리즘입니다.
	CPM(critical path)기법같은것이다. 
	그래프를 만들어 놓고 그래프에 따른 degree(진입차수)를 만들어서 
	degree가 낮은 놈 부터 순차적으로 계산하고 degree가 0이되면 다시 푸시한다.
*/
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	int n,m,a,b,s;
	cin >> n >> m;
	vector<vector<int> > graph(n+1,vector<int>(n+1,0));
	vector<int> degree(n+1);
	queue<int> Q;
	for(int i =0; i<m; i++){
		cin >> a >> b;
		graph[a][b] =1;
		degree[b]++;
	}
	for(int i =1; i<=n; i++){
		if(degree[i]== 0) Q.push(i);
	}
	while(!Q.empty()){
		int now = Q.front();
		Q.pop();
		cout<<now<< " ";
		for(int i = 1; i<=n; i++){
			if(graph[now][i] == 1){
				degree[i]--;
				if(degree[i]==0) Q.push(i);
			}
		}
	}
	return 0;
}


/*	입력예제
	6 6
	1 4
	5 4
	4 3 
	2 5 
	2 3 
	6 2

	출력예제
	1 6 2 5 4 3 
*/



