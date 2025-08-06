#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(char *str){
    int len = strlen(str);

    int st = 0, en = 0;

    en = len - 1;

    whlie(1){
        if(st == en){
            return true;
        }
        if(str[st] == str[en]){
            st++;
            en--;
        } else { 
            return false;
        }
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> str;

    while(strcmp(str, "0")){
        if(isPalindrome(str)) cout << "yes" << "\n";
        else cout << "no" << "\n";
        cin >> str;
    }
    return 0;

}