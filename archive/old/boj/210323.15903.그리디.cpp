#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

/**
 * 
 * 조건
 * n장 카드, i 번 카드엔 ai가 쓰여있다.
 * x,y카드를 골라 구장에 쓰여진 수를 더한값을 계산한다.(x!=y)
 * 계산한 값을 x,y카드 두장 모두에 덮어쓴다.
 * 총 m번 하면 놀이 끝난다. 
 * n 장의 카드에 쓰여있는 수를 모두 더한값이 놀이의 점수
 * 이점수를 가장 작게 만드는것이 놀이목표
 * 
 * 설계
 * 가장 작게 만드는것 ? 최소값 두개를 선택 
 * m번 돌려야하므로 매번 정렬
 *  
*/

int main(){
    int n,m;

    cin >> n >> m;

    vector<long long> cards(n);

    for(int i =0 ; i<n; i++){
        cin >> cards[i];
    }

    long long  sum = 0;
    while(m--){
        sort(cards.begin(),cards.end());
        sum = 0;
        for(int i = 0; i<2; i++){
            sum += cards[i];
        }
        for(int i = 0; i<2; i++){
            cards[i] = sum;
        }
    }
    sum = 0;
    for(auto card : cards){
        sum+=card;
    }
    cout << sum <<"\n";


}