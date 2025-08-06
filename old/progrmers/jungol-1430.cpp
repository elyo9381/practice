#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <math.h>
#include <string>
#define endl '\n'
using namespace std;

int arr[100][100];
int aa[11];

void pr(){
	for(int i = 0; i<10; i++){
		cout<< aa[i]<< endl;
	}
}

void solv(int tmp){
	int b;
	while(tmp>0){
		b = tmp%10;
		aa[b]++;
		tmp /=10;
	}
}

int main(){

	int a,b,c,res = 0,tmp;
	cin >> a >> b >> c;
	res = a*b*c;
	tmp = res;
	solv(tmp);
	pr();

	return 0;
}

