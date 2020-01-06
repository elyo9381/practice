#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//최대 공약수
// a,b : 최대공약수를 구하고자 하는 두 수
// r : a를 b로 나눈 나머지 = ( a%b ) = ( a mod b )
// 식 : gcd(a,b) = gcd(b,r)
// 최소 공배수 공식 (최대공약수를 이용)
// a,b : 최소공배수를 구하고자 하는 두 수
// gcd(a,b) : a와b의 최대공약수
// (최소공배수 * 최대공약수 = a * b)를 이용
// 식 : a * b / gcd(a,b)
int gcd(int a, int b){
    while(b!=0){
        int r = a%b;
        a= b;
        b= r;
    }
    return a;
}

int lcm(int a, int b){
    return a * b / gcd(a,b);
}


int main()
{
    std::vector<int> v;

    int a,b,c;

    cin >> a>>b;

    cout<< gcd(a,b)<<endl;
    cout<< lcm(a,b)<<endl;
}
