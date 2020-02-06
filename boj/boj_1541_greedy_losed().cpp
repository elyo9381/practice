#include <bits/stdc++.h>
#define endl '\n'
#define MAXN 10000
using namespace std;


int N;
string str;
// char str[MAXN];

void Input()
{   
   cin >> str;
}
void Solution()
{
    int ret = 0;
    string temp = "";
    bool minus = false;
    for(int i = 0; i<=str.size(); i++)
    {
        if(str[i] == '+' || str[i] == '-' || str[i] == '\0')
        {
            if(minus) ret -= stoi(temp);
            else ret +=stoi(temp);

            temp= "";
            if(str[i] =='-') minus = true;
            continue;
        }
        temp+=str[i];
    }

    cout<<ret<<endl;
    return ;
}

void Solve()
{
    Input();

    Solution();
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solve();
    return 0;
}

// //koosaga code
// char str[55];

// int main(){
//     cin >> str;
//     cout<<strlen(str)<<endl;
//     str[strlen(str)] = '+';
//     int buf = 0, found = 0, ret = 0;
//     for(int i=0; str[i]; i++){
//         if(str[i] == '+'){
//             ret += (1 - 2 * found) * buf;
//             buf = 0;
//         }
//         else if(str[i] == '-'){
//             ret += (1 - 2 * found) * buf;
//             buf = 0;
//             found = 1;
//         }
//         else{
//             buf = buf * 10 + str[i] - '0';
//         }
//     }
//     cout << ret;
// }
