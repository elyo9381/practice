#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <numeric>



using namespace std;

/**
 * 
 * 조건
 * 주사위의 평면도가 주어지고 주사위는 테이블 위에 놓여있을때
 * 테이블과 접합한 면을 제외한 다른면들의 합을 구하라 
 * 
 * 설계
 * dy,dx를 설정하고 direction 배열을 만들어서 회전시키며 
 * 주사위 이동시 direction을 고려하여 배열 이동시킨다. 실패
 * 
 * 디버그
 * dice를 움직일 생각하면 절대 못푼다 >> 오버플로우
 * 주사위가 n*n*n으로 쌓인다고 나왔으니 최솟값이 되는 경우(규칙)을 찾아야하다.
 * 3면이 보이는곳, 2면이 보이는곳, 1면이 보이는곳들의 주사위의 각면을 이루는 수의 합이 
 * 주사위가 쌓였을때 최소의 값이 된다. 
 * 꼭지점 무조건 4개
 * 모서리 : 지면과 수직인 선분 : 4 * (n-1), 4 * (n-2)
 * 나머지면 : 윗면 >> n-2^2 + 옆면>> 4 * (n-1) * (n-2)
 * 
 * 그리고 각각의 면이 보이는곳의 최솟값을 구하는 구현도 찾아야한다.
 * 
*/

const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};

const int INF = 987654321;
typedef long long ll;

int main(){

    ll n;
    cin >> n;
    vector<int> dice(6);
    for( auto &c : dice){
        cin >> c;
    }

    // 새로운 다이스로 놓는다. 왜? 좀더 편하게 코드를 편하게 작성하려고
    vector<int> new_dice(6);
    new_dice[0] = dice[4];
    new_dice[1] = dice[0];
    new_dice[2] = dice[1];
    new_dice[3] = dice[5];
    new_dice[4] = dice[3];
    new_dice[5] = dice[2];

    if(n==1){
        cout << accumulate(dice.begin(),dice.end(),0) - *max_element(dice.begin(),dice.end()) << "\n";
        return 0;
    }

    // 3면의 최소값 (옆면 2개 더하고 윗면 또는 아랫면) 
    int min_vertex = INF;
    for(int i = 0; i<4; i++){
        int sum = new_dice[i] + new_dice[(i+1)%4];
        for(int j = 4; j<=5; j++){
            min_vertex =  min(min_vertex, sum + new_dice[j]);
        }
    }

    // 2면의 최소값 (2개의 옆면 합, 옆면 + 윗면)
    int min_side = INF;
    for(int i = 0; i<4; i++){
        min_side = min(min_side, new_dice[i] + new_dice[(i+1) % 4]);
        for(int j = 4; j<=5; j++){
            min_side = min(min_side, new_dice[i]+new_dice[j]);
        }
    }


    ll sum = 0;
    sum += min_vertex * 4;
    sum += min_side * (8 * n -12);
    sum += *min_element(dice.begin(),dice.end()) * (5*n*n - 16 * n + 12);
    
    cout << sum << "\n";

    return 0;
}