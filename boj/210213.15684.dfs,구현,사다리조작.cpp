#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;
#define INF 987654321
#define hash 1000000007LL
typedef long long ll;
typedef pair<int,int> pii;
const int MAX = 1001;

void swap(int &a1, int &a2){
    int tmp = a1;
    a1 = a2;
    a2 = tmp;
    return;
}

int max(int i1,int i2){
    return i1> i2? i1:i2;
}


struct Lifting_Info{
    typedef struct Cod{int r, c;} cod;
    cod canBuild[300];

    int liftCnt; // 가로선의 갯수
    bool lift[31][11];
    int n,m,h;

    void init(){
        cin >> n >> m >> h;
        liftCnt = 0;
        memset(lift,false, sizeof(lift));
        int in1,in2;
        /**
         * 사다리를 2차원 배열로 표현하였다.
         * 세로줄을 기준으로 가로선을 놓을수있는데 가로선을 보면 세로줄사이에 위치한다. 
         * 이를 기반으로 세로줄-1을 배열의 column으로 설정하였다. 
         * 가로줄은 h를 row로 설정하였다. 
         * 추후 1.다른 함수에서 사다리의 내려가는 것과
         * 2. 어떤 가로선을 체크해야하는지
         * 1,2을 진행할 함수를 만든다. 
        */
       
        while(m--){ // 사다리에 가로선을 표현
            cin >> in1  >> in2;
            lift[in1][in2] = true;
        }
        /**
         * 가로선은 좌우와 겹치면 안되므로 column을 3개 확인하여 설정하였다. 
         * 놓은수잇는 가로선 
        */
        for(int r = 1; r <= h; r++){ 
            for(int c =1 ; c< n; c++){
                if( !lift[r][c-1] && !lift[r][c] && !lift[r][c+1]){
                    canBuild[liftCnt].r = r;
                    canBuild[liftCnt].c = c;
                    liftCnt++;
                }
            }
        }
    }

    /*
        추가할 가로선을 가지고 1,2,3일때 조합을구하여 ok 되는지 확인하는 재귀
    */
    int change(int index, int cnt, int changed){

        // idx : 추가할수있는 가로선 배열의 idx
        // cnt : 추가한 가로선의 cnt
        // changed : 종료를 위해서 나타낸 변수 및 
        int res = -1;
        
        /** 기저조건
         * cnt == changed 의미는 가로선 하나가 변해서 
         * i번째가 i 가 나온다는 의미 
        */
        if(cnt == changed){ 
            if(ok()){
                return cnt;
            } 
            else return -1;
        }

        // index == liftCnt 가 된다면 추가할 가로선 배열(canBuild)을 모두 돌았다는 의미
        if(index == liftCnt) return -1; 

        int r = canBuild[index].r, c = canBuild[index].c;

        // 가로선 1개일때 ,2개일때 3개일때 확인해야하므로 조합사용 
        if(!lift[r][c-1] && !lift[r][c] && !lift[r][c+1]){
            lift[r][c] = true;
            res = change(index +1 , cnt , changed+1);
            lift[r][c] = false;
        }

        // 모든 조합을 탐색하고 결과값이 나오면 반환
        if(res != -1) return res;

        // 모든 조합을 탐색하고 결과값이 안 나오면 조합을 사용치 않고 진행
        // 각 cnt별 인덱스 순차탐색
        res = change(index+1, cnt, changed);
        return res ;
    }

    /**
     * 재귀를 통해서 가로선을 놨을경우를 완탐하였다. 
     * 사다리는 1에서 출발하여 가로선이 있으면 2로 간다 
     * 가로라인에 가로선이 존재하면 2가 1로 진행된다. 
     * 
     * 이러한 아이디어를 참고하여 일차원 배열에서 lift를 확인하여  swap한다.
     * 결국 마지막 가로선에 i번째가 i인지 확인하는 ok()이다. 
    */
    bool ok(){

        int num[11];

        for(int i = 1; i<=n; i++){
            num[i] = i;
        }

        for(int i = 1; i<=h ;i++){
            for(int j = 1; j<n ; j++){
                if(lift[i][j])
                    swap(num[j],num[j+1]);
            }
        }

        for(int i = 1; i<=n ; i++){
            if(num[i] != i) return false;
        }
        return true;
    }


}liftingInfo;

int main(){

    // init()를 통해서 입력및 셋팅
    liftingInfo.init();

    // 가로선이 올수있는 경우가 많을때는 3개만 설정해야하므로 재설정
    int max = liftingInfo.liftCnt > 3 ? 3 : liftingInfo.liftCnt;

    // max까지 가로선 탐색
    for(int i = 0; i<=max; i++){
        int res = liftingInfo.change(0,i,0);
        if(res != -1){
            cout << res << "\n";
            return 0;
        }
    }

    cout << -1 <<"\n";
    return 0;

}