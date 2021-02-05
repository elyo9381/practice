#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
    1번째 줄에는 N과 M이 공백으로 주어진다. (1 ≤ N ≤ 100,000, 1 ≤ M ≤ N)

    2번째 줄부터 총 N개의 줄에는 현우가 i번째 날에 이용할 금액이 주어진다. (1 ≤ 금액 ≤ 10000)

    실수 2가지
    ㅇ 금액이 1만 그리고 범위가 10만으로 인트형 범위라고 생각했다. 
    하지만 하나 간과한것은 n이 2이상이고 하루에 써야하는 금액이 1만원이라고 가정한다면
    high가 1만으로는 부족하다 --> 이분탐색하므로 5천으로 줄어들기에 1만을 만족할수없음

    그렇기 때문에 최소 1만의 n명의의 여유 금액으로 high를 측정해야한다. 
    최대 하루에 써야하는 금액은 10억이 올수있다.
    ㅇ 이분탐색으로 접근 mid를 금액으로 놓고 check()까지 수월하였지만 
    여기서 if( mid < day[i]) return false; 를생각하지 못하였다. 

    왜 있어야하나면 일일 써야하는 금액보다 작은 mid로 탐색하면 일일 써야하는 부분에서 계속 루프 돌기때문이다.
    나는 일일 금액 500 일때 그리고 mid 400일때를 가정하여 루프를 돌려 이를 해결하려고 하였는데
    이러면 이분탐색 사용하는 의미가 상실되므로 20번줄의 아이디어를 생각했어야했다.
 */

int n,m;
vector<int> day;

bool check(int mid){
    int i,res,cnt = 0,sum = 0 , c = 0;
    c = day.size();

    for(int i = 0; i<day.size(); i++){
        if( mid < day[i]) return false;
        if( (sum < day[i] ){
            sum = mid;
            cnt++;
        }
        
        sum -= day[i];
        c--;
    }
    if(cnt <= m) return true;
    else return false;
}

int main(){
    cin >> n >> m;

    int low = 1, high =10000 , result = 0;
    high *= n;
    for(int i = 0 ; i<n; i++){
        int num;
        cin >> num;
        day.push_back(num);
    }
    while(low<=high){
        int mid = (low+high)/2;

        if(check(mid)){
            result = mid;
            high = mid-1;
        } else {
            low =mid+1;
        }
    }
    cout << result << '\n';
}