#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

/*
	수많은 도전 끝에 성공 하였다. 
	접근은 매우 쉬웠다. 인트형의 접근과 이진탐색 그리고 정렬
	그런데 cin 을 통한 입력이 ... 발목을 잡았고 
	한참을 해맸다... 
	짜증난다.
*/

int n , m,res = 0 , t;


// int count(vector<int> &resion, int mid){

// 	int i , res = 0;
// 	for(i = 0; i<resion.size(); i++){
// 		if(resion[i] > mid){
// 			res +=mid;
// 		}else {
// 		   res+=resion[i];
// 		}
// 	}
// 	// cout << res << '\n';
// 	return res;
// }

bool bs(int *m1, int target, int start, int end){
	if(start> end) return false;
	int mid = (start + end)/2;
	if(m1[mid] == target){
		return true;
	} else if(m1[mid] > target) {
		return bs(m1,target,start,mid-1);
	} else {
		return bs(m1,target,mid+1,end);
	}
}

int main(){ 
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int start = 0, end = 0, sum = 0;
	cin >> t;
	while(t--){
		int m1[1000001];
		int a;
		cin >> n ;
		for(int i = 0 ;i<n; i++){
			cin >> m1[i];
		}
		sort(m1,m1+n);
		cin >> m;
		for(int i = 0 ;i<m; i++){
			cin >> a;
			if(bs(m1,a,start,n-1)){
				cout << "1\n";
			}else{
				cout << "0\n";
			}
		}
	}
	
	return 0;
}