#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main(){

	string s;

	cin >> s;

	int cnt0 = 0, cnt1 =0;

	if(s[0] == '1')
		cnt1 +=1;
	else 
		cnt0 +=1;

	for(int i = 0; i<s.size()-1; i++){
		if(s[i] != s[i+1]){
			if(s[i+1] == '1')
				cnt1 +=1;
			else
				cnt0 +=1;
		}
	}

	cout << min(cnt0, cnt1) <<endl;
}	