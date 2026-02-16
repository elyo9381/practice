#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <math.h>
typedef long long ll;
#define hash 1000000007LL;
using namespace std;
const int MAX = 1000002;

int n;
vector<int> v;
pair<int,int> temp;
int ans = 2e9;

int main(){
    cin >> n;
    v.resize(n);
    for(int i = 0; i<n; i++) cin >>  v[i];
    sort(v.begin(), v.end());
    for(int i = 0; i<v.size()-1; i++){
        int lv = i+1, rv = v.size()-1, mid = 0, cur = v[i];
        while(lv<=rv){
            mid = (lv+rv)/2;
            if(ans > abs(cur + v[mid])){
                ans = min(ans, abs(cur + v[mid]));
                temp = make_pair(i,mid);
            }
            if( cur + v[mid] > 0) rv = mid -1;
            else lv = mid+1;
        }
    }
    cout << v[temp.first] << " " <<v[temp.second] << '\n';
}