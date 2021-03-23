#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

/**
 * 
 * 조건
 * 주식하나를산다.
 * 원하는만큼 가지고 있는 주식을 판다.
 * 아무것도 안한다. 
 * 
 * 최대이익이 얼마나 되는지 계산해달라 
 * 
 * 설계
 * 가격이 떨어지기 전날을 파악해서 그날 다판다.판날은 사지 않는다. 
 * 가격이 떨어지기 전날을 어떻게 파악하냐 ? 
 * 1, 처음엔 떨어지는 날을 파악했지만 이렇게 할시에 매번 파는 오류 발생
 * 2, 뒤에서 부터 큰값을 찾아 체크함 가장 큰값에 팔고 또한 상대적으로 큰값이 존재하면 판다. 
 * 
*/

const int INF = int(1e9);

int t,n ; 
int stocks[1000003];

int main(){

    cin >> t;
    while(t--){
        cin >> n;
        int MAX = 0;
        long long cnt = 0, myMoney = 0;

        bool noBuyCheck[1000003];
        memset(stocks,0,sizeof(stocks));
        memset(noBuyCheck,false,sizeof(noBuyCheck));

        for(int i = 0; i<n; i++){
            cin >> stocks[i];
        }

        int sellest = 0;
        for(int i = n; i>=0; i--){
            if(stocks[i] > sellest ){
                sellest = stocks[i];
                noBuyCheck[i] = true;
            }
        }
        long long ret = 0;
        for(int i = 0; i<n; i++){

            if(noBuyCheck[i]){
                myMoney += cnt * stocks[i];
                cnt = 0;
                continue;
            }
            myMoney -= stocks[i];
            cnt++;
        }
        
        cout << myMoney <<"\n";

    }
}