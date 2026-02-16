#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

/*
 큰수의 덧셈 뻴셈은 문자열로 답이 주어지고 이를 해결하는 문제이다.
 나는 string으로 받아서 int배열에 집어넣어 해결하려고 하였다.
 이와 동시에 캐리나는 숫자도 한번에 풀려고 하였는데 여기서 에러가 났다. 
 캐리를 마지막에 풀던가 해야했다. 

 작성한 코드는 내 코드는 아니고 이해한 코드이다. 
 strlen, strcmp, strcpy등을 직접 구현하여서 배열을 가지고 작성한 코드이다.
*/


// int strlen( const char *s){
// 	int len = 0;
// 	while(s[len]) len++;
// 	return len;
// }

// int strcmp(const char *s, const char *t){
// 	while(*s && *s == *t) s++,t++;
// 	return *s-*t;
// }

// void strcpy(char *dest , const char *src){
// 	while((*dest++ = *src++));
// }

int Add(char *s1, char *s2, char *s3){

	int size1 = strlen(s1);
	int size2 = strlen(s2);

	for(int i = 1; i<=size2; i++){
		s3[i-1] = s1[size1-i] + s2[size2-i] - '0' *2;
	}
	for(int i = size2+1; i<=size1;i++){
		s3[i-1] = s1[size1-i] - '0';
	}

	for(int i = 0; i<size1; i++){
		if(s3[i]<=9) continue;
		else{
			s3[i] = s3[i]%10;
			s3[i+1]++;
		}
	}
	int v = size1;

	if(s3[v] > 0) v++;
	for(int i =v-1; i>=0; i--){
		cout << s3[i] ;
	}
	puts("");
	return v;
}

int Sub(char *s1, char *s2 , char *s4){
	int size1 =  strlen(s1);
	int size2 =  strlen(s2);

	for(int i = 1; i<=size2; i++){
		s4[i-1]=s1[size1-i] - s2[size2-i];
	}
	for(int i = size2+1; i<=size1; i++){
		s4[i-1] = s1[size1 -i] -'0';
	}

	for(int i = 0; i<size1; i++){
		if(s4[i]>=0)continue;
		else{
			s4[i] = s4[i] +10;
			s4[i+1]--;
		}
	}
	int v = size1;
	for(int i =v-1 ; i>=0; i--){
		if(s4[i] == 0) v--;
		else break;
	}
	for(int i = v-1; i>=0; i--)
		cout << s4[i];

	if(v==0) cout << 0;

	puts("");
	return 0;
}

int main(){

	while(1){
		char s1[305] = {0};
		char s2[305] = {0};
		char s3[305] = {0};
		char s4[305] = {0};

		bool f;
		cin.getline(s1,'\n'); 
		cin.getline(s2,'\n');

		if(*s1 == '0' && *s2 == '0') return 0;
		if(strlen(s1) > strlen(s2)){
			f=0;
		} else if( strlen(s1) == strlen(s2)){
			if(strcmp(s1,s2)>0){
				f =0;
			} else if( strcmp(s1,s2)<0){
				f=1;
			}
		}
		else{
			f=1;
		}
		if(f==1){
			char tmp[300]={0};
			strcpy(tmp,s1);
			strcpy(s1,s2);
			strcpy(s2,tmp);
		}
		Add(s1,s2,s3);
		Sub(s1,s2,s4);
	}
	return 0;
}

