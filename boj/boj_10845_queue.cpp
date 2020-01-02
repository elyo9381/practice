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

