#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

// 참외밭 문제
// 주어진 입력은 ㄱ자 모양의 입력이 주어진다. 이때 넓이를 구해야하는데
// 전체 넓이에서 빈넓이를빼면 구할수 있다.
// line()를 통해서 정렬을 해야하는이유! > 이것은 추후에 전체 넓이에서 빈곳의 넓이를 구하기위해서 
// line()를 정렬을 해야한다. 
// size()는 전체 넓이를 가장 넓은 변을 선택해도 되고 ㄱ모양이기 때문에
// 번개모양의 변의 길이를 x,y에 더하면 전체 길이를 구할수있다.
// 그래서 정렬을 해놓는다면 빈곳의 번개모양의 변의길이를 통해 빈곳의 넓이를 구할수있다.


int where[6][2];

int size(void){
	int sum, cut, i , x=0, y=0;

	for(i = 0 ; i<6; i++){
		if(where[i][0] == 1)
			x+=where[i][1];
		else if(where[i][0] ==3)
			y+=where[i][1];
	}
	sum=x*y;

	for(i = 0; i<6; i++){
		where[i][0]--;
		if((where[i][0]/2) == 0 && where[i][1]<x)
		{
			cut = where[i+1][1] * where[i+2][1];
			break;
		}
		else if((where[i][0]/2) == 1 && where[i][1]<y){
			cut = where[i+1][1] * where[i+2][1];
			break;
		}
	}
	sum -=cut;

	return sum;
}

void line(){
	int i , num[4] = {0}, n[2], k = 0, tmp1,tmp2;

	for( i = 0 ;i<6; i++){
		num[where[i][0]]++;

		// if(num[where[i][0]]==2)
		// 	n[k++]=where[i][0];
	}

	while(where[5][0]!=num[0] && where[5][0]!=num[1])
	{
		tmp1 = where[5][0];
		tmp2 = where[5][1];

		for(i = 4; i>=0; i--){
			where[i+1][0] = where[i][0];
			where[i+1][1] = where[i][1];
		}
		where[0][0] = tmp1;
		where[0][1] = tmp2;
	}
}

int main(void){

	int k , sum = 0;
    cin >> k;

    for(int i = 0; i<6 ;i++){
        cin >> where[i][0] >> where[i][1];
    }

	line();
	sum = size();

	cout << sum*k;

	return 0;
}

