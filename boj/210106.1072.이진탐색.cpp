#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

/*
   이진탐색을 재귀를 통해서 구현하려고 하지 말자 
    재귀로 생각치 못하겠으면 루프로 다시 구현해보자 
    그렇게 어렵지는 않았는데 접근은 맞았는데 구현을 못했다. 

*/
long long x,y,z;

int count(int mid){

	int tmpz = (100*(y+mid)/(x+mid));
	return tmpz;
}
int res = 0;

int bs(int start, int end){
	if(start>end) return 0;
	int mid = (start+end)/2;

	if(count(mid) <= z){
		res = mid+1;
		bs(mid+1,end);
	} else {
		bs(start, mid-1);
	}
		// int tmpz = ((y+mid)*100) / (x+mid);
		// cout << "mid : " << mid << " "<< "tmpz : " << tmpz<<'\n';
		// if(z >= tmpz){
		// 	res = mid +1;
		// 	start = mid +1;
		// } else {
		// 	end = mid-1;
		// }

	return res;
}
int main(){


	cin >> x >> y;

	z =  (y * 100)/x;

	cout << z <<'\n';

	if(z >= 99) {
		cout << -1 <<'\n';
		return 0;
	}

	int start = 0, end = 1e9;
	int result = -1;
	result = bs(start,end);

	// while(start <= end){
	// 	int mid = (start + end) /2;
	// 	// int tmpz = ((y+mid)*100) / (x+mid);
	// 	int tmpz = ((y+mid)*100) / (x+mid);
	// 	cout << "mid : " << mid << " "<< "tmpz : " << tmpz<<'\n';
	// 	if(z >= tmpz){
	// 		res = mid +1;
	// 		start = mid +1;
	// 	} else {
	// 		end = mid-1;
	// 	}
	// }

	cout << result <<endl;
	return 0;
}

