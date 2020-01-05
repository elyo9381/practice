#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*오큰수 다른 측면에서 생각하였을때 가장 오른쪽 n이 n-1보다
크면 n을 출력하고 n이 n-1작으면 스택을 pop하면 되는 구조이다. 
비교하여 풀기 
*/
int test_case;

int temp;

vector<int> v;
vector<int> ans;
stack<int> s;

int count_num[1000001] = { 0 };

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> test_case;
    for (int i = 0; i < test_case; i++) {
        cin >> temp;
        v.push_back(temp);
        count_num[temp]++;
    }

    s.push(-1);

    for (int i = 0; i <= v.size() - 1; i++) {
        cout<<"<1>"<<endl;
        if (count_num[s.top()] <= count_num[v[i]]) {  //스택맨위가 백터보더 더 작으면
            while (count_num[s.top()] <= count_num[v[i]] && s.top() != -1){
                cout<<"<3>"<<endl;
                s.pop();
            }
            ans.push_back(s.top());
            cout<<"<4>"<<endl;
            s.push(v[i]);
            cout<<"<5>"<<endl;
        }
        else {
            cout<<"<6>"<<endl;
            ans.push_back(s.top());
            cout<<"<7>"<<endl;
            s.push(v[i]);
        }
    }

     for (int i = 0; i <= v.size() - 1; i++)  {
        cout << ans[i] << " ";
    }

    return 0;
}