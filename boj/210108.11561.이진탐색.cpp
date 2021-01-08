#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef unsigned long long ull;
/*
    첫 징검다리는 점프해서 아무 것이나 밟을 수 있다. 이 점프가 첫 점프이다.
    두 번째 점프부터는 이전에 점프한 거리보다 1 이상 더 긴 거리를 뛰어야만 한다.
    N번 징검다리는 반드시 밟아야 한다.
    N번 징검다리를 밟은 후 강 건너로 이동할 땐 점프를 하지 않으므로 위의 규칙이 적용되지 않는다.
    승택이가 위의 규칙을 지키며 강을 건널 때, 밟을 수 있는 징검다리의 최대 수는 몇 개일까?

    밣을 수 있는 징검다리의 최대 수는 첫번쨰 부터 밣았을때 가장 최대이다. 
    처음부터 밣고 이전거리보다 1이상 긴거리는 등차수열이다.
    등차수열의 n번째 값을 구하는 공식은 ((n+1)*n)/2이다.
 */

ull M = 1e16;

bool Can(ull mid, ull num) {
    if (mid >= M) return false;
    return ((1 + mid) * mid) / 2 <= num;
}
 
int main() {
    int q;
    ull x, l, r, mid;
 
    scanf("%d", &q);
    while (q--) {
        scanf("%lld", &x);
        
        l = 1, r = x;
        while (l <= r) {
            mid = (l + r) / 2;
            if (Can(mid,x)) l = mid + 1;
            else r = mid - 1;
        } printf("%lld\n", l - 1);
    }
}
