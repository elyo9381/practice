#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

/*
    x,y를 입력 받으면 y를 기준으로 내림차순 정렬을 진행한다. 
    y를 기준으로 내림차순 정렬하는 이유는 
*/
int n;
 
int main() { 
    scanf(" %d", &n);
    priority_queue<pair<int, int> > pq;
 
    for (int i = 0; i < n; i++) {
        int x, y; scanf(" %d %d", &x, &y);
        x += 300; y += 300;
        pq.push(make_pair( y,x ));
    }
    int ans = 1;
 
    int pos = pq.top().second; pq.pop();
    while (!pq.empty()) {
        int x = pq.top().first;
        int y = pq.top().second;
        pq.pop();
        if (x >= pos) pos = max(pos, y);
        else {
            ans += 1; pos = y;
        }
    }

    printf("%d\n", ans);
}
