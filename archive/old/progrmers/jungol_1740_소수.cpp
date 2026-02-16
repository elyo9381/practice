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
	int sum = 0, min = 2147000000;
	for(int i = n ; i<=k; i++){
		int f= 1;
		for(int j = 2; j<=i/j; j++){
			if( i % j == 0) f = 0;
		}

		if(f ==1){
		if(i < min) min = i;
		sum += i; 
		}
	}
	if(sum == 0) cout << -1;
	cout << sum << endl << min;	
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

