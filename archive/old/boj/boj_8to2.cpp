#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string change8to2(char c)
{
    string result = "";
    int num = c - '0';

    if(num == 0)           // 이걸 해주지 않으면 0이 입력일 때 빈 문자열이 반환된다.
        return "0";

    while (num != 0)
    {
        result += to_string(num % 2);
        num = num / 2;
    }
    reverse(result.begin(), result.end());
    
    return result;
}

int main() {
    string s;
    cin >> s;

    for(int i = 0; i < s.size(); i++)
    {
        if (i == 0)
            cout << change8to2(s[i]);
        else
        {
            string temp = change8to2(s[i]);
            while(temp.size() != 3)
                temp = '0' + temp;
            cout << temp;
        }
    }
}