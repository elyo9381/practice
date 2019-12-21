#include <iostream>
#include <string>
#include <time.h>
using namespace std;
//��ʹ� �Լ��� ����¹��������� �߾˾ƾ��Ѵ�. 
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
    cout<<"5 ���� �� �ɸ� �ð�:"<<et-st<<endl;
    
    st = clock();
    Hanoi("a","b","c",8);
    et = clock();
    cout<<"8 ���� �� �ɸ� �ð�:"<<et-st<<endl;
    return 0;
}
