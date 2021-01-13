#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
typedef long long ll;
#define hash 1000000007LL;
using namespace std;
const int MAX = 1000002;

int main(){

    int m;
    cin >> m;

    int lv = 1, rv = 1e9, mid,cnt,ans;

    bool f = false;

    while(lv <= rv){
        cnt = 0;
        mid= (lv+rv)/2;
        for(int i = 5; i<=mid; i*=5)
            cnt+= mid/i;
        if( m <= cnt){
            if( m == cnt){
                f = true;
                ans = mid;
            }
            rv = mid -1;
        } else {
            lv = mid +1;
        }
    }
    if(!f)
        cout <<  -1 ;
    else
        cout << ans;
}