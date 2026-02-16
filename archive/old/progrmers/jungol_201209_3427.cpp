#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//볼 모으기 문제 RBBBRBRRR 최소의 이동으로 같은색상으로 이동하는 방법
//나는 삽입정렬로 모든 완탐접근을 하였다. 하지만 더이상 진도가 나가지 못했다.
// R과 B중 하나를 큰값으로 생각하고 이를 sort하려고 하였는데 이러면 B가 뒤에 나왔을때 매우 어렵다.
// 제약조건이 N 최대 50만 인것도 한목하였다. 이는 bfs나 dp를 사용하기 벅찬 사이즈이다.
// 그래서 그리디로 풀어야한다. 그리디 접근할지 아니면 탐색할지 내가 잘 판단하자.


int N, Rcnt = 0, Bcnt = 0;
string s;

int main(void){

	cin >> N >> s;
	for(int i= 0; i<s.size(); i++){
		if(s[i] == 'R') Rcnt++;
		else Bcnt++;
	}
	int minN = 2147000000, cnt = 0, idx = 0;
	while(s[idx++] == 'R') cnt++;
	minN= min(minN,Rcnt-cnt);

	idx = N-1, cnt = 0;
	while(s[idx--] =='R') cnt++;
	minN = min(minN, Rcnt-cnt);

	idx = 0, cnt = 0;
	while(s[idx++] == 'B') cnt++;
	minN = min(minN, Bcnt-cnt);

	idx = N-1, cnt = 0;
	while(s[idx--] == 'B') cnt++;
	minN = min(minN, Bcnt-cnt);
	cout << minN;
	return 0;
}
