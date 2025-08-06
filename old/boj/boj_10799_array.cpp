#include <iostream>
#include <stack>
using namespace std;

/* 배열을 이용한 문제 
( 나왔을땐 cnt++하고 )나오면 cnt--한다. 
()일경우에는 cnt -- 를 sum에 더하고
))일경웅는 cnt --하고 sum만 ++한다.*/

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    stack<char> st;

        string str;
        getline(cin, str);
        int sum =0,cnt =0;
        int size = str.size();
        for(int i =0; i<size; i++)
        {
            if(str[i] == '(')
            {
                cnt++;

            }
            else
            {
                if(str[i-1]=='(')
                {
                    cnt--;
                    sum +=cnt;

                }
                else
                {
                    cnt--;
                    sum++;
                }
            }

        }
        cout<<sum<<"\n";
        return 0;
}


