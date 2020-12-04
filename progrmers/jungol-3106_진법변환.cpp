#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <math.h>
#include <string>
#define endl '\n'
using namespace std;

char convert(int n){
	if(n < 10)
		return n+0x30;
	else 
		return n+0x37;
}

void intto(unsigned long long n, int b){
	char arr[1000] = {0,};
	int i= 0 ; 
	while(1){
		if(n<b){
			arr[i] = convert(n);
			break;
		}
		arr[i] = convert(n%b);
		n /= b;
		i++;
	}
	for(; i>=0; i--)
		cout << arr[i];
	cout <<"\n";
}

int invert(char n){
	if( '0' <= n && '9'>=n)
		return n-0x30;
	else if ('A'<=n && 'Z'>=n)
		return n-0x37;

	return 0;
}

unsigned long long toint(char n[] , int a){
	unsigned long long decimal = 0, tmp;
	int len;

	len = strlen(n);

	for(int i = len - 1; i>=0; i--){
		tmp = invert(n[i]);
		for(int j = 0; j<(len-i-1); j++)
			tmp *=a;

		decimal +=tmp;
	}
	return decimal;
}


int main(){

	int a,b;
	char n[100] = {0,};

	while(1){
		cin >> a;
		if(!a) break;

		cin >> n >> b;

		intto(toint(n,a),b);
	}

	// in(n);
	// solv(str,n,k);
	// pr(n,k);
	return 0;
}