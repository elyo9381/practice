#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h> 
#include <deque>
#include <math.h>
typedef unsigned long long ll;
const int MAX = 200002;
using namespace std;

int n , c;

int count(vector<int> arr, int mid){
    int pos = arr[0], i, res = 0, cnt = 1;

    for(i = 1; i<arr.size(); i++){
        if(arr[i] - pos >= mid){
            cnt++;
            pos = arr[i];
        }
    }
    // cout << mid << " " <<cnt <<'\n';
    return cnt;
}


int main(){

    cin >> n >> c;

    vector<int> arr(n);

    for(int i = 0; i<n ;i++){
        cin >> arr[i];
    }

    sort(arr.begin(),arr.end());

    int lv = 1, rv = 1e9, res = 0;
    while(lv <= rv){
        int mid = (lv+rv)/2;
        if(count(arr,mid) >= c){
            res = mid;
            lv = mid +1;
        } else {
            rv= mid-1;
        }
    }

    cout << res <<'\n';