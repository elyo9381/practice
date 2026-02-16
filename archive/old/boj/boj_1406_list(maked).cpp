#include <bits/stdc++.h>
// #include <vector>
using namespace std;
const int maxn =1000000;

const int MX = 1000005;
int dat[MX];
int pre[MX];
int nex[MX];
int unused = 1;


int insert(int idx, char val)
{
    dat[unused] = val;
    pre[unused] = idx;
    nex[unused] = nex[idx];
    if(nex[idx]!=-1) pre[nex[idx]] = unused;

    nex[idx] = unused;
    unused++;
    return nex[idx];
}

//
int erase(int idx)
{
    nex[pre[idx]] = nex[idx];
    if(nex[idx] != -1) pre[nex[idx]] = pre[idx];

    return pre[idx];
}

void traversal()
{
    int cur = nex[0];
    while(cur != -1){
        cout<< char(dat[cur]);
        cur = nex[cur];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    fill(pre,pre+MX,-1);
    fill(nex,nex+MX,-1);
    // int pos = 0;

    // pos=insert(pos,'a');
    // cout<<pos<<endl;

    // pos = insert(pos,'b');
    // cout<<pos<<endl;

    // pos = insert(pos,'c');
    // cout<<pos<<endl;

    // pos = erase(pos-1);
    // cout<<pos<<endl;
    //  cout<<"\n";

    //  traversal();

    //      cout<<"\n"; 

    // for(int i = 0; i<10;i++)
    //     cout<< nex[i]<<" ";

    string init;
    cin >> init;
    // list<char> L;
    int pos = 0;
    for(auto c : init){
    pos = insert(pos, c);
    }
    int Q;
    cin >> Q;
    string tmp;
    getline(cin,tmp); // 줄바꿈 한 개 제거
    while (Q--) { // Q번 반복
        string op;
    getline(cin,op);
        if (op[0] == 'P') {
      pos = insert(pos, op[2]);
        }
        else if (op[0] == 'L') {
      if(pre[pos] != -1) pos = pre[pos];
        }
        else if (op[0] == 'D') {
      if(nex[pos] != -1) pos = nex[pos];
        }
        else {
            if (pos != 0) {
        pos = erase(pos);
            }
        }
    }
    // traversal();

    for(int i = 0; i<10;i++)
        cout<< dat[i]<<" ";
    cout<<endl;
        for(int i = 0; i<10;i++)
        cout<< pre[i]<<" ";
    cout<<endl;
    for(int i = 0; i<10;i++)
        cout<< nex[i]<<" ";
    cout<<endl;
}