#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main(){


	int n, arr[1001]={0}, ch[1001] = {0},sum = 0;

	cin >> n; 
	for(int i = 0; i<n; i++){
		cin >> arr[i] ;
	}
	sort(arr, arr+n);

	sum = arr[0];
	ch[sum] = 1;

	for(int i = 1; i<n; i++){
		sum+=arr[i];
		ch[sum]=1;
		if(sum <arr[i+1]) break;
	}
	if(ch[1] == 0) cout << 1 <<endl;
	else cout << sum+1<<endl;
}	