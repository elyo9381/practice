#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/*오큰수 다른 측면에서 생각하였을때 가장 오른쪽 n이 n-1보다
크면 n을 출력하고 n이 n-1작으면 스택을 pop하면 되는 구조이다. */
int test_case;

int temp;

vector<int> v;
vector<int> ans;
stack<int> s;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> test_case;
    for (int i = 0; i < test_case; i++) {
        cin >> temp;
        v.push_back(temp);
    }

    s.push(-1);

    for (int i = v.size() - 1; i >= 0; i--) {
        if (s.top() <= v[i]) {  //스택의 맨 위가 백터보다 더 크면
            while (s.top() <= v[i] && s.top() != -1)
                s.pop();
            ans.push_back(s.top());
            s.push(v[i]);
        }
        else {
            ans.push_back(s.top());
            s.push(v[i]);
        }
    }

    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i] << " ";
    }

    system("pause");
    return 0;
}