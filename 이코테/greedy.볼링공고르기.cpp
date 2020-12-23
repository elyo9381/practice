#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


/*
    재귀를 이용해서 푸려고 하였으나 막혔다. 
    레벨로 인덱스를 타고 내려가고 루프를 통해서 다음인덱스를 탐방하려고 하였으나 잘 안되었다. 
    

*/



int arr[1001];
int ch[1001];
int n , m , cnt = 0;

// void re(int L){

// 	int pre =  0;
// 	if( L == m-1){
// 		int pos = 0;
// 		for(int i = 0; i<n; i++){
// 			cout << ch[i] ;
// 			if(pos != 0 && arr[pos] == arr[i])cnt -= 1;
// 			if( ch[pos] == 1 && arr[i] ==1 ){}
// 			if(ch[i] == 1){} pos = i;
// 		}
// 		cout << " " << cnt <<endl;
		
// 	} else {
// 		for(int i = L; i<n-1; i++){
// 			if(ch[L-1] <=i){

// 			ch[i] = 1;
// 			re(L+1);
// 			ch[i] = 0;
// 			}
			
// 		}
// 	}
// }

int main(){



	cin >> n >> m;

	for(int i = 0; i<n; i++){
		cin >> arr[i];
	}
	
	// for(int i = 0; i<n; i++){
	// 	for(int j = i+1; j<n; j++){
	// 		if(arr[i] == arr[j]) continue;
	// 		cnt++;
	// 	}
	// }
    re(0);
	cout << cnt <<endl;
}	