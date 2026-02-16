#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
#include <math.h>
#include <cstring>

using namespace std;
#define hash 1000000007LL;
typedef long long ll;
typedef pair<int,int> pii;
const int MAX = 100001;


using namespace std;

int N, r, c;
int x, y, ans;

void solve(int x, int y,int n) {

    if (x == r && y == c) {
        cout << ans << "\n";
        return;
    }


    if (r < x + n && r >= x && c < y + n && c >= y) 
    {
        solve(x, y, n / 2);
        solve(x, y + n / 2, n / 2);
        solve(x + n / 2, y, n / 2);
        solve(x + n / 2, y + n / 2, n / 2);
    }
    // (r,c)가 현재 사분면이 아니면 그냥 사분면의 크기만큼 더해준다 (탐색한걸로 친다)
    else ans += n* n;

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> r >> c;

    solve(0, 0, (1 << N));

    return 0;
}