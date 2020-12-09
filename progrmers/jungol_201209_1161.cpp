#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int sum =1;

int n,cnt=0;

int re(int n, int from, int tmp, int to) {
	if(n == 1){
		printf("1 : %d -> %d\n",from,to);
	}
	else{
		re(n - 1, from, to, tmp);
		printf("%d : %d -> %d\n",n,from,to);
		re(n-1,tmp,from,to);
	}
	return 0;
}

int main(void){

	int n;
	cin >> n;
	re(n,1,2,3);
	return 0;
}
 