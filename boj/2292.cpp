#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,m=1,h,w,x = 0,y = 0,z,res=0, t, tmp = 0;
	
	cin >> n;
	int idx = 1,val = 1;
	tmp = n;
	res = 1;
	int cnt = 1;
	while(1){

		val = idx * 6;
		cnt++;
		idx++;
		res +=val;
		if(res == tmp || res > tmp) break;

	}
	if(n == 1 ) cnt =1;
	cout << cnt;
}


/*
입력예제
13
출력예제
3
*/
