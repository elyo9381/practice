#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

/*
    조건
    세준 0, 초기 책 위치 0
    책의 위치가 주어질때, 책을 모두 제자리에 놔둘때 
    드는 최소걸음수를 계산하는 프로그램 작성

    모두 제자리에 놔둔 후에는 다시 0으로 돌아올 필요는 없다. 
    최대 M권의 책을 들수 있다.

    설계
    정렬하고 음수,양수일때를 다르게 저장해야한다.
    마지막 가장 먼거리는 되돌아올 필요가 없으므로 한번 빼주도록 하자 
    또 예외처리가 필요하다 음수또는 양수에 책이 없을수있으므로 이에 대한 경우도 준비해야한다.
*/


const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};

const int INF = 987654321;
typedef long long ll;

int main(){

    int n ,m ;

    vector<int> temp1;
    vector<int> temp2;

    cin >> n >> m;

    for(int i = 0; i<n; i++){
        int a; 
        cin >> a;
        if(a < 0) temp1.push_back(-a);
        else temp2.push_back(a);
    }


    sort(temp1.begin(),temp1.end(),greater<int>());
    sort(temp2.begin(),temp2.end(),greater<int>());
    
    int result = 0;
    for(int i = 0; i<temp1.size(); i = i+m){
        result += 2*(temp1[i]);
    }

    for(int i = 0; i<temp2.size(); i = i+m){
        result += 2*(temp2[i]);
    }

    // if(temp1.empty()) result -= temp2[0];
	// else if(temp2.empty()) result -= temp1[0];
	if(temp1[0] > temp2[0]) result -= temp1[0];
	else result -= temp2[0];

	cout << result;
}