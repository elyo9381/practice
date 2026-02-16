#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

/*
    이문제는 생각의 확장이 필요한 문제였다. 
    나는 완탐을 생각하긴 하였으나. 그 다음 접근이 안되었다. 
    로테이션 함수만드는데서부터 막혔다... 
    로테이션 만들고 아래로 오른쪽으로 내려리고 접근하였는데 
    이러한 접근은 한번 회전하고 그다음이 어렵다.

    그렇다면 쉬운 접근은 자물쇠의 공간에 
    키의 공간이 맞게 되는 것을 찾는것이므로
    자물쇠의 공간을 3배 키우고 키를 자물쇠의 공간에 더하여 1만
    존재하는 경우를 찾는것이다. 
    아니라면 키의 값을 자물쇠에서 다시 빼줘야한다. 


*/

vector<vector<int> > rotateMatrixBy90Degree(vector<vector<int> > a){
    int n = a.size();// 행 길이 계산
    int m = a[0].size(); // 열 길이 계산
    vector<vector<int> > result(n, vector<int> (m)); // 결과리스트;
    for(int i = 0; i<n ; i++){
        for(int j = 0; j<m; j++){
            result[j][n-i-1] = a[i][j];
        }
    }
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            result[n-j-1][i] = a[i][j];
            cout << result[i][j];
        }
        cout << '\n';
    }
    return result;
}

bool check(vector<vector<int> > newLock){
    int lockLength = newLock.size() / 3;
    for(int i = lockLength; i<lockLength * 2; i++){
        for(int j = lockLength; j<lockLength * 2 ; j++){
            if(newLock[i][j] != 1) {
                return false;
            }
        }
    }
    return true;
}

bool solution(vector<vector<int> > key, vector<vector<int> > lock) {
    int n = lock.size();
    int m = key.size();
    
    vector<vector<int> > newLock(n*3, vector<int>(n *3));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            newLock[i+n][j+n] = lock[i][j];
        }
    }
    
    for(int rotation = 0; rotation < 4; rotation++){
        key = rotateMatrixBy90Degree(key);
        for(int x = 0; x<n*2; x++){
            for(int y = 0; y<n*2; y++){
                
                for(int i = 0; i<m; i++){
                    for(int j = 0; j<m; j++){
                        newLock[x+i][y+j] += key[i][j];
                    }
                }
                
                if(check(newLock)) return true;
                
                for(int i = 0; i<m; i++){
                    for(int j = 0; j<m; j++){
                        newLock[x+i][y+j] -= key[i][j];
                    }
                }
            }
        }
    }
    return false;
}