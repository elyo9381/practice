#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <math.h>
#include <string>
#define endl '\n'
using namespace std;
int aa[100];
// int change(char t[], int len){
// 	if(len == 0) return 0;
// 	return change (t,len-1) * 2 + (t[len-1]- '0');
// }

// bool isPrime(int n){
//     if(n < 2) return false;
//     for(int i = 2; i<=n /i ; i++){
//         if(n % i ==0) return false;
//     }
//     return true;
// }

// void pr(int n,int k){
// 	if(aa[k] != 0) cout <<aa[k];
// 	else cout <<0;
// }

void solv(char str[]){

	int pre,now, koi=0, ioi=0 , sum = 0;

	int len =  strlen(str);
	pre = 0;
	for( now = 1; str[now]!='\0'; now++){
		if(str[now] == 'O'){
			if(str[pre] == 'K' && str[now+1] == 'I') koi++;
			else if( str[pre] == 'I' && str[now+1] == 'I') ioi++;

		}
		pre=now;
	}
	cout << koi << '\n' << ioi <<endl;

  
}


// void in(int n){
// 	for(int i = 1 ; i<=n; i++){
// 		cin >> aa[i];
// 	}
// }

int main(){

	char str[10000];
	cin >> str;

	// in(n);
	solv(str);
	// pr(n,k);
	return 0;
}


