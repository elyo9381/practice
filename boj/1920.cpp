#include <bits/stdc++.h>
using namespace std;

int n,m;
int arr[100001],res[100001];

void Binary_Search(int tar){
	int lt,rt;
	lt = 0; rt = n-1;
	while(lt<=rt){
		int mid = (lt+rt)/2;

		if(arr[mid] == tar) {
			cout << "1\n";
			return;
		}
		else if(tar < arr[mid]) rt = mid-1;
		else lt = mid+1;
	}

	cout << "0\n";
	return ;
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 0; i<n; i++) cin >> arr[i];
	sort(arr,arr+n);
	cin  >> m;
	for(int i = 0; i<m; i++){
		int t;
		cin >> t;
		Binary_Search(t);
	}

	return 0;
}


/*
입력예제
5
4 1 5 2 3
5
1 3 7 9 5

출력예제
1
1
0
0
1
end
*/ 