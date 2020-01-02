#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <iostream>
#include <string>
#include <time.h>
#include <stack>
#include <vector>
using namespace std;

/*[1] 전형적인 리스트 문제 operation 4가 되고 추가삭제 등이 필요하니깐
  [2] vector를 통해서는 삽입삭제가 어려움으로 list
  [3] 입력받은것을 list에 넣고 list를 iter를 통해서 커서를 움직인다.
  [4] */


/*stack사용 
stack은 하나의 스택에 다 넣고 왼쪽커서는 다른 스택에 넣고 
오른쪽 커서는 A스택에 넣어서 구현 
삭제는 A스택에서 B스택으로 이동후 Apop
P는 A에 push */
stack<char> head, tail; //커서 왼쪽, 오른쪽

 

int main(void)
{

        ios_base::sync_with_stdio(0);
        cin.tie(0);
        string s;
        cin >> s;

        for (int i = 0; i < s.length(); i++)

                 head.push(s[i]);

 

        int N;
        cin >> N;
        for (int i = 0; i < N; i++)
        {
                 char op;
                 cin >> op;
 

                 //커서 왼쪽
                 if (op == 'L')
                 {
                         if (!head.empty())
                         {
                                 tail.push(head.top());
                                 head.pop();
                             }
                 }
                 //커서 오른쪽
                 else if (op == 'D')
                 {
                         if (!tail.empty())
                         {
                                 head.push(tail.top());
                                 tail.pop();
                         }
                                          }

                 //커서 왼쪽 문자 삭제
                 else if (op == 'B')
                 {
                         if (!head.empty())
                                 head.pop();
                 }

                 //커서 왼쪽에 문자 추가
                 else
                 {
                         char c;
                         cin >> c;                       
                         head.push(c);
                 }
        }

        while (!head.empty())
        {
                 tail.push(head.top());
                 head.pop();
        } 

        string result;
        while (!tail.empty())
        {
                 result += tail.top();
                 tail.pop();
        }
        cout << result << "\n";
        return 0;
}

//stl list사용
// int N;
// list<char> li;
// char str[100001]; 
// int main(){
//     scanf("%s",str);        
//     for(int i=0;str[i];++i) li.push_back(str[i]);
     
//     list<char>::iterator it = li.end();   
//     scanf("%d\n",&N);
//     char c;
//     while(N--){
//         scanf(" %c",&c);
//         if(c=='L'){
//             if(it!=li.begin())it--; 
//         }else if(c=='D'){
//             if(it!=li.end())it++;
//         }else if(c=='B'){
//             if(it!=li.begin())  it=li.erase(--it);                                      
//         }else if(c=='P'){
//             scanf(" %c",&c);
//             li.insert(it,c);
//         }
//     }
//     for(it=li.begin();it!=li.end();it++) printf("%c",*it);
//     return 0;
// }


// 리스트 직접구현
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
 
// typedef struct _node{
//     _node *prev;
//     _node *next;
//     char val;
// } node;
 
// node *head, *tail, *cur;
 
// void init(){
//     head = (node*)malloc(sizeof(node));
//     tail = (node*)malloc(sizeof(node));
     
//     head->prev = head;
//     head->next = tail;
//     head->val = 'H';
     
//     tail->prev = head;
//     tail->next = tail;
//     tail->val = 'T';
     
//     cur = tail;
// }
 
// void left(){
//     if(cur->prev==head) return;
//     cur = cur->prev;
// }
 
// void right(){
//     if(cur==tail) return;
//     cur = cur->next;
// }
 
// //cur 앞쪽에 삽입 
// void insert(char c){
//     node *n = (node*)malloc(sizeof(node));
//     n->prev=cur->prev;
//     n->next=cur;
//     n->val = c;
     
//     cur->prev->next=n;
//     cur->prev=n;
     
// }
 
// //cur 앞쪽에 있는 것 삭제 
// void remove(){
//     if(cur->prev==head) return;
//     node *n = cur->prev;
//     n->prev->next=cur;
//     cur->prev=n->prev;
//     free(n);
// }
 
// void printList(){
//     node *n = head;
//     while(1){
//         n = n->next;
//         if(n==tail) break;
//         printf("%c",n->val);
//     }
//     printf("\n");
// }
 
// char str[100001];
// int N;
// int main(){
//     scanf("%s",str);
//     init();
//     int len = strlen(str);
//     for(int i=0;i<len;++i)   insert(str[i]);
         
//     scanf("%d\n",&N);
//     char c;
//     while(N--){
//         scanf(" %c",&c);
//         if(c=='L'){
//             left(); 
//         }else if(c=='D'){
//             right();
//         }else if(c=='B'){
//             remove();
//         }else if(c=='P'){
//             scanf(" %c",&c);
//             insert(c);
//         }
//     }
     
//     printList();
//     return 0;
// }



//test case 
// abcd
// 3
// P x
// L
// P y