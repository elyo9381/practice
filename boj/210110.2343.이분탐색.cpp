#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;
const int MAX = 100001;

int n, m ;
vector<int> arr;

bool count(int mid){
    int i, cnt = 1 , sum = 0;

    for(i = 0;i<arr.size(); i++){
        if(arr[i] > mid) return false;
        sum += arr[i];
        if(sum > mid){
            cnt++;
            sum = 0;
            i = i-1;
        }
    }
    return m>=cnt;
}

int main(){
    cin >> n >> m;
    arr.resize(n,0);
    int lv = 0, rv = 1e9 , mid = 0,res = 0 , maxx = 0;

    for(int i = 0; i<n; i++){
        cin >> arr[i];
        rv += arr[i];
        maxx = max(arr[i],maxx);
    }

    while(lv<=rv){
        mid = ( lv + rv)/2;
        if( count(mid)){
            res = mid;
            rv = mid -1;
        } else {
            lv = mid+1;
        }
    }
    cout << res << '\n';
}