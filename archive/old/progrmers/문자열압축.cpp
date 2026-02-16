#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

/*
    c++문자열에서 문자를 자를는 substr을 이용하여 
    문자열을 자르고 
    루프를 이용하여서 자른 문자열과 비교하는방법이다.
*/

int main(){
	
	string s;
	int sum  = 0;
	cin >> s;
	bool f = false;
	int len,cnt = 1,minx = 2147000000;
	len = s.size();

	for(int step = 1; step < s.size()/2 + 1 ; step++){
		string compressed = "";
		string prev = s.substr(0, step);
		int cnt = 1;

		for(int j = step; j< s.size(); j+=step){
			if(prev == s.substr(j,step)) cnt +=1;
			else {
				compressed += (cnt>=2) ? to_string(cnt) + prev : prev;
				prev = s.substr(j,step);
				cnt =1;
			}
		}

		compressed += (cnt>=2) ? to_string(cnt) + prev : prev;

		for(int j = 0; j<compressed.size(); j++){
			cout << compressed[j];
		}
		cout << '\n';
		cout << len << " : " << compressed.size() <<'\n';
		len = min(len, (int)compressed.size());
	}

	cout << len <<'\n';	
	// for(int k = 1; k < len/2+1; k++){
	// 	string res = "";
	// 	int c = 0;
	// 	for(int i =0; i<len; i++){
	// 		if(s[i] == s[i+k]){
	// 			f = true; cnt+=1;
	// 		}else {
	// 			f = false; c++;
	// 		}
	// 		if(!f && c == k){
	// 			if(cnt != 1){
	// 				cnt += '0';
	// 				res.push_back(cnt);
	// 			}
	// 			for(int j = i-k+1; j<=c; j++){
	// 				res.push_back(s[j]);
	// 			}
	// 			cnt = 1;
	// 		}
	// 	}
	// 	int ch_min = res.size();
	// 	minx = min(ch_min,minx);

	// for(int i = 0; i<res.size(); i++){
	// 	cout << res[i] ;
	// }
	// cout <<'\n'<< res.size() << '\n';
		
	// }
}	