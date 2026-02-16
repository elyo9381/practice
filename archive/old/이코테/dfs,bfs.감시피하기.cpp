#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

/*
    문제 해결을 위해서는 조합과 선생님 시야에서 감시가 안되었다는
    check함수가 있어야한다. 

    조합은 dfs를 이용해서 만들수있었지만
    선생님 시야에서 사방위 일직선상 감시는 구현하지 못하여 
    오랜시간이 결렸다. 
    감시를 재귀로 구현하려다 실패하고 loop사용하여 구현하기로 하였다. 

*/

int n;
char map[6][6];
char tmp[6][6];
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };
vector<pair<int,int> > pmu(3);
vector<pair<int,int> > o;
vector<pair<int,int> > ss;
bool f, found;


bool check(pair<int,int> pt) {
	for(int i = 0; i<4; i++){
		int nx = pt.first;
		int ny = pt.second;
		while (1){
            // dx,dy를 이용하여 일직선상으로 계속 나아간다.
			ny += dy[i];
			nx += dx[i];
            // 직선상의 범위를 벗어나면 그만 멈춘다.
			if (nx < 0 || ny < 0 || nx >n -1 || ny > n - 1 || tmp[nx][ny] == 'O') break;
            // 학생이 감지되면 반환한다.
			if (tmp[nx][ny] == 'S') {
				return true;
			}
		}
	}
    // 학생이 감지 되지 않았다는 의미
	return false;
}

// bool watch(int x, int y, int direction) {
//     // 왼쪽 방향으로 감시
//     if (direction == 0) {
//         while (y >= 0) {
//             if (tmp[x][y] == 'S') { // 학생이 있는 경우
//                 return true;
//             }
//             if (tmp[x][y] == 'O') { // 장애물이 있는 경우
//                 return false;
//             }
//             y -= 1;
//         }
//     }
//     // 오른쪽 방향으로 감시
//     if (direction == 1) {
//         while (y < n) {
//             if (tmp[x][y] == 'S') { // 학생이 있는 경우
//                 return true;
//             }
//             if (tmp[x][y] == 'O') { // 장애물이 있는 경우
//                 return false;
//             }
//             y += 1;
//         }
//     }
//     // 위쪽 방향으로 감시
//     if (direction == 2) {
//         while (x >= 0) {
//             if (tmp[x][y] == 'S') { // 학생이 있는 경우
//                 return true;
//             }
//             if (tmp[x][y] == 'O') { // 장애물이 있는 경우
//                 return false;
//             }
//             x -= 1;
//         }
//     }
//     // 아래쪽 방향으로 감시
//     if (direction == 3) {
//         while (x < n) {
//             if (tmp[x][y] == 'S') { // 학생이 있는 경우
//                 return true;
//             }
//             if (tmp[x][y] == 'O') { // 장애물이 있는 경우
//                 return false;
//             }
//             x += 1;
//         }
//     }
//     return false;
// }

// bool process() {
//     // 모든 선생의 위치를 하나씩 확인
//     for (int i = 0; i < ss.size(); i++) {
//         int x = ss[i].first;
//         int y = ss[i].second;
//         // 4가지 방향으로 학생을 감지할 수 있는지 확인
//         for (int i = 0; i < 4; i++) {
//             if (watch(x, y, i)) {
//                 return true;
//             }
//         }
//     }
//     return false;
// }


void dfs(int s, int L){
	if( L == 3){
			for(int i = 0; i<n; i++){
				for(int j = 0; j<n; j++){
					tmp[i][j] = map[i][j];
				}
			}

			for(int i = 0; i<pmu.size(); i++){
				tmp[pmu[i].first][pmu[i].second] = 'O';
			}

			// if (!process()) {
            // // 원하는 경우를 발견한 것임
            // found = true;
            // return;
        	// }

			for(int i = 0; i< ss.size(); i++){
                //check가 true이면 학생이 감지된것이고 
                // 전혀 감지되지 않아야 우리가 원하는 답이다.
				if(check(ss[i])){
					return ;
				}
			}
			cout << "YES";
			exit(0);


	} else {
		for(int i = s; i<o.size(); i++){
			pmu[L] = o[i];
			dfs(i+1, L+1);
		}
	}
}



int main(void){

	cin >> n;
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			cin >> map[i][j];
			if(map[i][j] == 'X'){
				o.push_back(make_pair(i,j));
			}
			if( map[i][j] == 'T'){
				ss.push_back(make_pair(i,j));
			}
		}
	}

	dfs(0,0);

	cout << "NO";
	return 0;
}