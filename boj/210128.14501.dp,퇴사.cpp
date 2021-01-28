#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;
#define INF 987654321
#define hash 1000000007LL
typedef long long ll;
typedef pair<int,int> pii;
const int MAX = 1000001;

int d[50];

int main(){

	int n,ret = 0,t = 0, sum = 0;

	vector<pii> v;
	cin >> n;
	v.resize(n+1);
	for(int i = 1; i<=n; i++){
		cin >> v[i].first >> v[i].second;
	}

	for(int i = 1; i<=n+1; i++){
		if(i + v[i].first <=n+1){
			d[i+v[i].first] = max(d[i+v[i].first], d[i] + v[i].second);
			ret = max(ret,d[i+v[i].first]);
		}

		d[i+1] = max(d[i+1],d[i]);
		ret = max(ret , d[i+1]);

	}
	cout << ret <<'\n';
}