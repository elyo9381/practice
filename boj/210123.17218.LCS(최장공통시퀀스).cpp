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

int cache[41][41];

int main(){

	string s1, s2;

	cin >> s1 >> s2;


	// memset(cache, 0, sizeof(cache));

	for(int i = 1; i<= s1.size(); i++){
		for(int j = 1; j<= s2.length(); j++){
			if(s1[i-1] == s2[j-1]) cache[i][j] = cache[i-1][j-1] + 1;
			else cache[i][j] = max(cache[i][j-1],cache[i-1][j]);
		}
	}

	string s = "";
	int x = s1.size();
	int y = s2.size();
	while(cache[x][y]){
		int now = cache[x][y];
		if(now == cache[x-1][y]) x--;
		else if( cache[x][y] == cache[x][y-1]) y--;
		else if(cache[x][y] != cache[x-1][y] && cache[x][y] != cache[x][y-1]) {
			s += s1[x-1];
			x--;
			y--;
		}
	}

	reverse(s.begin(), s.end());
	cout << s <<'\n';
}
