#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

long long n, m, res = 0;
vector<long long> wood;

long long count(vector<long long> &wood, long long mid){

	long long res = 0 , sum = 0, i;
	for( i = 0; i<n; i++){
		if(wood[i] > mid){
			res += wood[i] - mid;
		}
	}
	return res;
}

long long bs(vector<long long> &wood, long long start, long long end){
	if(start > end) return 0;
	long long mid = (start+end)/2;

	if( count(wood,mid) >= m){
		// if( res < mid)
			res = mid;
	// } else if( count(wood,mid) < m){
		bs(wood,mid+1,end);
	} else {
		bs(wood,start,mid-1);
	}
	return res;
}

int main(){
	long long result = 1, start = 0, end = 1e9;
	cin >> n >> m;

	for(int i = 0; i<n; i++){
		long long a;
		cin >> a;
		wood.push_back(a);
	}

	result = bs(wood,start,end);
	cout << result;
}