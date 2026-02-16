#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <math.h>
typedef long long ll;
#define hash 1000000007LL;
using namespace std;
const int MAX = 1000001;


int n, m , l;
vector<int> saro;

int main(){
    
    cin >> m >> n >> l;
    saro.resize(m);

    for(int i = 0;i<m; i++){
        cin >> saro[i];
    }

    sort(saro.begin(), saro.end());

    int cnt = 0;
    while(n--){
        int lv = 0, rv = n-1, mid, a,b ,tmp = 0;
        cin >> a >> b;
        tmp = l - b;
        if(tmp < 0) continue;

        if(upper_bound(saro.begin(),saro.end(),a+tmp) - lower_bound(saro.begin(),saro.end(),a-tmp) > 0){
            cnt++;
        }

    }
    cout << cnt << '\n';

}
