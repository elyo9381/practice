#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

/*
	이진 탐색과 삼진 탐색을 이용하여 탐색 과정을 카운트하는 문제
	문제이해를 못하여 오래걸림 
	
*/

int n,bcnt = 0,tcnt = 0,cnt = 0;

int bs(int *arr, int target, int start, int end){
	if(start>end) return -1;
	int mid = (start+end)/2;
	if(arr[mid] == target){
		return bcnt;
	} else if( arr[mid] < target){
		bcnt++;
		return bs(arr,target,mid+1,end);
	} else{
		bcnt++;
		return bs(arr,target,start,mid-1);
	}
}

int ts(int *arr, int key, int low, int high)
{	
	int mid1, mid2;
	if (low > high)
	{
		return -1;
	}
	else
	{
		mid1 = low + (high - low) / 3;
		mid2 = high - (high - low) / 3;
		tcnt++;
		if (arr[mid1] == key)
		{	tcnt--;
			return tcnt;
		}
		else if (arr[mid2] == key)
		{	
			tcnt++;
			tcnt--;
			return tcnt;
		}
		if (key < arr[mid1])
		{
			tcnt++;
			return ts(arr, key, low, mid1 - 1);
		}
		else if (key < arr[mid2])
		{	
			tcnt++;
			return ts(arr, key, mid1 + 1, mid2 - 1);
		}
		else
		{
			tcnt++;
			return ts(arr, key, mid2 + 1, high);
		}
	}
}

int arr[500001];


int main(){
	cin >> n;

	int b,t , res1=0,res2=0,res3=0;
	

	for(int i = 0; i<n; i++){
		arr[i] = i;
	}

	for(int i = 0; i<n; i++){
		b = bs(arr,i,0,n-1);
		t = ts(arr,i,0,n-1);

		if( b > t){
			res3+=1;
		} else if( b < t){
			res1+=1;
		} else {
			res2+=1;
		}
		cnt = 0;
		bcnt = 0;
		tcnt = 0;
	}
		cout << res1 <<'\n';
		cout << res2 <<'\n';
		cout << res3 <<'\n';
}