#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <math.h>
#include <string>
#define endl '\n'
using namespace std;

int arr[100][100];
int aa[100];

void pr(int n,int k){
	if(aa[k] != 0) cout <<aa[k];
	else cout <<0;
}

void solv(int n,int k){
	int gcd = 0,lcm = 0,tmp = 1;
	if(n < k) tmp = n;
	else tmp = k;

	for(int i = 1; i<=tmp; i++){
		if( n % i == 0 && k % i == 0){
			gcd = i;
		}
	}
	
	lcm = (n * k)/gcd;
	cout << gcd  << '\n' << lcm;
}

void in(int n){
	for(int i = 1 ; i<=n; i++){
		cin >> aa[i];
	}
}
int main(){

	int n,m,k,res;
	cin >> n >> k;

	// in(n);
	solv(n,k);
	// pr(n,k);
	return 0;
}

