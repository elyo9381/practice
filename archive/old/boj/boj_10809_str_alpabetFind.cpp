#include <bits/stdc++.h>
// #include <vector>
using namespace std;

/*
1. 주어진 단어를 배열에 넣기
2. 글자가 해당하는 인덱스를 알파벳 배열에 넣기 
 */


int main()
{
    int alpabet[26];
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //알파벳 배열 초기화 
    for (int i = 0; i < 26; i++)  //cnt 배열 -1로 초기화
        alpabet[i] = -1;

    // 입력
    string str;
    cin >> str;

    // str의 인덱스를 알파벳 배열에 넣기  
    for(int i=0; i<str.length();i++){
            if(alpabet[str[i]-97] == -1)
            {
                alpabet[str[i]-97]= i;
         }
        }


    for (int i = 0; i < 26; i++) {
        cout<< alpabet[i]<<" ";
    }
    cout<<"\n";



    return 0;
}
