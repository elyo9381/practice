#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

/*

 나는 dfs로 풀었다. 인덱스를 레벨로 보고 +,*의 경우를 완탐하였고 
 이를 기반으로 max로 비교하여 최종 max를 반환하였다. 
 
 그리디의 개념으로 접근하려면 0,1을 곱하게 되면 수가 더 작아진다.
 그러며로 배열값및 최종값이 1보다 작을때는 더하고 아닐때는 곱하면
 그리디 문제로 풀수있다. 
*/

int ch[21], arr[21];
int len ;


int re(int L, int sum){
	int mx = 0;

	if(L == len-1){
		mx = max(mx,sum);
		return mx;
	} else {
		ch[L] = 1;
		mx = max(mx,re(L+1,sum+arr[L+1]));
		ch[L] = 0;
		mx = max(mx,re(L+1,sum*arr[L+1]));
	}
	return mx;
}

int main(){

	string s;
	cin >> s;
	len = s.size();
	int res = 0;

	for(int i= 0 ;i<len; i++){
		arr[i] = s[i] - 48;
	}
	for(int i= 0; i<len-1; i++){
		if(arr[i] <=1 || res <=1)
			res += arr[i+1];
		else
			res *= arr[i+1];
	}
	cout << res <<endl;


	
	// cout << re(0,arr[0]);

}

