#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,m,h,w,x,y,z,res=0, t;
	cin >> t;

	char xx ,yy;
	while(t>0){

		cin >> h >> w >> n;
		int cnt = 0,flag = 0;

		vector<vector<int> > map(h+1,vector<int>(w+1,0));

		for(int i = 1; i<=w; i++){
			if(flag == 1) break;
			for(int j = 1 ; j<=h; j++){
				map[j][i] = i;
				cnt++;
				if(cnt == n){ 
					flag = 1;
					cout<< j*100+ i;
					break;
				}
			}
		}
		cout<<"\n";
		t--;
	}
	return 0;
}

/*
입력예제
2
6 12 10
30 50 72
출력예제
402
1203
*/


