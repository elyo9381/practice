#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main(){
	
	string s;
	int sum  = 0;
	cin >> s;
	vector<char> a;
	for(int i = 0; s[i]!='\0'; i++){
		if(s[i] >=65 && s[i] <=97){
			a.push_back(s[i]);
		} else if( s[i] >=48 && s[i] <=57)
			sum += (s[i]-48);
	}

	sort(a.begin(),a.end());

	for(int i = 0; i<a.size(); i++){
		cout << a[i];
	}
	cout << sum<< '\n';

}	