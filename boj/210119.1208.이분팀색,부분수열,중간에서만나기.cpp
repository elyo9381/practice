#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <math.h>

using namespace std;
#define hash 1000000007LL;
typedef long long ll;
typedef pair<int,int> pii;
const int MAX = 987654321;
 

int A[20], B[20];

int main(){

    int n , s;

    cin >> n >> s;

    int as = n/2, bs = n-as;
    for(int i=0;i<as; i++) cin >> A[i];
    for(int i=0;i<bs; i++) cin >> B[i];

    vector<int> a;
    vector<int> b;

    for(int i = 0; i<(1<<as) ; i++){
        int sum = 0;
        for(int k = 0; k<as; k++){
            if(i & (1<<k)){
                sum += A[k];
            }
        }
        a.push_back(sum);
    }

    for(int i = 0; i<(1<<bs); i++){
        int sum = 0; 
        for(int k = 0; k<bs; k++){
            if( i & (1<<k)){
                sum += B[k];
            }
        }
        b.push_back(sum);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll ans = 0;

    for(int i = 0; i<b.size(); i++){
        int temp = s - b[i];
        auto hi = upper_bound(a.begin(), a.end(),temp);
        auto lo = lower_bound(a.begin(), a.end(),temp);
        ans += hi - lo;
    }

    if(s == 0) ans--;
    cout << ans <<"\n";
}