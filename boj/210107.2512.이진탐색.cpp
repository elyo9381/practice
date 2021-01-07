#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

/*
    이분탐색 풀이 

    0, 정해진 촉액 이하에서 가능한 한 최대의 총예산 구하기 
    1. 모든 요청이 배정될수있는 경우에는 요청한 금액을 그대로 배정한다.
    2. 모든 요정이 배정될 수 없는 경우에는 특정한 정수 상한액을 계산하여 그 이상인 예산요청에는 모두 상한액을
    배정한다. 상한액 이하의 예산요청에 대해서는 요청한 금액을 그대로 배정한다.

    1 요청이 배열로 들어오는데 요청한 금액이 모두 요청되러면  요청의 합이 국가예산보다 작아야한다. 
    이러한 경우를 하나 작성
    2의 경우는 특정한 정수 상한액을 이진탐색으로 계산(mid) 그리고 이를 통해서 최대값을 구하고 이때 mid를
    반환하여야한다. 

*/

int n , m,res = 0;
vector<int> resion;

int count(vector<int> &resion, int mid){

	int i , res = 0;
	for(i = 0; i<resion.size(); i++){
		if(resion[i] > mid){
			res +=mid;
		}else {
		   res+=resion[i];
		}
	}
	// cout << res << '\n';
	return res;
}

int bs(vector<int> &resion, int start, int end){
	if(start> end) return 0;
	int mid = (start + end)/2;
	if(count(resion,mid) <= m){
		res = mid;
		bs(resion,mid+1,end);
	} else {
		bs(resion,start,mid-1);
	}
	return res;
}

int main(){ 
	int start = 0, end = 0, sum = 0;
	cin >> n ;
	for(int i = 0 ;i<n; i++){
		int a;
		cin >> a;
		sum +=a;
		end = max(end,a);
		resion.push_back(a);
	}
	cin >> m;

	if(sum <= m){
		cout <<  end << '\n';
		return 0;
	}

	int result;

	result = bs(resion,start,sum);
	cout <<  result << '\n';
	return 0;
}