#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
string str;
int stick(){
	// rcnt : 레이저 지나고 나서 막대기수
	// cnt : total 막대기
	// ch가 1일때는 레이저 아직안쏘고 증가하면 쏜것 레이저 쏘고도 ch가올라가면 막대 끝도달
	int i ,j,rcnt=0, cnt=0,ch =0;
	
	for(i = 0;i <str[i]!='\0';i++){
		if(str[i] == '('){
			rcnt++;
			ch = 1;
		}
		else if( str[i] == ')' && ch!=1){
			cnt++;
			rcnt--;
			ch++;
		} else if (str[i] == ')' && ch==1){
			rcnt--;
			cnt+=rcnt;
			ch++;
		}
	}
	return cnt;
}

int main(void){

	int res;
	getline(cin,str);
	res=stick();
	cout << res <<endl;
	
	return 0;
}
