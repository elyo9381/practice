#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <iostream>
#include <string>
#include <time.h>
#include <stack>

using namespace std;

int main(void){
    int T;
    cin>>T;

    stack<int> st;
    string str;

    for(; T!=0; T--)
    {
        cin >> str;

        if(str =="push")
        {
            int num;
            cin>> num;
            st.push(num);
        }
        else if(str == "pop")
        {
            if(!st.empty())
            {
                cout<< st.top()<<endl;
                st.pop();
            }
            else
            {
                cout<< "-1"<<endl;
            }
        }
        else if(str =="size")
        {
            cout<<st.size()<<endl;

        }
        else if(str == "empty")
        {
            if(st.empty())
            {
                cout<< "1"<<endl;
            }
            else
            {
                cout<<"0"<<endl;
            }
        }
        else if( str == "top")
        {
            if(st.empty())
            {
                cout<< "-1"<<endl;
            }
            else{
                cout<<st.top()<<endl;    
            }
    
        }
    }

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// const int MX= 1000007;

// int dat[MX];
// int pos;

// void push(int val){
//     dat[pos++] = val;
// }

// void pop(){
//     pos--;
// }

// int top(){
//     return dat[pos-1];
// }

// int main()
// {
//    ios::sync_with_stdio(false);
//    cin.tie(NULL);

//    int n;
//    cin >> n;

//    while(n--)
//    {
//     string c;
//     cin >> c;
//     if(c=="push"){
//         int t;
//         cin >> t;
//         push(t);
//     }
//     else if(c== "pop"){
//         if(pos == 0) cout << -1 << '\n';
//         else
//         {
//             cout << top() <<'\n';
//             pop();
//         }
//     }
//     else if(c=="size")
//         cout<<pos<<'\n';
//     else if(c=="empty")
//         cout<< (int)(pos == 0) << '\n';
//     else{
//         if(pos ==0) cout << -1 <<'\n';
//         else cout<< top() << '\n';
//     }
//    }

//    return 0;
// }


// 14
// push 1
// push 2
// top
// size
// empty
// pop
// pop
// pop
// size
// empty
// pop
// push 3
// empty
// top