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

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};


int gcd (int a, int b){
	while(b != 0){
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int lcm(int a, int b){
	return a * (b / gcd(a,b));
}
int main(){
	int t , m , n ,x , y, i ,j ;

	cin >> t;

	while(t--){
		cin >> m >> n >> x >> y;
		int limit = lcm(m,n);
		for(j = x ; j<=limit ; j+=m){
			int temp = (j%n == 0)? n : j%n;
			if(temp == y){
				cout << j <<'\n';
				break;
			}
		}
		if(j  > limit)
			cout << "-1\n";
	}

	return 0;
}