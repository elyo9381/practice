#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

/*  어려가지 조건에 해당하는 부분 증가수열을 만족할때는
    정렬미리 할수있으면 미리하는것이 좋다. 
    부분증가수열 부분에 해당하는곳만 
    부분증가수열 또는 부분감소수열을 만들어사용한다. 
*/
struct Brick{
    int s, h, w;

    Brick(int a, int b, int c){
        s = a, h = b ,  w = c;
    }

    bool operator<(const Brick &b)const{
        return s >b.s;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    int n,a,b,c,max_h= 0 ,res = 0;
    cin >> n;
    // 탑을 쌓아야하는데 어려가지 조건이 주어졌으므로 구조체를 사용한다.
    vector<Brick> Bricks; 
    // 구조체에서 부분증가수열이므로 매번 값을 리턴 받기위해 dy선언(dynamic)
    vector<int> dy(n,0);
    // 입력 받는 부분 구조체 혹은 pair를 중첩해서 가능 할것! 
    for(int i =0; i<n ; i++){
        cin >> a >> b >> c;
        Bricks.push_back(Brick(a,b,c));
    }
    // 간단하게 할수있는 조건인 정렬은 구조체의 operator<를 통해서 해결
    sort(Bricks.begin(), Bricks.end());
    // 반환하는 값 h를 계속적으로 반환해야하고 인덱스별 반환해야하므로 dy배열에 저장
    dy[0] = Bricks[0].h;
    // 도출되는 result
    res = dy[0];

    //부분증가 수열
    for(int i = 1; i<n; i++){
        // 높이에 대한 조건은 없으므로 매번 0으로 설정 
        max_h = 0; 
        // i번째와 이전 i-1,i-0, ....i-n으로 비교해야한다.
        for( int j = i-1; j>=0; j--) {
            // 조건 무게가 높은건 낮은거위에 올라올수없는 조건 
            if(Bricks[j].w > Bricks[i].w && dy[j]> max_h){
                max_h  = dy[j];
            }
        }
        // 조건에 만족하는 h와 이전 h를 계속적으로 더해줘야 쌓아지는 현상을 표현가능하다.
        dy[i] = max_h + Bricks[i].h;
        // 결과를 반환
        res = max(res, dy[i]);
    }
    cout << res; 
    return 0;
}