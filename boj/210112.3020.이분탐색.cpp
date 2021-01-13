#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <math.h>
typedef long long ll;
#define hash 1000000007LL;
using namespace std;
const int MAX = 1000002;

int n , h , L;
vector<int> top,bottom;
pair<int,int> temp;


int bs_lo(vector<int> vec, int x){

    int res = 0, i, lv = 0, rv = n/2-1, mid ;

    while(lv<=rv){
        mid = (lv+rv)/2;
        if(x > vec[mid]){
            lv = mid +1;
        } else {
            rv = mid -1;
        }
    }
    return n/2 - lv;
}

int main(){

    int cnt = 0;
    cin >> n >> h;

    int ans = n;
    top.resize(n/2);
    bottom.resize(n/2);

    for(int i = 0; i<n/2; i++){
        cin >> bottom[i];
        cin >> top[i];
    }

    sort(top.begin(),top.end());
    sort(bottom.begin(),bottom.end());

    int t_obs = 0, b_obs = 0;
    int tt = top.size(), tb = bottom.size();
    for(int i = 1; i<=h; i++){
        // b_obs = tb - (lower_bound(bottom.begiin(),bottom.end(), i) - bottom.begin());
        // t_obs = tt - (lower_bound(top.begin(),top.end(), h-i+1) - top.begin());
        b_obs = bs_lo(bottom,i);
        t_obs = bs_lo(top,h-i+1);
        // cout << b_obs << " " << t_obs <<'\n';
        if( t_obs + b_obs == ans){
            cnt+=1;
        }else if( t_obs + b_obs < ans){
            ans = t_obs + b_obs;
            cnt=1;
        }
    }
    cout << ans <<" "<<  cnt<<'\n';
}

