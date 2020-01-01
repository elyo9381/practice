#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <iostream>
#include <string>
#include <time.h>
#include <stack>


using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    cin.ignore();
    while(t--) {
        string str;
        getline(cin, str);
        str += '\n';
        stack<char> s;
        for(char ch: str) {
            if(ch == '\n' || ch == ' ') {
                while(!s.empty()) {
                    cout << s.top();
                    s.pop();
                }
                cout << ch;
            } else {
                s.push(ch);
            }
        }
    }
    return 0;
 }

// #include <iostream>
// #include <string>
// using namespace std;

// int main(void)
// {
//     int t, len, st, size;
//     cin >>t;
//     cin.ignore();
//     for(;t!=0;t--)
//     {
//         string arr;
//         getline(cin,arr);
//         cout<<arr<<"\n";
//         st =0, size = arr.size();
//         for(int i =0; i<size; i++)
//         {
//             if ( arr[i] ==' ')
//             {
//                 for( int j = i-1; j>= st; j--)
//                     cout<<arr[j];
//                 cout<<" ";
//                 st = i+1;
//             }
//         }
//         for( int i = size -1; i>=st; i--)
//             cout<< arr[i];
//         cout<<"\n";
//     }
// }