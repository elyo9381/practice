#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

/**
 * 
 * 조건
 * 1,0 상태를 가진다.
 * i-1, i , i+1의 세개의 전구의 상태가 바뀜
 * 
 * 
 * 설계
 * 각각 스위치를 켰을때 최선인지 확인??? fail
 * 
 * 전구를 두번이상 누르면 손해이다 왜냐? 최소값으록 구할수없기 때문이다.
 * 그렇다면 어떻게? 한번씩 누르는게 베스트이다. 순차적으로 
 * 또한 영향을 주는 스위치가 존재하므로 첫스위치가 눌렸는지 않눌렸는지 2가지 방법으로 풀이한다.
 * 
 * 2가지 방법에서 최선의 방법
 * 
*/

const int INF = int(1e9);

int main() {
	int n, mn = INF; string a, b; cin >> n >> a >> b;
	{
		int cnt = 0;
		string s = a;
        // 안누름 
		for (int i = 1; i < n; i++) {
            
			if (s[i - 1] != b[i - 1]) {
				s[i - 1] = !(s[i - 1] - '0') + '0';
				s[i] = !(s[i] - '0') + '0';
				if (i + 1 < n) s[i + 1] = !(s[i + 1] - '0') + '0';
				cnt++;
			}
		}
		if (s == b) mn = min(mn, cnt);
	}
	{
		int cnt = 1;
		string s = a;
        // 눌럿다는걸 표시하기 위함
		s[0] = !(s[0] - '0') + '0';
		s[1] = !(s[1] - '0') + '0';
		for (int i = 1; i < n; i++) {
			if (s[i - 1] != b[i - 1]) {
				s[i - 1] = !(s[i - 1] - '0') + '0';
				s[i] = !(s[i] - '0') + '0';
				if (i + 1 < n) s[i + 1] = !(s[i + 1] - '0') + '0';
				cnt++;
			}
		}
		if (s == b) mn = min(mn, cnt);
	}
	cout << (mn == INF ? -1 : mn) << '\n';
}