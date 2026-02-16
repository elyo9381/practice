#include <bits/stdc++.h>

using namespace std;

int main(){
	int N;
	cin >> N;

	int digit[10];

	fill(digit, digit+10,0);

	
	while(N!=0){
		digit[N%10]++;
		N/=10;
	}

	int result = 0;
	for(int i=0; i<9; i++){
		if(i==6) continue;
		result = max(result, digit[i]);
	}
	result = max(result, (digit[6]+digit[9]+1)/2);
	cout << result << endl;

	return 0;
}
