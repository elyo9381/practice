#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

/*
 섞기순열을 만드는것부터 힘들었다...
 문제를 천천히 읽어보자!!!!
 너무 성급하게 읽어서 할수있는것도 못하였다..

 입력받은 배열은 섞기 순열이고
 시작하는 순열은 123456이다.
 물론 입력받은 순열도 섞기 순열이면서 시작순열이 될수있다. 

 ... 위과같이 풀면 시간초과난다 왜냐?? 궤적이 20억이기 때문이다.
 카드는 2만이하로 주어지지만 카드 썪는것을 인덱스 처음과 끝으로 섞는다고 생각해보면
 카드 중앙으로 몰리면서 처음같은 값이 나올때까지 반복한다. 최소 2만 * 1만 * 1만 으로 수가 커지게 된다.
 이런식으로 최대 20억까지 나올가능성이 존재한다고 하니
 시간을 단축하기 위해서 
 중복되는 조건을 찾아야한다. 
 3 -> 5 -> 1 -> 3으로 돌아온다 3번만에 한사이클을 수행한다.
 2 -> 2  계속 사이클을 돌며
 6-> 4 -> 6 4,6은 2번만에 한사이클을 돈다.
 각각의 사이클의 수가 다르므로 이를 최소 공배수 하면 총 궤적이 몇번 수행되어야 원래대로 돌아오는지 알수있다.
 ? 왜 최소 공배수인가 ? 3번 3번 돌고 2번 2번 2번 돌게 되어 최종수가 나타나므로 최소공배수를 생각할수있다.

 문제를 잘읽고 중복된것이 무엇인지 항상 찾자.

 

*/


int arr[20000];
bool same[20000];

int gcd(int a, int b){ return b? gcd(b,a%b):a;}

int lcm(int a, int b){
	return a / gcd(a,b)*  b;
}

int checkCycle(int start){
	int cycleCnt = 1;
	int next = arr[start];

	while(true){
		if(start == next)
			return cycleCnt;
		
		same[next] = true;
		next = arr[next];
		cycleCnt++;
	}
    return 0;
}

int main(){

	int n;
	cin >> n; 
	for(int i= 1; i<=n; i++){
		cin >> arr[i];
	}
	int ans =1;
	for(int i = 1; i<=n; i++){
		if(same[i]) continue;
		ans = lcm(ans, checkCycle(i));
	}
	cout <<  ans;


	// 시간을 계산하지 않고 작성한 코드
	// while(true){
	// 	cnt++;
	// 	for(int i = 0; i<n; i++)
	// 		tmp[i] = card[arr[i]-1];

	// 	first = 1;
	// 	for(int i = 0; i<n; i++){
	// 		card[i] = tmp[i];
	// 		if(card[i] != i+1)
	// 			first = 0;		
	// 	}
	// 	if(first == 1)
	// 		break;
	// }
	return 0;
}