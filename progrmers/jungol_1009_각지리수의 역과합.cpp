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
	
}

void in(int n){
	for(int i = 1 ; i<=n; i++){
		cin >> aa[i];
	}
}

void reverse(int n){
	int res = 0,tmp,sum = 0,renum;
	while(n>0){
		tmp = n %10;
		sum +=tmp;
		res = res * 10 +(tmp);
		n /=10;
	}
	cout << res << " " << sum<<endl;
}
int main(){

	int n,m,k,res;

	while(1){
		cin >> n;
		if(n == 0) break;
		reverse(n);

	}
	// cin >> n >> k;

	// in(n);
	// solv(n,k);
	// pr(n,k);
	return 0;
}

