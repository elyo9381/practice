#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

/*

  이코테 그리디 문제이다. 

  공포도가 x인 모험가는 반드시 x명 이상으로 구성한 모험가 그룹에 참여
  해야 여행을 떠날수있는 규칙이다. 

  입력 
  5
  2 3 1 2 2 

  출력
  2

  나는 m[arr[i]]를 통해서 공포도 x인사람의 인원체크를 하고 
  이를 공포도 맥스부터 내려 돌리면서 카운트 하려고 하였다. 
  하지만 이것의 문제점은 m[j] == 0일때를 생각치 못한것과
  맥스가 여러개 나올 경우를 생각하지 않았다. 
  만약에 문제가 그룹당 많은 인원을 보내는 문제였다면 
  내가 접근한 대로 했어야겠지만 

  이문제는 많은 그룹을 보내는것으로 보낼수있는 인원부터 보내는것이 좋겠다. 

  
*/

int main(){

	int n ,res = 0,cnt = 0; 
	int arr[100000]={0}; 
	int m[100000]={0};
	bool ch[100000];

	cin >> n;

	for(int i = 0; i<n; i++){
		cin >> arr[i];
	}
	sort(arr, arr+n);

	for(int i = 0; i<n; i++){
		cnt +=1;
		if(cnt >= arr[i]){
			res +=1;
			cnt = 0;
		}
	}

	cout << res <<endl;

}

