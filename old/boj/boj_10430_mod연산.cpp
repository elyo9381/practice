#include <iostream>
#include <vector>
#include <stack>
using namespace std;


int main()
{
    std::vector<int> v;

    int a,b,c;

    cin>> a>>b>>c;

    cout<< (a+b)%c<<endl;
    cout<< (a%c+b%c)%c<<endl;
    cout<< (a*b)%c<<endl;
    cout<< (a%c * b%c)%c<<endl;
}
