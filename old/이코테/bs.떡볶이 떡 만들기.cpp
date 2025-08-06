#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n,m;

int count(int mid, vector<int> &a){

	int res = 0, i;
	for(i = 0; i<n; i++){
		if(a[i] - mid > 0){
			res+= a[i] - mid;
		}
		// if(a[i] > mid) res += a[i]-mid;
	}
	return res;

}

int BS(vector<int> &a, int s, int e){
	if(s > e)return -1;
	int mid = (s+e)/2;
	int res;
	cout << "s : " << s << " e : " << e << " mid : " << mid << " count : " <<count(mid,a) <<"\n";
	if( count(mid,a) == m){
		return mid;
	}
	else if( count(mid,a) > m){
		res=BS(a,mid+1,e);

	}
	else 
		res=BS(a,s,mid-1);
	return res;
}

int main(){

	vector<int> a;
	int lt = 0, rt = 0, res;

	cin >> n >> m;
	for(int i = 0; i<n; i++){
		int num;
		cin >> num;
		rt += num;
		a.push_back(num);
	}

	sort(a.begin(),a.end());

	lt = a[0];
	// rt = 1e9;
	res = BS(a,lt,rt);

	cout << res;
	return 0;
}