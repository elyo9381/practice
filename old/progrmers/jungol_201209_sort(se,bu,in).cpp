#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;



/*
	선택정렬은 i,idx ,j를 가지고 idx > j이면 idx = j를 하여 swap
	버블정렬은 0 to n-1까지 j는 0to n-i-1까지 j>j+1이면 swap
	삽입정렬은 1to n-1, j는 i-1 to >0까지 j < tmp를 비교하여 j+1에 j를 넣는기법 

*/

int arr[102] ;

void se_sort(int n){
	int i, j, tmp;
	for(i=0; i<n ;i++){
		int idx = i;
		for(j= i+1; j<n; j++){
			if(arr[idx] > arr[j]){
				idx = j;
			}
			tmp = arr[i];
			arr[i] = arr[idx];
			arr[idx] = tmp;
		}

		for(int k = 0; k<n; k++){
			cout <<arr[k]<< " ";
		}
		cout<<endl;
	}
}

void bu_sort(int n){
	int i,j,tmp;

	for(i = 0; i<n-1; i++){
		for(j = 0;j<n-i-1; j++){
			if(arr[j] > arr[j+1]){
				tmp = arr[j+1];
				arr[j+1] = arr[j];
				arr[j] = tmp;
			}
		}
		for(int k = 0; k<n; k++){
			cout <<arr[k]<< " ";
		}
		cout <<endl;
	}
}

void in_sort(int n){
	int i,j,tmp,cnt=0;

	for(i = 1; i<n ;i++){
		tmp = arr[i];
		for(j = i-1; j>=0; j--){
			if(arr[j] > tmp) {
				arr[j+1] = arr[j];
				cnt++;
			}
			else break;
		}
		arr[j+1] =tmp;


		for(int k = 0; k<n; k++){
			cout <<arr[k]<< " ";
		}
		cout <<endl;
	}
	cout <<cnt;
}

int main(void){

	int n;
	cin >> n;
	for(int i =0; i<n; i++){
		cin >> arr[i];
	}
	

	// se_sort(n);
	// bu_sort(n);
	in_sort(n);
	return 0;
}
