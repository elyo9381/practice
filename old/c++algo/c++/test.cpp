#include <iostream>
#include "vector.h"
#include "algorithm.h"

using namespace std;
using ehlib::vector;
bool Isnum(int i){ return (i==3) == 1;}

int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	
	vector<int>::iterator bit = v.begin();
	vector<int>::iterator eit = v.end();
	
	vector<int>::iterator seek = find_if(bit, eit, Isnum);
	
    
    	cout<<*seek<<endl;
        v.erase(seek);        
        cout<<"삭제하였습니다."<<endl;
    
    

	return 0;
}
