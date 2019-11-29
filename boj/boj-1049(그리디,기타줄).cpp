#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

// int  d[1001];

// int dp(int x){
// 	if(x == 0) return 1;
// 	if(x == 1) return 1;
// 	if(x == 2) return 2;
// 	if(d[x] != 0) return d[x];
// 	return d[x] = (dp(x-1) + dp(x-2)) % 10007;
// }


int d[100];

int dp(int x)
{
	if(x==1) return 1;
	if(x==2) return 2;
	if(d[x] != 0) return d[x];
	return d[x] = dp(x-1) + dp(x-2);
}


int main(void){
	cout << dp(10)<< endl;
}

