#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

// 떡먹는 호랑이 문제
// 1 1 2 3 5 8
// 식의 순열이 존재할때
// 인덱스 6엔 8의 값이 들어있다.
// 인덱스 값과 인덱스배열의 데이터값이 주어질때 인덱스 1,2의값을 구하라


int a,b ;

void answer(int k){
	int i, j, an;

	for(i = 1; ; i++){
		for(j= i; ; j++){
			an= (i*a) +(j*b);
			if(an>=k) break;
		}
		if(an == k)
		break;
	}
	cout << i << '\n'<< j <<endl;
}

void count(int d){
	int i, aa[30][2];
	if(d >= 1)
	{
		aa[0][0] = 1;
		aa[0][1] = 0;
	}
	if(d >=2){
		aa[1][0] = 0;
		aa[1][1] = 1;
	}

	for(i = 2; i<d; i++){
		aa[i][0] = aa[i-1][0] + aa[i-2][0];
		aa[i][1] = aa[i-1][1] + aa[i-2][1];
	}
	a=aa[d-1][0];
	b=aa[d-1][1];
}

int main(){

	int d,k ; 
	cin >> d >> k;
	count(d);
	answer(k);
	
	return 0;
}
