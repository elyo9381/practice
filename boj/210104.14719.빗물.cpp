#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
// 나는 쌉구현으로 풀었는데 주어진 조건으로 안품.. ㅁㅊㄴ
// 수학적인 방법으로 그리고 문제에서 주어진 h를 가지고 푸는방법이다.

// int main() {
//     int N, M, K;
//     int answer = 0;

//     cin >> N >> M;
//     vector<int> v(M);

//     for (int i = 0; i < M; i++)
//         cin >> v[i];

//     for (int i = 1; i < M - 1; i++) {
//         int left = 0; int right = 0;
//         //왼쪽 최대 값
//         for (int j = 0; j < i; j++) left = max(left, v[j]);
//         //오른쪽 최대 값
//         for (int j = M - 1; j > i; j--) right = max(right, v[j]);
//         //빗물 계산
//         answer += max(0, min(left, right) - v[i]);
//     }

//     cout << answer << endl;
//     return 0;
// }


int n,m;

int arr[500];
int map[500][500];


int main(){

	cin >> n >> m;

	int cnt = 0;

	for(int i = 0; i<m; i++){
		cin >> arr[i];
	}

	for(int  i = n-1; i>=0; i--){
		for(int j = 0; j<m ; j++){
			if(arr[j] > 0){
				map[i][j]++;
				arr[j]--;
			}
		}
	}

	for(int i = 0; i<n; i++){
		int f = 0;
		queue<pair<int,int> > q;
		for(int j = 0; j<m ;j++){
			if(map[i][j] == 1){
				if(f == 1 && map[i][j-1] ==0)
					f = 0;
				if(f == 0){
					while(!q.empty()){
						int x = q.front().first;
						int y = q.front().second;
						q.pop();
						map[x][y] = 2;
						cnt+=1;
					}
				}
				f = 1;
			} else {
				if(f == 1){
					q.push(make_pair(i,j));
				}
			}
		}
	}

	
	cout << cnt ;
}