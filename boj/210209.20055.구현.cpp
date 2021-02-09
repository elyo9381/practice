#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int N, K;
int zerocount;
int p = 0;
int barr[201];
bool robo[101];

void ratate() { //barr[0]는 그냥 tmp용으로 사용
	barr[0] = barr[2 * N];
	for (int i = 2 * N; i >= 2; i--) { //벨트이동
		barr[i] = barr[i - 1];
	}
	for (int i = N - 1; i >= 1; i--) { //로봇이동
		robo[i + 1] = robo[i];
	}
	robo[1] = false;
	barr[1] = barr[0];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> K;
	for (int i = 1; i <= 2*N; i++) {
		cin >> barr[i];
		if (barr[i] == 0) zerocount++;
	}
	while (1) {
		if (zerocount >= K) break;
		p++;
		ratate();
		if (robo[N] == true) { //내려오는 칸
			robo[N]= false;
		}
		for (int i = N - 1;  i >= 1; i--) { //이동관련
			if (robo[i] == true) {
				if (robo[i + 1] == false && barr[i + 1] >= 1) {
					robo[i] = false; robo[i + 1] = true;
					barr[i + 1]--;
					if (barr[i + 1] == 0) zerocount++;
				}
			}
		}
		if (robo[1] == false && barr[1] >= 1) { //올라가는 칸
			robo[1] = true; barr[1]--;
			if (barr[1] == 0) zerocount++;
		}
	}
	cout << p << "\n";
	return 0;
}