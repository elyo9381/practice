#include <iostream>
#include <string>

using namespace std;

// string change2to8(string s)
// {
//     int result = 0;

//     for (int i = 0; i < s.size(); i++)
//         result = result * 2 + (s[i] - '0');

//     return to_string(result);
// }

// int main() {
//     string s;
//     cin >> s;

//     string ans;
    
//     int r = s.size() % 3;

//     // 길이를 3으로 나눈 나머지가 0이 아닌경우 먼저 그 만큼만 떼서 변환하기
//     if(r != 0)
//         ans.append(change2to8(s.substr(0, r)));

//     for (int i = r; i < s.size(); i+=3)
//         ans.append(change2to8(s.substr(i, 3)));

//     cout << ans << endl;
// }

// 백준풀이
int main() {
    string s;
    cin >> s;
    
    int n = s.size();
    
    if (n%3 == 1)
        cout << s[0];
    else if (n%3 == 2)
        cout << (s[0]-'0')*2 + (s[1]-'0');

    for (int i=n%3; i<n; i+=3)
        cout << (s[i]-'0')*4 + (s[i+1]-'0')*2 + (s[i+2]-'0');

    cout << '\n';
}