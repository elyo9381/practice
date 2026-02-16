#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <math.h>

#define hash 1000000007LL;
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAX = 987654321;

bool can(int idx, int n){
    return 0<=idx && idx <n;
}


int main(){

    int t,n,k;

    cin >> t;

    while(t--){
        cin >> k >> n;

        vector<ll> tmp1(n), tmp2(n);
        vector<ll> a,b;
        for(int i = 0; i<n; i++) cin >> tmp1[i];
        for(int i = 0; i<n; i++) cin >> tmp2[i];
        for(int i =0; i<n; i++)
            for(int j = 0; j<n; j++)
                a.push_back(tmp1[i]+tmp2[j]);
        for(int i = 0; i<n; i++) cin >> tmp1[i];
        for(int i = 0; i<n; i++) cin >> tmp2[i];
        for(int i =0; i<n; i++)
            for(int j = 0; j<n; j++)
                b.push_back(tmp1[i]+tmp2[j]);


        sort(a.begin(),a.end());
        sort(b.begin(),b.end());

        ll ans = a[0] + b[0];
        for(int i = 0; i<a.size(); i++){
            ll key = a[i] - k;
            int idx1 = lower_bound(b.begin(), b.end(),abs(key)) - b.begin();
            int idx2 = idx1-1;

            if( can( idx1, b.size() )){
                ll minus = abs(k-ans);
                ll t = abs(k - (a[i] + b[idx1]));
                if(minus > t) ans = a[i] + b[idx1];
                if(minus == t) ans = min(ans, a[i] + b[idx1]);
            }

            if(can(idx2, b.size())){
                ll minus = abs(k-ans);
                ll t = abs(k - (a[i]+b[idx2]));
                if(minus > t) ans = a[i] + b[idx2];
                if(minus == t) ans = min(ans,a[i] + b[idx2]);
            }
        }

        cout << ans << "\n";
    }
}