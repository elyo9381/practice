#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
나는 소가있는 외양간 c를 m으로 나눈 나머지와 몫을 통해서 배열을 만들고 이를 완탐하려고 하였는데
이 방법으로 풀지 못했다. n^3 시간복잡도가 걸릴뻔하였다. 내가 구상한대로 풀었다면...

아래의 풀이는 소가없는 외양간을 확인하여 이를 기반으로 판자를 둔다
예를들어 3469가 존재하면 하나를 사용할땐 9-3+1이면 판자길이가..
두개를 사용해야할땐 최소길이가 외양간이 없는 78을 빼고 9만 하나로 하고 3456을 판자로 하는것이 최소길이이다.
*/


int main(void){

	int m,s,c;
	int rooms[200];
	int sub[200];

	cin >> m >> s >> c;
	for(int i = 0; i<c; i++){
		cin >> rooms[i];
	}

	sort(rooms, rooms+c);

	// 3468 의 소가 있는 외양간이 존재한다고 할때 46사이에는 5가 있으므로 -1을 해주는것이다.
	for(int i = 0; i< c-1; i++){
		sub[i] = rooms[i+1] - rooms[i] - 1;
	}

	sort(sub,sub+(c-1),greater<int>()); // 내림차순

	int res = rooms[c-1] - rooms[0] +1;
	for(int i = 0; i<m-1 && i<c-1; i++){
		res = res - sub[i];
	}
	cout <<res;
	// re(n);
	// pr();
	return 0;
	
}
 