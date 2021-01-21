#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
#include <math.h>
#include <cstring>

using namespace std;
#define hash 1000000007LL;
typedef long long ll;
typedef pair<int,int> pii;
const int MAX = 100001;

int t, n;

/*
    dp를 이용한 피보나치 0,1이 호출된 가짓수 구하는 문제이다. 
    0,1이 호출된 가짓수는 fibo(x-1),fibo(x-2)의 값들이랑 같아서 이를 구하면 된다. 

*/



int dp[50];

int fibo(int x){

	if(x == 0){
		dp[0] = 0;
		return 0;
	} else if( x == 1){
		dp[1] = 1;
		return 1;
	}
	
	if(dp[x]!= 0){
		return dp[x];
	} else {
		return dp[x] = fibo(x-1) + fibo(x-2);
	}
}

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	while(t--){

		cin >> n;
		
		if(n == 0){
			cout << 1 << " " << 0 << "\n";
		} else if(n==1){
			cout << 0 << " " << 1 << "\n";
		} else{

		fibo(n);
		cout << dp[n-1] << " " << dp[n] <<'\n';
		}

	}
}