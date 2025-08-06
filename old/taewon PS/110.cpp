#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

/* 	플로이드와샬

*/
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);	
	int n, a, b, score;
	cin>>n;
	vector<vector<int> > dis(n+1, vector<int>(n+1, 100));
	vector<int> res(n+1);
	for(int i=1; i<=n; i++) dis[i][i]=0;
	while(true){
		cin>>a>>b;
		if(a==-1 && b==-1) break;
		dis[a][b]=1;
		dis[b][a]=1;
	}
	for(int k=1; k<=n; k++){
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				dis[i][j]=min(dis[i][j], dis[i][k]+dis[k][j]);
			}
		}
	}
	score=100;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(i==j) continue;
			res[i]=max(res[i], dis[i][j]);
		}
		score=min(score, res[i]);
	}
	int cnt=0;
	for(int i=1; i<=n; i++){
		if(res[i]==score) cnt++;
	}
	cout<<score<<" "<<cnt<<endl;
	for(int i=1; i<=n; i++){
		if(res[i]==score) cout<<i<<" ";
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
	2 3
	2 3 4 

*/



