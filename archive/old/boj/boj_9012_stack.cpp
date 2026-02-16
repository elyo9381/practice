#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <iostream>
#include <string>
#include <time.h>
#include <stack>


using namespace std;

bool Check(string str){
    int len= (int)str.length();
    stack<char> st;

    for(int i =0; i<len; i++)
    {
        char c = str[i];
        if(c=='(')
        {
            st.push(str[i]);

        }else
        {
            if(!st.empty())
            {
                st.pop();

            }else{
                return false;
            }
        }
    }
    return st.empty();
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    cin.ignore();
    for(; t!=0;t--)  {
        string str;
        //getline 공백도 같이 받아올수있는 함수
        getline(cin, str);
        // str += '\n';


        if(Check(str))
        {
            cout<<"YES"<<"\n";
        }else{
            cout<<"NO"<<"\n";
        }

    }
       
}


// 6
// (())())
// (((()())()
// (()())((()))
// ((()()(()))(((())))()
// ()()()()(()()())()
// (()((())()(