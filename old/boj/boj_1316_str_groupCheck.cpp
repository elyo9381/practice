#include <bits/stdc++.h>
// #include <vector>
using namespace std;

/* */
const int mod =9901;
const int maxn = 1000000;

// long long dp[maxn+1][3];

// int buf[maxn+1];
bool wordCheck(string str)
{
    bool alpabet[26] = {false};

    for(int i = 0; i<str.size(); i++)
        if(alpabet[str[i]-'a']){
            return false;
        }else{

            char tmp = str[i];
            alpabet[str[i] -'a'] = true;

            while(true){
                if(tmp != str[++i]){
                    i--;
                    break;
                }
            }
        }
        return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>> t;

    int cnt = 0;

    for(int i =0; i<t; i++)
    {
        string str;
        cin>> str;


        if(wordCheck(str))
            cnt++;

    }

    cout<< cnt;

    return 0;
}
