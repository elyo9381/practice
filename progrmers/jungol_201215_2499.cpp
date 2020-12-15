#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

/*
	저울 문제 추의 무제가 주어졌을때 추로 측정할수없는 양의정수를 알아내는 문제이다.
	측정할수없는 양의 정수는 가장 큰 추 이전의 총 무게라고 할수있다. 
	추를 정렬하고 sum하는중에 가장큰 추보다 sum이 작으면 break 하여
	추를 더해가며 잴수있는 수는 sum이 될것이고 sum+1은 측정치 못하는 가장 최소의 값이 될것이다.
	
*/
 
int main() { 
	int n, sum = 0, res = 0;

	cin >> n;
	int *w = new int[n+1];

	for(int i = 1; i<=n; i++){
		cin >> w[i];
	}
	sort(w,w+n+1);
	// sum = w[1];
	for(int i = 1; i<=n ; i++){

		sum += w[i];
		cout << sum << " " << w[i] <<endl;
		if(sum < w[i+1]){
			break;
		}
	}
	cout << sum+1<<endl;
}
