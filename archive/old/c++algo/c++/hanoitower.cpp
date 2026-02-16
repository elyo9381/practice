#include <iostream>
#include <string>
#include <time.h>
using namespace std;
//재귀는 함수를 만드는법에서부터 잘알아야한다. 
// 
void Hanoi(string src, string use, string dest, int n)
{ 
    if(n<=0) 
    {
        return;
    } 
    Hanoi(src,dest,use,n-1); 
    cout<<"move "<<src<<" -> "<<dest<<endl; 
    Hanoi(use,src,dest,n-1); 
} 
int main()
{
    clock_t st,et;
    
    st = clock();
    Hanoi("a","b","c",5);
    
    et = clock();
    cout<<"5 개일 때 걸린 시간:"<<et-st<<endl;
    
    st = clock();
    Hanoi("a","b","c",8);
    et = clock();
    cout<<"8 개일 때 걸린 시간:"<<et-st<<endl;
    return 0;
}
