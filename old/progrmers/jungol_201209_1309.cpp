#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int sum =1;

// int re(int a){
// 	if(a == 0) return 0;
// 	if(a!=1){
// 		cout << a <<"! = "<<a << " * "<<a-1<<"!"<<endl;
// 		sum *=a;
// 		re(a-1);
// 	} else {
// 		cout <<"1! = 1\n";	
// 	}
// 	return 0;
// }

int re(int a){
	if(a == 0) return 0;
	if(a == 1){
		cout <<"1! = 1\n";
	} else {
		cout << a<<"! = "<<a<< " * "<<a-1<<"!"<<endl;
		sum *=a;
		re(a-1);
	}
	return 0;
}

int main(void){

	int n;
	cin >> n;
	re(n);
	cout <<sum;
	return 0;
}
 