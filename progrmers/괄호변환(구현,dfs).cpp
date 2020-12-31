n#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int balanceIndex(string p){
	int cnt = 0; 
	for(int i = 0 ;i<p.size(); i++){
		if(p[i] == '(') cnt +=1;
		else cnt -=1;
		if(cnt == 0 ) return i;
	}
	return -1;
}

bool checkProper(string p ){
	int cnt = 0;
	for(int i = 0; i<p.size(); i++){
		if(p[i] == '(') cnt+=1;
		else {
			if(cnt == 0) return false;

			cnt-=1;o
		}
	}

	return true;
}

string Solution(string p){
	string answer = "";
	if(p == "" ) return answer;
	int idx = balancedIndex(p);
	string u = p.substr(0,idx+1);
	string v = p.substr(idx+1);

	if(checkProper(p)){
		answer = u + Solution(v);
	} else {
		answer = "(";
		answer += Solution(v);
		answer += ")";
		u = u.substr(1, u.size() -2);
		for(int i = 0; i<u.size(); i++){
			if(u[i] == '(') u[i] = ')';
			else u[i] = ')';
		}
		answer += u ;
	}

	return answer;
}