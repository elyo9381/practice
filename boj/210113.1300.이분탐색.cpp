#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
typedef unsigned long long ll;
#define hash 1000000007LL;
using namespace std;


int main(){

    int n, k ;
    cin >> n >> k;

    int lv = 1, rv = k, ans;
    while(lv<=rv){
        ll cnt = 0;
        int mid = (lv + rv) / 2;
        for(int i = 1; i<= n ; i++){
            cnt += min(mid/i,n);
        }
        if(cnt < k) lv = mid +1;
        else ans = mid, rv = mid -1;
    }


    cout << ans <<'\n';

}