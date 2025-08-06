#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n,c,dis = 0,res = 0;
vector<int> arr;

/*
	인덱스를 bs하는것이 아니라 기준점을 잡고 이를 bs하는것이므로 
	lt = 0이면 2로 나눴을시 하나가 부족한 상황이 생기게 된다. 
	또한 두 집사이 거리가 0일때는 겹쳐진다는 소리인데 이러한 조건은 없으므로 lt =0으로 설정하면 안된다. 

	그리고 count함수에서 arr[i]- pos를 하여 mid보다 크거나 같다면 이는 기존의 첫번째 집과 두번째로 와이파이가 들어올 집이 생긴다는것이므로 cnt = 1이 default이다. 

	
*/

int count(vector<int> &arr, int mid){
	int pos = arr[0],cnt = 1, i ;
	for( i = 1; i<=arr.size(); i++){
		// n개의 집에 들어갈 와이파이의 수 == cnt
		if(arr[i] - pos >= mid){ 
			cnt+=1;
			pos = arr[i];
		}
	}
	return cnt;
}

int bs(vector<int> & arr, int s, int e){
	if(s > e) return 0;
	int m = (s+e)/2;
	if(count(arr,m) == c){
		res = m;
		return res;
	} else if( count(arr,m) > c){
		bs(arr,m+1,e);
	} else {
		bs(arr,s,m-1);
	}

	return res;
}


int main() {
	cin >> n >> c;
	int lt = 1, rt=0;

	for(int i = 0; i<n; i++){
		int a ;
		cin >> a;
		rt +=a;
		arr.push_back(a);
	}

	sort(arr.begin(),arr.end());

	dis = bs(arr,lt, rt);

	cout << dis ;
}
