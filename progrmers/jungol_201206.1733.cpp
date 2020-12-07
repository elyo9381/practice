#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int om[19][19];
int win, win_x, win_y;


int go(int x, int y){

	int i , j, ,h, a= 0;
	h = om[x][y];// 흰색 혹은 검은색

	for(i = x+1; i<=(x+5) && i<19; i++){ // 세로줄 판단
		if(om[i][y]!=h) // 같은색의 바둑돌이 높여있지 않을경우
			break;
		a++;
	}
	if(a == 4){
		if(om[x-1][y] !=h)
			return h;
	}

	a = 0; 
	for(j = y+1; j<=(y+5) && j<19; j++){
		if(om[x][j] !=h) break;

		a++;
	}
	if(a == 4){
		if (om[x][y-1] !=h) return h;
	}

	a = 0; 
	for(i = x+1 , j = y+1; i<=(x+5) && j < 19 && i<19 ; i++, j++){
		if(om[i][j] !=h) break;

		a++;
	}
	if(a == 4){
		if(om[x-1][y-1] !=h) return h;
	}
	a = 0; 
	for(i = x-1, j = y-1; j<=(y+5) && i <19 && j<19 ; j++){
		if(om[i][j] !=h) break;

		a++;
	}
	if(a == 4)
		if(om[x+1][y-1] !=h) return h;

	return 0;

}

void search(void){

	int i , j ,a;
	for(i = 0; i<19; i++){
		for(j = 0 ; j<19; j++){
			if(i>14 && j >14) break;

			else if(om[i][j] != 0){
				a = go(i,j);
				if(a != 0){
					win =a; 
					win_x = i+1;
					win_y = j+1;
					break;
				}
			}	
		}
	}

}

void in(void){

	for(int i = 0; i<19; i++){
		for(int j = 0 ;j <19; j++){
			cin >> om[i][j] ;
		}
	}
}

int main(){

	in();
	search();

	cout << win<<endl;
	if(win!=0)
		cout << win_x << win_y ;	
	
	return 0;
}
