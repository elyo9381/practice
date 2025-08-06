#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
#include <math.h>

using namespace std;
#define hash 1000000007LL;
typedef long long ll;
typedef pair<int,int> pii;
const int MAX = 987654321;
 
int n, m, ans; 
int arr[5001];

// 문제에서 주어진 조건을 잘보자... 최대 최소값으로 진행하라고 했으니 이걸로 확인하는것이 좋다. 
// 갠히 sum으로 확인하려고 하지말고 주는걸로 하자 제발 

bool check(int mid){
	int sum = 0,i,cnt = 1, maxx = -1e9, minx = 1e9;
	for(i = 0; i<n; i++){
		maxx = max(arr[i],maxx);
		minx = min(arr[i],minx);

		if(maxx - minx > mid){
			cnt++;
			maxx = arr[i];
			minx = arr[i];
		}	
	}
	return m>=cnt;
}

int main(){

	cin >> n >> m;

	int lo = 0, hi = 0, mid,res = 0;
	for(int i = 0; i<n; i++){
		cin >> arr[i];
		hi +=arr[i];
	}
	res = 0;
	
	while(lo<=hi){
		mid = (lo+hi)/2;
		bool ch = check(mid);
		if(ch){
			hi = mid-1;
			ans = mid;
		} else {
			lo = mid+1;
		}
	}

	cout <<  ans <<"\n";

	return 0;
}