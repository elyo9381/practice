#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h> 

using namespace std;

typedef unsigned long long ll;

const ll INF = 1e16;
const ll MAX = 1000001;

ll s,c, sum = 0;
int G_onion[MAX];

bool check(ll mid){
    int cnt = 0 , mod = 0;
    
    for(int i = 0; i<s; i++){
        cnt += G_onion[i]/mid;
        if(cnt>=c){
            return true;
        }
    }
    return false;
}

int main(){

    cin >> s >> c;

    for(int i = 0; i<s; i++){
        cin >> G_onion[i];
        sum += G_onion[i];
    }

    ll lv = 1 , rv = 1e9;

    while(lv<=rv){
        ll mid = (lv+rv)/2;

        if(check(mid)){
            lv = mid+1;
        } else {
            rv = mid-1;
        }
    }

    cout << sum - rv * c <<'\n';
}