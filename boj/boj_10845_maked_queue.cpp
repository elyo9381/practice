#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <iostream>
#include <string>
#include <time.h>
#include <stack>
#include <vector>
#include <list>
#include <queue>
using namespace std;

/* */



 

int main(void)
{
    int t;

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    queue<int> qu;

    cin>> t;
    cin.ignore();
    while(t--)
    {
        string str;
        cin>> str;       

        if(str=="push")
        {
            int num;
            cin>>num;
            qu.push(num);
        }
        else if(str == "pop")
        {
            if(!qu.empty())
            {
                cout<<qu.front()<<"\n";
                qu.pop();

            }else{
                cout<<"-1"<<"\n";
            }
        }
         else if(str == "size")
        {
            cout<<qu.size()<<"\n";
        }
        else if(str=="empty")
        {
           cout<<qu.empty()<<"\n";
        }

         else if(str == "front")
        {
            if(!qu.empty())
            {
                cout << qu.front() << endl;
            }
            else
            {
                cout<<"-1"<<"\n";
            }
        }
        else if(str=="back")
        {
            if (!qu.empty())
            {    int curSize = qu.size();
            
                for (int j = 0; j < curSize - 1; j++)
                {
                    int num = qu.front();
                    qu.pop();
                    qu.push(num);
                }
                int num = qu.front();
                qu.pop();
                cout << num << endl;
                qu.push(num);
            }
            else
                cout << -1 << endl;
        }
    }


    return 0;



    
}


//직접구현한 queue

// #include <bits/stdc++.h>
// using namespace std;
// #define endl '\n'
// const int MX =1000007;

// int dat[MX];
// int head, tail;

// void push(int val){
//     dat[tail++] = val;
// }


// void pop(){
//     head++;
// }

// int front(){
//     return dat[head];
// }


// int back(){
//     return dat[tail-1];
// }

// int main(void){
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);

//     int n;
//     cin >>n;
//     while(n--){
//         string q;
//         cin>> q;


//         if(q=="push"){
//             int val;
//             cin>> val;
//             push(val);
//         }
//         else if(q=="pop")
//         {   
//             //비였다면 -1출력
//             if(tail == head) cout<< -1 <<endl;
//             else{
//                 cout<< front()<<endl;
//                 pop();
//             }
//         }
//         else if(q=="size"){
//             cout<< tail-head<<endl;
//         }
//         else if(q=="empty"){
//             cout<< (tail==head) <<endl;
//         }

//         else if(q=="front"){
//             if(tail==head) cout<< -1 << endl;
//             else cout<< front()<<endl;
//         }
//         else { //back 
//             if(tail==head) cout << -1<< endl;
//             else  cout<< back()<< endl;
//         }
//     }

//     return 0;
// }

