#include <iostream>
#include <algorithm>
using namespace std;
 
const int maxv = 100000, maxe = 200000;
int a[maxe], b[maxe], nxt[maxe], st[maxv], np = 2;
void add(int x, int y) {
    a[np] = x; b[np] = y; nxt[np] = st[x]; st[x] = np++;
}
int v, e;
 
int main() {
    cin >> v >> e;
    for (int i=1; i<=e; i++) {
        int x, y;
        cin >> x >> y;
        add(x, y);
    }
    
    for (int i=1; i<=v; i++)
        for (int j=st[i]; j; j=nxt[j])
            cout << a[j] << " and " << b[j] << " are connected.\n";
}


//가중치 코드이다. 
// 간선의 순서를 절적히 섞어 주어야하는 상황에선 
// 사용하면 안된다 ex)크루스칼 알고리즘
// #include <iostream>
// using namespace std;
 
// const int maxv = 100000, maxe = 200000;
// int a[maxe], b[maxe], w[maxe], nxt[maxe], st[maxv], p = 2;
// void add(int x, int y, int wt) {
//     a[np] = x; b[np] = y; w[np] = wt; nxt[np] = st[x]; st[x] = p++;
// }
// int v, e;
 
// int main() {
//     cin >> v >> e;
//     for (int i=1; i<=e; i++) {
//         int x, y, w;
//         cin >> x >> y >> w;
//         add(x, y, w);
//     }
 
//     for (int i=1; i<=v; i++)
//         for (int j=st[i]; j; j=nxt[j])
//             cout << a[j] << " and " << b[j] << " are connected in weight " << w[j] << ".\n";
// }

