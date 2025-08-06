#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main(){
	int tmp,n, mok ,cnt = 0, cnt2 = 0, l = 0, r = 0;

	cin >> n; 

	tmp = n; 
	while(tmp > 0){
		tmp = tmp /10;
		cnt++;
	}
	tmp = n;

	while( tmp > 0){
		++cnt2;
		if((cnt/2) >= cnt2){
			mok = tmp %10;
			r +=mok;
		} else {
			mok = tmp %10;
			l +=mok;
		}
		tmp = tmp/10;
	}

	if(l == r) cout << "LUCKY";
	else cout << "READY";

}	