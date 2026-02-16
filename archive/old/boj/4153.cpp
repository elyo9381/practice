#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,m,h,w,x,y,z,res;

	while(cin >> x >> y >> z){
		if(x == 0  && y == 0  && z == 0) break;
		
		if(x*x + y*y == z*z) cout << "right"<<"\n";
		else cout << "worng"<<"\n";
	}
	return 0;

}

/*
입력예제
6 8 10
25 52 60
5 12 13
0 0 0
출력예제
right
worng
right
*/
