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
 * 1원당 열량이 가장 높은 피자 
 * 같은 토핑2개이상 선택할수는 없다. 
 * 
 * 도우의가격 A원 토핑의 가격 모두 B원
 * 피자의 가격은 도우와 토핑의 가격의 합계가 된다. 
 * 즉 토핑 k종류 선택했다면, 피자의 가격은 A+B*k원이된다.
 * 1원당 열량을 구하는 프로그램 작성
 * 
 * 설계
 * 입력 
 * 토핑의 열량을 배열로 뺀다. 그리고 내림차순 정렬한다. 
 * 그리고 내림차순부터 하나씩 토핑을 올림을 가정하여 가장 높은 열량을 구한다. 
 * 
 * success .. but trash code ..!
*/

int N;
int dough, toping, doughPrice = 0;
int topingPricep[100001];

bool compare(int a, int b){
    return a > b;
}

int main(){

    cin >> N;

    cin >> dough >> toping >> doughPrice;

    for(int i = 0; i<N; i++){
        cin >> topingPricep[i];
    }

    sort(topingPricep, topingPricep + N,compare);

    int findMax = 0;
    int price = dough + toping * 0;
    findMax = doughPrice / price;

    int cal_Price = 0;
    for(int i = 0; i<N; i++){
        cal_Price +=topingPricep[i];
        int mok = dough + (toping * (i+1));
          int c = ((doughPrice + cal_Price) /mok );
        findMax = max(findMax , c);
    }

    cout << findMax << "\n";
}