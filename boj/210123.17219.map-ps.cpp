#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;
#define hash 1000000007LL;
typedef long long ll;
typedef pair<int,int> pii;
const int MAX = 100001;

map<string,string> mp;

int main(){

 	ios::sync_with_stdio(false);
    cin.tie(0);

	int n,m;

	cin >> n >> m ;

	while(n--){
		string s, str;
		cin >>  s >> str;
		mp[s]=str;
	}

	while(m--){
		string s;
		cin >> s;
		cout << mp[s] << '\n';
	}
	
}