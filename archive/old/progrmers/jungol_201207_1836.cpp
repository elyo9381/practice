#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int arr[100001];
int num[100001];

// void dfs(int L,int sum){
//     if(L == n+1){
//         for(int i = 1; i<=n; i++){
//             if(ch[i]!=0 && arr[i]!=0){
//                 cout << sum <<endl;
//             }
//         }
//     } else {
//         ch[L] = 1;
//         dfs(L+1, sum+arr[L]);
//         ch[L] = 0;
//         dfs(L+1, sum);
//     }
// }

void maxadd(){

	int i,j,max = -2147000000, k,a,c;

	for(i = 0; i<n; i++){
		a = arr[i];
		if(a > max){
			max = a;
			num[0] = i;
			c =1;
		}
		for(j = i+1; j<n; j++){
			a = a+arr[j];
			if(a > max){
				max = a;
				c = j-i+1;
				for(k=0; k<c; k++){
					num[k] = i+k;
				}
			}
		}
	}
	cout << max << '\n';
}
int main(void){

    cin >> n;

    for(int i = 0; i<n ;i++){
        cin >> arr[i];
    }

	maxadd();


	return 0;
}