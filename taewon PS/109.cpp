#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

/* 	<다익스트라 및 벨만포드는 한 정점에서 다른정점으로 가는 거리구하는 것이죠>
	
	플로이드는 그래프에서 모든 정점에서 모든 정점으로 가는 알고리즘 최단거리
	1번 정점에서 5번 정점까지 가는 최단거리를 찾는다고 할때 k번을 경우할수있다. 이때
	k번을 경우할때가 빠른지 또는 1 to 5로 바로 가는것이 빠른지 둘중최소값을 선택하게 되며
	이런상황에서 플로이드와샬 알고리즘을 사용한다. 
*/
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	int n,m ,a,b,c;
	cin >> n >> m;
	// max = 5000 으로 설정하였다. 
	vector<vector<int> > dis(n+1, vector<int>(n+1, 5000));
	for(int  i =1; i<=n; i++) dis[i][i] = 0;
	for(int i = 1; i<=m; i++){
		cin >> a >> b>> c;
		dis[a][b]=c;
	}
	for(int  k =1; k<=n; k++){
		for(int i = 1; i<=n; i++){
			for(int j =1 ; j<=n; j++){
				// if(dis[i][j] > dis[i][k] + dis[k][j]){
				// 	dis[i][j] = dis[i][k] + dis[k][j];
				// }
				dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
			}
		}
	}

	for(int i = 1; i<=n ; i++){
		for(int j = 1; j<=n; j++){
			if(dis[i][j]==5000) cout << "M ";
			else cout << dis[i][j] <<" ";
		}
		cout<<endl;
	}
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
*/

