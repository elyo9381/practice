#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
typedef long long ll;
using namespace std;
const int MAX = 100001;

#define hash 1000000007LL


int main() {

	unordered_map <ll, int> h;
	ll a = 1, b = 1, c;
	h[1] = 2;
	for (int i = 3; i <= 120000; i++) {
		c = a + b;
		c %= hash;
		h[c] = i;
		a = b;
		b = c;
	}

	int t;
    cin >> t;

	while (t--) {

        string str;
        cin >> str;
		ll k = 0;

		for (int i = 0; i < str.size(); i++) {
			k = k * 10 + str[i] - '0';
			k %= hash;
		}

        cout << h[k] <<'\n';
	}

}