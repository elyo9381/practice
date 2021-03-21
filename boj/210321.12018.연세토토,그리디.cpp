#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

/**
 * 
 * 조건
 * 마일리지 1~36 분배, 마일리지 많이 투자한순으로 과목의 수강인원 신청
 * 
 * 설계
 * p < l 일때는 무조건 하나라도 들어가 줘야한다. 
 * 그리고 나는 36이 아닐때를 빼려고 했었는데 
 * 다 넣고 다시 한번 정렬하는 방법으로 큰값을 뺼수있다. 주의하자.
 * 
*/

int main(){

    int n,m;

    cin >> n >> m;

    vector<int> v;

    for(int i = 0; i<n; i++){
        int p, l;
        cin >> p >> l;
        
        vector<int> temp(p);

        for(int j = 0; j<p; j++){
            cin >> temp[j];
        }

        if( p < l){
            v.push_back(1);
            continue;
        }

        sort(temp.begin(), temp.end(), greater<int>());

        v.push_back(temp[l-1]);
    }

    sort(v.begin(),v.end());


    int result = 0;

    for(int i = 0; i< v.size(); i++){
        if( m >= v[i]){
            m -= v[i];
            result++;
        }
        else {
            break;
        }
    }

    cout <<result << "\n";
}