#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h> 
#include <deque>

using namespace std;
typedef unsigned long long ll;
const int MAX = 100001;

int n,k,b;

int main(){

    cin >> n >> k >> b;
    bool arr[MAX] = {false};

    for(int i = 0; i<b; i++){
        int num;
        cin >> num;
        arr[num]=true;
    }

    int lv = 0, rv = 1000000;
    int res = 100000;

    while(lv<=rv){
        int mid = (lv + rv) / 2;
        bool flag = false;
        deque<int> window;

        //덱을 사용한 슬라이딩 윈도우로 연속한 k개의 신호등이 연속돼 있는지 확인한다.
        for(int i = 1; i<=n; i++){
            if(i > k &&  !window.empty() && window.front() <= i-k)
                window.pop_front();
            if(!arr[i])
                window.push_back(i);
            if(i>=k && k - window.size() <= mid)
                flag = true;
        }

        if(flag){
            res = min(res,mid);
            rv = mid-1;
        } else {
            lv = mid+1;
        }
    }

    cout << res <<'\n';
}