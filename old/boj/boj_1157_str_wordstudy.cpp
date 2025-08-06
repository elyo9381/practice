#include <bits/stdc++.h>
// #include <vector>
using namespace std;


/**/
int main()
{
    int alpabet[26];
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //알파벳 배열 초기화 
    for (int i = 0; i < 26; i++) 
        alpabet[i] = 0;

    // 입력
    char str[1000001];
    cin >> str;
    int len= strlen(str);

    for(int i=0;i<len; i++){
        if(str[i] >= 65 && str[i] <=90)
            alpabet[str[i]-65]++;
        else if(str[i] >=97 && str[i]<=122)
            alpabet[str[i]-97]++;

    }

    char ans;
    int max=0;
    for(int i =0;i<26;i++){
        if(alpabet[i]>max){
            ans = i + 65;
            max = alpabet[i];

        }
        else if( alpabet[i] == max)
            ans = '?';
    }



    cout<< ans<< endl;

    return 0;
}
