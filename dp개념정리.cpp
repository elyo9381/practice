#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
//동적프로그래밍 개념정리

int d[100];

int dp(int x)
{
	if(x==1) return 1;
	if(x==2) return 1;
	if(d[x] != 0) return d[x];
	return d[x] = dp(x-1) + dp(x-2);
}


int main(void){
	cout << dp(5)<< endl;
}

