#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

/*


*/


int main(){

	long long x,y,z;

	cin >> x >> y;

	z =  (y * 100)/x;

	cout << z <<'\n';

	if(z >= 99) {
		cout << -1 <<'\n';
		return 0;
	}

	int start = 0, end = 1e9;
	int res = -1;

	while(start <= end){
		int mid = (start + end) /2;
		// int tmpz = ((y+mid)*100) / (x+mid);
		int tmpz = ((y+mid)*100) / (x+mid);
		cout << "mid : " << mid << " "<< "tmpz : " << tmpz<<'\n';
		if(z >= tmpz){
			res = mid +1;
			start = mid +1;
		} else {
			end = mid-1;
		}
	}

	cout << res <<endl;
	return 0;
}

