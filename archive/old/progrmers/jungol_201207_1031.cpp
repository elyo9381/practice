#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int n[5][5][2];
int m[5][5];

int clear(){
	int i, j , a = 0;

	for(i = 0; i<5; i++){
		a = 0;
		for(j = 0; j <5; j++){
			if(n[i][j] != 0){
				break;
			}
			a++;
		}
			if(a == 5){
				res++;
				if(res>=3)
				return res;
			}
	}

	for(i = 0; i<5; i++){
		a = 0;
		for(j = 0; j<5; j++){
			if(n[j][i] != 0)
				break;	
			a++;
		}
		if(a == 5){
			res++;
			if(res>=3)
			return res;
		}
	}

	a = 0;
	for(i = 0; i<5; i++){
		if(n[i][i] != 0)
			break;
		a++;
	}

	if(a == 5){
		c++;
		if(c>=3)
			return c;
	}

	a = 0;
	for(i = 0; i<5; i++){
		if(n[4-i][i][1]!=0)
			break;
		a++;
	}

	if(a == 5)
	{
		c++;
		if(c>=3)
			return c;
	}

	return 0;
}

int search(int a){
	int i,j;
	for(i = 0; i<5; i++)
		for(j = 0; j<5; j++)
			if(n[i][j][1] == a){
				n[i][j][1] =0;
				return 0;
			}
}

int check(){
	int i, j , res = 0; 
	for( i = 0; i<5; i++){
		for(j = 0; j<5; j++){
			search(m[i][j]);
			res++;
			if(clear() > 0){
				return c;
			}
		}
	}
}

void in(){
	for(int i = 0; i<5; i++){
		for(int j = 0; j<5; j++){
			cin >> n[i][j][0];
			n[i][j][1] = n[i][j][1];
		}
	}
}


int main(void){

	in();

	cout <<  check();
	return 0;
}