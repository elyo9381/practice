// #include <cstdio>
// #include <cstdlib>
// #include <iostream>
// #include <sstream>
// #include <algorithm>
// #include <string>
// #include <vector>
// #include <queue>

// using namespace std;
// #define INF 987654321
// #define hash 1000000007LL
// typedef long long ll;
// typedef pair<int,int> pii;
// const int MAX = 1001;

// int arr[MAX];
// int ch[MAX];
// int n,k,cnt =0,zcnt=0;


// void ratate(){

//     int tmp = arr[2*n];
//     for(int i = 2*n; i>=2; i--){
//         arr[i] = arr[i-1];
//     }
//     arr[1] = tmp;

    
//     for(int i = n-1; i>=1; i--){
//         ch[i+1] = ch[i];
//     }

//     ch[1] = 0;

// }

// int main(){

//     cin >> n >> k;

//     for(int i = 1; i <=2*n ; i++){
//         cin >> arr[i];
//     }


//     while(true){

//         if(zcnt >=k )break;
//         // 회전
//         ratate();
//         if(ch[n] == 1){
//             ch[n] = 0;
//         }

//         // 로봇이 이동가능한가
//             for(int i = n-1; i>=1; i--){
//                 // if(i == 2*n) 
//                 if(ch[i] == 1){
//                     if(arr[i+1] !=0 && ch[i+1] == 0) {
//                         arr[i+1]--;
//                         ch[i+1]=1;
//                         ch[i]=0;
//                         if(arr[i+1]== 0) zcnt++;
//                     }
//                 }
//             }
        
//         // 올라가는 위치
//         if(arr[1] != 0 && ch[1] == 0){
//             ch[1] = 1;
//             arr[1]--;
//             if(arr[1] == 0) zcnt++;
//         }
        

//         cnt++;
        

//     }
//     cout <<cnt <<'\n';

// }



#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, m, result = 0,answer = 0, f_res = 0;

vector<pair<int,int> > pmu(3);
int tmp[8][8];

int map[8][8];

queue<pair<int,int> > q;

// 4가지 이동 방향에 대한 배열
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void bfs(int a, int b){
	q.push(make_pair(a,b));
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for(int i = 0 ; i<4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];

			if( nx < 0 || ny <0 || nx >=n || ny >= m) continue;
			if(tmp[nx][ny] == 0){
				tmp[nx][ny] = 2;
				q.push(make_pair(nx,ny));
			}
		}
	}	
}

int getScore() {
    int score = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (tmp[i][j] == 0) {
                score += 1;
            }
        }
    }
    return score;
}



int dfs(vector<pair<int,int> > z,int s, int L){
	if( L == 3){ 

		for(int i = 0;i <n; i++){
			for(int j = 0; j<m; j++){
				tmp[i][j] = map[i][j];
			}
		}

		for(int i = 0; i< 3; i++){
			int px = pmu[i].first;
			int py = pmu[i].second;
			tmp[px][py] = 1;
			// cout << pmu[i].first << pmu[i].second<< '\n';
		}

		for(int i = 0; i<n; i++){
			for(int j = 0; j<m; j++){
				if(tmp[i][j] == 2){
					bfs(i,j);
				}
			}
		}
		result = max(result,getScore());
		return result;

	} else {
		for(int i = s ; i < z.size(); i++){
			pmu[L] = z[i];
			answer = dfs(z,s+1,L+1);
			f_res = max (f_res , answer);
		} 
	}
	return f_res;
}

int main(){

	cin >> n >> m ;

	vector<pair<int,int> > z;

	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			cin >> map[i][j];
			if(map[i][j] == 0){
				z.push_back(make_pair(i,j));
			}
		}
	}



    vector<bool> Binary(z.size());

    fill(Binary.end() - 3, Binary.end(), true);
    
    do{

        for(int i = 0;i <n; i++){
			for(int j = 0; j<m; j++){
				tmp[i][j] = map[i][j];
			}
		}

        for(int i= 0 ; i<Binary.size(); i++){
            if(Binary[i]){
                int px = z[i].first;
                int py = z[i].second;
                tmp[px][py] = 1;
            }
        }

        for(int i = 0; i<n; i++){
			for(int j = 0; j<m; j++){
				if(tmp[i][j] == 2){
					bfs(i,j);
				}
			}
		}
		result = max(result,getScore());
        
        
    } while(next_permutation(Binary.begin(),Binary.end()));

    cout << result;
    


	// cout << dfs(z,0,0);
}
