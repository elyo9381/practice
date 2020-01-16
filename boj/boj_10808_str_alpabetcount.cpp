#include <bits/stdc++.h>
// #include <vector>
using namespace std;
const int maxn =1000000;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int al[26];

    memset(al,0,sizeof(al));

    char str[101];

    cin>> str;

    for (int i = 0; i < strlen(str); ++i)
    {
        // cout<<str[i]<<endl;
        al[str[i] - 97]++;
    }


    for(int i =0; i<26;i++)
        cout<< al[i]<< " ";






}