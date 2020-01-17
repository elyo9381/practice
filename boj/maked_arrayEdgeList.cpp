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
