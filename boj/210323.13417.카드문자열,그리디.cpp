#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue> 


/**
 * 
 * 조건
 * 왼쪽에 있는 카드부터 차례대로 한장씩 가져옴
 * 그리고 가져온 카드셋의 좌우로 놓을수있음
 * 
 * 카드문자열 중 사전순으로 가장빠른 문자열 구하라 
 * 
 * 설계
 * 큐와 덱을 이용한다.
 * 큐를 이용해서 입력을 받고 
 * 덱과 큐를 비교하여 덱에 조건에 따라 front에 넣고 back뒤에 넣는다.
 * 
 * 
*/

using namespace std;

int main()
{
	char c;
	int i, t, n;
	cin >> t; // 테스트 횟수
	while (t > 0)
	{
		deque <char> str;
		queue <char> q;
		cin >> n;
		for (i = 0; i < n; i++) {
			cin >> c;
			q.push(c); 
		}
        if (str.size() == 0) { 
            str.push_back(q.front());
            q.pop();
        };
		for (i = 1; i < n; i++) {
			if (q.front() <= str.front()) { // 아스키 코드 값이 작으면 덱의 앞에 저장
				str.push_front(q.front());
				q.pop();
			}
			else if (q.front() > str.front()) {
				str.push_back(q.front());
				q.pop();
			}

		}
		for (i = 0; i < n; i++) {
			cout << str.front();
			str.pop_front();
		}
		cout << endl;
		--t;
	}
	return 0;
}