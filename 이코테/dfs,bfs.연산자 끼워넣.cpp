#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int n , a[101], op[4];
int maxx = -1e9, minx=1e9;

void dfs(int L, int sum){
	if(L == n){
		if( sum > maxx) maxx = sum;
		if( sum < minx) minx = sum;
		return ;

	} else {
		if(op[0] > 0){
			op[0]--;
			dfs(L+1,sum+a[L]);
			op[0]++;
		}
		if(op[1] > 0){
			op[1]--;
			dfs(L+1,sum-a[L]);
			op[1]++;
		}
		if(op[2] > 0){
			op[2]--;
			dfs(L+1,sum*a[L]);
			op[2]++;
		}
		if(op[3] > 0){
			op[3]--;
			dfs(L+1,sum/a[L]);
			op[3]++;
		}
	}
}

int main(void){

	cin >> n;

	for(int i = 0; i<n; i++){
		cin >> a[i];
	}

	for(int i = 0; i<4; i++){
		cin >> op[i];
	}

	dfs(1,a[0]);

	cout << maxx <<'\n'<< minx<<'\n';
}