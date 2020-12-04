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

void pr(int n){
	for(int i = 1 ; i<=n; i++){
		cout << aa[i];
	}
}

void solv(int n,int m){
	int sum1 = 0,sum2 = 0;
	for(int i = 1; i<=m ; i++){
		if(m%i == 0){
			for(int j = 1; j<=n; j++){
				if(aa[j] == i) sum1+= aa[j];
			}	
		}
	}
	cout<<sum1<<endl;

	for(int i = 1; i<=n; i++){
		if(aa[i] % m ==0) sum2+=aa[i];
	}
	cout <<sum2<<endl;
}

void in(int n){
	for(int i = 1 ; i<=n; i++){
		cin >> aa[i];
	}
}
int main(){

	int n,m,res;
	cin >> n;

	in(n);
	cin >> m;
	solv(n,m);
	// pr(n);

	return 0;
}

