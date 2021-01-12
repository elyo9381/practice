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
    int tt =top.size(), tb = bottom.size();
    for(int i = 1; i<=h; i++){
        b_obs = tb - (lower_bound(bottom.begin(),bottom.end(), i)- bottom.begin());
        t_obs = tt - (lower_bound(top.begin(),top.end(), h-i+1)- top.begin());
        if( t_obs + b_obs == ans){
            cnt+=1;
        }else if( t_obs + b_obs < ans){
            ans = t_obs + b_obs;
            cnt=1;
        }
    }
    cout << ans <<" "<<  cnt<<'\n';
}

