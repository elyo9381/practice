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

bool isPrime(int n){
    if(n < 2) return false;
    for(int i = 2; i<=n /i ; i++){
        if(n % i ==0) return false;
    }
    return true;
}

void pr(int n,int k){
	if(aa[k] != 0) cout <<aa[k];
	else cout <<0;
}

void solv(int n){
    if(isPrime(n)){
        cout << n <<endl;
        return;
    }

    int f=0;
    for(int i = 1 ; !f; i++){
        if(isPrime(n-i)){
            cout << n-i << " ";
            f++;
        }
        if(isPrime(n+i)){
            cout << n+i;
            f++;
        }
    }
    cout << "\n";
}


void in(int n){
	for(int i = 1 ; i<=n; i++){
		cin >> aa[i];
	}
}

int main(){

	int n,m,k,res;
	cin >> n;

	// in(n);
	while(n>0){
		cin >> m;
		solv(m);
		n--;

	}
	// pr(n,k);
	return 0;
}

