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

ll n,b,c, res = 0;

ll a[MAX];

int main(){

	cin >> n;

	for(int i  = 0; i<n; i++){
		cin >> a[i];
	}
	cin >>  b >> c;


	for(int i = 0; i<n ;i++){
		if(a[i] <=b ){
			res++;
		} else {
			res++;
			a[i] -= b;
			if(a[i] < c) res +=1;
			else if (a[i] == c ) res+=1;
			else if(a[i] > c){
				if(a[i] %c == 0) res += a[i]/c;
				else res += a[i]/c + 1;
			} 
		}
	}

	cout << res <<'\n';

}
