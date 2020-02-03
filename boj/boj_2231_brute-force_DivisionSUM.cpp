#include <iostream>
using namespace std;


/* 
   부분집합적으로 생각하자. 
   256 = (245 + 2 + 4 + 5) 이다. 
   이것을 해결하기 위해서 
   245+2를 먼저 생각하고 
   245+4
   245+5가 되는 방법을 생각하자 

   이것은 cnt가 245일때 

   div라는 변수에 각 자리수의를 나타내자
   
   245%10은 5를 남기고   245/10은 24를 남긴다. 
   div가 24일때 %10하면 4가  24/10하면 2가 남고 
   이것을 반복하고 div 가 0 이라면 반복문을 빠져나오고 

   cnt와 N혹은 sum을 비교한다. 

*/
int N;
int findCreator(void)
{
        int creator = 1; //1부터 시작

        while (1)
        {
                 int copy = creator;
                 int sum = creator; //합은 생성자와 생성자의 각 자리 숫자의 합
 
                 while (copy) //각 자리 숫자의 합을 구한다
                 {
                         sum += copy % 10;
                         copy /= 10;
                 }
                 //조건 성립시 혹은 생성자가 없을 경우
                 if (creator == N || sum == N)
                         break;
                 creator++;
        }
        return creator;
}

 
int main(void)
{
        cin >> N;
        int result = findCreator();
        if (result == N)
                 cout << 0 << endl;
        else
                 cout << result << endl;
        return 0;
}

// koosaga code
// #include <cstdio>

// int dcps(int x){
//     int res = x;
//     while (x) {
//         res += x%10;
//         x /= 10;
//     }
//     return res;
// }
// int main(){
//     int n;
//     scanf("%d",&n);
//     for (int i=1; i<=n; i++) {
//         if(dcps(i) == n){
//             printf("%d",i);
//             return 0;
//         }
//     }
//     puts("0");
// }