#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n,k,cnt = 0;
vector<int> arr;


int bs(vector<int>& arr, int start, int end) {
    if (start > end) return -1;
    int mid = (start + end) / 2;
    if (arr[mid] == mid) return mid;
    else if (arr[mid] > mid) return binarySearch(arr, start, mid - 1);
    else return binarySearch(arr, mid + 1, end);
}


// int unb(vector<int> &arr, int target, int start,int end){
// 	if(start > end) return 0;
// 	int mid = (start + end) / 2;
// 	// 해당 값을 가지는 원소 중에서 가장 왼쪽에 있는 경우에만 인덱스 반환
// 	if( (mid == 0 || target > arr[mid-1]) && arr[mid] == target ){
// 		return mid;
// 	// 중간점의 값보다 찾고자 하는 값이 작거나 같은 경우 왼쪽 확인
// 	} else if(arr[mid] >= target){
// 		return unb(arr,target,start,mid-1);
// 	// 중간점의 값보다 찾고자 하는 값이 큰 경우 오른쪽 확인
// 	} else {
// 		return unb(arr, target, mid+1,end);
// 	}
// }	

// int upb(vector<int> &arr, int target, int start, int end){
// 	if(start > end) return 0;
// 	int mid = (start + end) /2;
// 	if( (mid == n-1 || target < arr[mid + 1]) && arr[mid] == target) {
// 		return mid+1;
// 	} else if(arr[mid] > target) {
// 		return upb(arr,target,start,mid-1);
// 	} else {
// 		return upb(arr,target,mid+1,end);
// 	}
// }


// int count_value(vector<int> & arr, int x){
// 	int len = arr.size();
// 	int a = unb(arr,x,0,len-1);
// 	int b = upb(arr,x,0,len-1);
// 	cout << a << " : " << b << '\n';
// 	if(b == 0) return 0;
// 	return b-a;
// }

int main(){
	cin >> n ;

	for(int i = 0 ; i<n; i++){
		int a;
		cin >> a;
		arr.push_back(a);
	}

	// for(int i = 0; i<n; i++){
	// 	if( i == arr[unb(arr,arr[i],0,n-1)]){
	// 		cnt = i;
	// 	}
	// }

	cnt = bs(arr,0,n-1);
	
	cout << cnt;
}