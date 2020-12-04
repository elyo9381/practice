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

void solv(int n){
	int sum1 = 0,sum2 = 0,idx = 1;
	for(int i = 1; i<=n; i++){
		if(n%i == 0)cout << i << " ";
	}
	
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
	solv(n);
	// pr(n,k);
	return 0;
}

