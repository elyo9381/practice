#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h> 

using namespace std;

typedef unsigned long long ll;
#define MAX 50002
 
int T, K;
int mat[MAX];
vector<int> v;
vector<int> l;
 
//에라토스테네스의 체
void func() {
    for(int i = 1; i < MAX; i++) {
        mat[i] = i;
    }
    for(int i = 2; i < MAX; i++) {
        if(!mat[i]) {
            continue;
        }
        else {
            v.push_back(i);
        }
        for(int j = i + i; j < MAX; j += i) {
            mat[j] = 0;
        }
    }
}
 
int main() {
    func();
    
    //구한 소수를 서로 곱하는 과정
    for(int i = 0; i < v.size() - 1; i++) {
        for(int j = i + 1; j < v.size(); j++) {
            if(i != j) {
                l.push_back(v[i] * v[j]);
            }
        }
    }
    
    //오름차순 정렬
    sort(l.begin(), l.end());
    
    cin >> T;
    while(T--) {
        cin >> K;
        int ans = 0;
        int left = 0, right = l.size() - 1;
        while(left <= right) {
            int mid = (left + right) / 2;
            if(l[mid] >= K) { //현재 찾은 값이 K이상이면 답으로 현재 위치를 갱신하고 범위를 작은 쪽으로 줄인다.
                ans = mid;
                right = mid - 1;
            }
            else { //현재 찾은 값이 K보다 작으면 범위를 큰 쪽으로 줄인다.
                left = mid + 1;
            }
        }
        cout << l[ans] << '\n';
    }
 
    return 0;
}