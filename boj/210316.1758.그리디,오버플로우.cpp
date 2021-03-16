#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

/**
 * 
 * 조건
 * - 8시가 되는 순간 모든 손님들은 커피를 받음
 * - 커피를 받는순간 팁을줌( 몇번째 받았는지에 따라 팁이다름)
 *  - 원래주고려 했던 ( 돈 - (받은등수 -1) ) 의 팁을 줌
 *  - 음수이면 팁을 받을수없음
 * 
 * 설계 
 * 1, 입력을 그대로 받고 루프돌며 바로 계산 : fail
 * 2, 순서를 적절히 바꿨을때를 보고 순열 생각 : fail(timeover)
 * 3, 순서를 적절히 바꿧을때 최대값은 오름차순 : fail
 *
 * N이 100000이고 빼는 수가 0~99999이다. 이때 N이 10만이라고 가정하면
 * 10만을 5만번 곱하게 된다. 
 * 
*/

int N;
vector<int> people;

bool compare(int i,int j){
    return j < i;
}

int main(){

    cin >> N;

    long long ret = 0;

    for(int i = 0; i<N; i++){
        int a;
        cin >> a;
        people.push_back(a);
    }

    // 순서를적절히 바꾼다.

    sort(people.begin(),people.end(), compare);

        for(int i = 0; i<N; i++){
            long long sum = 0;
            sum = people[i] - i;
            if(sum < 0) sum = 0;
            ret += sum;
        }
    cout << ret <<"\n";
}
