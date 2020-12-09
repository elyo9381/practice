#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;



/*
    후위 표기법
*/

int s[102] , top =-1;
char str[102];

int pop(void){
    return s[top--];
}

void push(int a){
    ++top;
    s[top] = str[a] - '0';
}

int cal(int n){
    int i,j;

    for(i = 0 ; i<n; i++){

        if(str[i] >='0' && str[i] <='9') push(i);
        else{
            switch(str[i]){
                case '+':
                    s[top]+=pop();
                case '-':
                    s[top]-=pop();
            }
        }
    }
    return s[0];
}
int main(void){

	int n,res=0;
	cin >> n;
	for(int i =0; i<n; i++){
		cin >> str[i];
	}

    res = cal(n);
	
	return 0;
}
