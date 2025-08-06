#include <bits/stdc++.h>
// #include <stdio.h>
// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <queue>
using namespace std;

/* 	

*/
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,m,h,w,x,y,res;

	cin >> x >> y >> h >> w;

	int a,b;
	a=min(abs(x-0),abs(y-0)); 
	b=min(abs(x-h),abs(y-w));
	res = min(a,b);
	cout << res ;

	return 0;

}


/*	입력예제

*/