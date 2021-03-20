#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

/**
 * 
 * 조건
 * 왼쪽도시에서 오른쪽 도시로 이동
 * 인접한 두도시 사이의 도로들은 서로길이가 다를수있다.
 * 1키로미다 1리터
 * 
 * 왼쪽도시에서 오른쪽 도시로 갈때 최소비용
 * 
 * 
 * 설계
 * 최소값을 설정하고 최소값보다 크면 이전값으로 구매한다.
 * 최소값이 나오면 계속 최소값을 바꿔줘서 최소값이 나오기 전까지 구매한다. 
 * 
 * 도시의 거리는 10억까지 올수있으므로 오버플로우를 걱정한다. 
 * 
 * 왼도시에서 최소비용으로만 기름을 구매한다. 
 *   2 3 1 1
 * 5 2 4 1 0
 * 
*/

int N;
long long dist[100001];
long long city[100001];


int main(){
   
   cin >> N;
   long distSum = 0;
   long long sum = 0;

   for(long i = 1; i<N; i++){
       cin >> dist[i];
       distSum += dist[i];
   }

   for(long i = 0; i<N; i++){
       cin >> city[i];
   }


    int minCost = 987654321;

   for(int i = 0; i<N; i++){

       if(minCost > city[i]){
           minCost = city[i];
           sum += minCost * dist[i+1];
       } else {
           sum += minCost * dist[i+1];
       }

   }
   cout << sum <<"\n";

}