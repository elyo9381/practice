#include <bits/stdc++.h>

#define endl "\n"
#define MX 3000

using namespace std;

/*
	자기자신을 다시 호출할 때에는 현재 함수에서의 입력값보다 
	저 작은 갑을 인자로 넘겨주어야 합니다. 

	함수의 입력값이 일정 크기 이하일 때에는 더 이상 
	자기 자신을 호출하지 말고 값을 반환해야 합니다.
	이러한 하위 문제를 base condition 이라고 부릅니다.

	별찍기 문제는 리커전이 필요하고 
	division_conquest 를통해서 풀어야한다. 
	입력이 3,9,27 이 올며 3,9일때의 규칙을 통해서 규칙을 찾는다.
	분할되어서 (0,0) (0,3) (0,6)일 때 분할되어서 실행될 규칙도 찾아야한다. 
	
*/

char MAP[MX][MX];

void Init()
{
	memset(MAP, ' ', sizeof(MAP));
}

void solve(int n , int x, int y)
{
	if(n == 1){
		MAP[x][y] = '*';
		return ;
	}

	int div = n/3;
	for( int i=0; i<3;  i++){
	for( int j = 0; j <3 ; j++){
	if( i == 1 && j ==1 ){
	continue;
	}
	solve(div, x+(div*i), y + (div*j));
	}
	}

	return ;
}

int main()
{
	int n;
	cin >> n ;

	Init();
	solve(n,0,0);

	for(int i = 0; i<n ; i++){
		for( int j = 0; j <n ; j++){
		cout<< MAP[i][j];
		}
		cout<< endl;
	}
	return  0;
}