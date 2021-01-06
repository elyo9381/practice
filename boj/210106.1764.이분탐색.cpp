#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

/*
    이분탐색을 이용하여 문자열 검색하기 
    탐색하기
    가사 찾기에 응용 될는 문제였다. 

    그리고 map을 통해서도 풀수있다. 
    
    이분탐색은 정렬이 되어있어야한다. 

	문자열 이분탐색하는 방법 
	!str.compare(x)를 이용하여 같은지 확인 값이 0이면 같은것
	대소비교는 > or < 연산자를 통해서 할수있음 -> 아스키값.
*/

int n, m;

bool bs(vector<string> &h, int start ,int end, string x){
	if(start> end) return false;
	int mid = (start + end)/2;

	if(!h[mid].compare(x)){
		return true;
	} else if( h[mid] < x ){
		return bs(h,mid+1,end,x);
	} else {
		return bs(h,start,mid-1,x);
	}
}	


int main(){

	vector<string> h;
	vector<string> s;
	vector<string> answer;

	cin >> n  >> m ;

	for(int i = 0; i<n;i++){
		string str;
		cin >> str;
		h.push_back(str);
	}
	sort(h.begin(), h.end());
	
	for(int i= 0 ; i<m; i++){
		string str;
		cin >> str;
		if( bs(h,0,h.size()-1,str) ){
			answer.push_back(str);
		}
		cout << '\n';
	}
	sort(answer.begin(),answer.end());

	cout << answer.size() << '\n';
	for(int i = 0; i< answer.size(); i++){
		cout << answer[i] <<'\n';
	}
}