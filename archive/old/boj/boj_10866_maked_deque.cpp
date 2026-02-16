#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <iostream>
#include <string>
#include <time.h>
#include <stack>
#include <vector>
#include <list>
#include <deque>
using namespace std;

/**/



 

int main(void)
{
    int t;

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    //빈 컨테이너를 생선한다.
    deque<int> dq;

    cin>> t;
    cin.ignore();
    while(t--)
    {
        string str;
        cin>> str;       

        if(str=="push_front")
        {
            int num;
            cin>>num;
            dq.push_front(num);
        }
        else if(str == "push_back")
        {
            int num;
            cin>>num;
            dq.push_back(num);
        }
         else if(str == "pop_front")
        {
            if(!dq.empty())
            {
               cout<<dq.front()<<endl;
               dq.pop_front();

            }
            else
            {
                cout<<"-1"<<"\n";
            }
        }
        else if(str == "pop_back")
        {
            if(!dq.empty())
            {
               cout<<dq.back()<<endl;
               dq.pop_back();

            }
            else
            {
                cout<<"-1"<<"\n";
            }
        }
         else if(str == "size")
        {
            cout<<dq.size()<<"\n";
        }
        else if(str=="empty")
        {
           cout<<dq.empty()<<"\n";
        }

         else if(str == "front")
        {
            if(!dq.empty())
            {
                cout << dq.front() << endl;
            }
            else
            {
                cout<<"-1"<<"\n";
            }
        }
        else if(str=="back")
        {
            if (!dq.empty())
            {   
                cout<<dq.back()<<endl;
            }
            else
                cout << -1 << endl;
        }
    }


    return 0;



    
}


// test case
// 15
// push_back 1
// push_front 2
// front
// back
// size
// empty
// pop_front
// pop_back
// pop_front
// size
// empty
// pop_back
// push_front 3
// empty
// front



// deque dq

// dq는 빈 컨테이너이다. 

// deque dq(n)

// dq는 기본값으로 초기화된 n개의 원소를 갖는다. 

// deque dq(n,x)

// dq는 x 값으로 초기화된 n 개의 원소를 갖는다. 

// deque dq(dq2)

// dq는 dq2 컨테이너의 복사본이다. 

// deque dq(b,e)

// dq는 반복자 구간 [b,e)로 초기화된 원소를 갖는다. 





// 멤버 함수 

// dq.assign(n,x)

// dq에 x 값으로 n 개의 원소를 할당한다 

// dq.assign(b,e)

// dq를 반복자 구간 [b,e)로 할당한다. 

// dq.at(i) 

// dq의 i번째 원소를 참조한다. 

// dq.back()

// dq의 마지막 원소를 참조한다. 

// p=dq.begin()

// p는 dq의 첫 원소를 가리키는 반복자다 

// dq.clear()

// dq의 모든 원소를 제거한다. 

// dq.empty()

// dq가 비었는지 조사한다. 

// p=dq.end()

// p는 dq의 끝을 표식하는 반복자다 

// q=dq.erase(p)

// p가 가리키는 원소를 제거한다. q는 다음 원소를 가리킨다. 

// q=dq.erase(b,e)    반복자 구간 [b,e)의 모든 원소를 제거한다. q는 다음 원소다 
// dq.front()

// dq의 첫 번째 원소를 참조한다. 
// q=dq.insert(p,x)   
// p가 가리키는 위치에 x 값을 삽입한다. q는 삽입한 원소를 가리킨다. 

// dq.insert(p, n, x)

// p가 가리키는 위치에 n 개의 x 값을 삽입한다. 
// dq.insert(p, b, e)

// p가 가리키는 위치에 반복자 구간 [b,e)의 원소를 삽입한다. 

// x=dq.max_size()

// x는 dq가 담을 수 있는 최대 원소의 개수이다. 

// dq.pop_back()

// dq의 마지막 원소를 제거한다. 

// dq.pop_front()

// dq의 첫 원소를 제거한다. 
// dq.push_back() dq의 끝에 x를 추가한다. 
// dq.push_front()    
// dq의 앞쪽에 x를 추가한다. 

// p=dq.rbegin()

// p는 dq의 역 순차열의 첫 원소를 가리키는 반복자이다. 
// p=dq.rend()    p는 dq의 역 순차의 끝을 표식하는 반복자 
// dq.resize(n)

// dq의 크기를 n으로 변경하고 확장되는 공간의 값을 기본값으로 초기화한다. 
// dq.resize(n,x) dq의 크기를 n으로 변경하고 확장되는 공간의 값을 x 값으로 초기화한다. 
// dq.size()

// dq 원소의 개수다 
// dq.swap(dq2)   
// dq와 dq2를 swap 한다. 



#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

const int MX = 1000007;

int dat[2*MX+3];
//스택/큐와 달리 왼쪽으로도 확장되기 때문에
//0번지에서 시작하는게 아니라 중간에서 시작함
int head= MX, tail =MX;

// 길이는 여전히 tail-head
void push_front(int val){
    dat[--head] = val;
}

void push_back(int val){
    dat[tail++] = val;
}

void pop_front(){
    head++;
}

void pop_back(){
    tail--;
}

int front(){
    return dat[head];
}

int back(){
    return dat[tail -1];
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    while(n--){
        string q;
        cin >> q;
        if(q == "push_back"){
            int val;
            cin>> val;
            push_back(val);

        }

        else if(q =="push_front")
        {
            int val;
            cin >> val;
            push_front(val);
        }
        else if(q== "pop_front"){
            if(tail==head) cout<< -1 <<endl;
            else{
                cout<< front() << endl;
                pop_front();
            }
        }
        else if(q == "pop_back"){
            if(tail == head) cout<< -1 <<endl;
            else{
                cout<< back()<< endl;
                pop_bakc();
            }
        }

        else if(q== "size")
            cout<< tail-head<<endl;
        else if( q == "empty")
            cout<<(tail==head)<<endl;
        else if( q =="front"){
            if(tail==head) cout<< -1<<endl;
            else cout<< front()<<endl;
        }
        else {
            if(tail == head) cout<< -1<<endl;
            else cout<< back()<<endl;
        }   
    }
}
