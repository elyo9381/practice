#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h> 
#include <deque>
#include <math.h>
typedef unsigned long long ll;
const int MAX = 1000000;
using namespace std;

long long arr[1000000];

int main() {
	int n;
	scanf("%d", &n);
	n *= n;
	long long tot = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%lld", &arr[i]);
		tot += arr[i];
	}

    // cout << tot<<'\n';

    // for(int i = 0; i<n ;i++){
    //     cout << arr[i] << ' ';
    // }

    // cout << '\n';
	long long l = 0, r = 1e7, ans = 1e7;
	while (l <= r) {
		long long m = (l + r) / 2;
		long long t = 0;
		for (int i = 0; i < n; ++i){
			t += min(arr[i], m);
            cout << " t : " << t << " arr[i] : " << arr[i] <<" m : "<< m<< '\n';
        }


		if (t >= (tot +1) / 2) {
			ans = min(ans, m);
			r = m - 1;
		}
		else
			l = m + 1;
	}

	printf("%lld\n", ans);

	return 0;
}