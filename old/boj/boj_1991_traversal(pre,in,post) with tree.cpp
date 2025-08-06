
#include <bits/stdc++.h>
#define endl '\n'
#define MAXN 4000
typedef long long ll;
using namespace std;

/*
  이진트리에 입력받는법
  원래라면 구조체 혹은 클래스를 사용해서 받아야겠지만 
  나는 2가지 배열을 통해서 입력을 받으면 훨씬 좋다.
  lc와 rc 배열을 만들고 두 배열에 해당 1번 인덱스에 root의 lc,rc를 입력한다. 
  이런식으로 이진트리임으로 인덱스 2의 lc,rc를 작성하고 인덱스 별로 증가하게끔 
  입력을 받는다. 이때 자식이 없는 경우도 있으니 if(lc!=null) ~~ 이거나 if(lc != '.') 일때가 
  자식이 없는 경우라고 한다면 이때를 고려해서 입력받고록 한다. 
*/
int T;
int lc[30];
int rc[30];

void preorder(int cur){
  cout << char(cur+'A'-1);
  if(lc[cur] != 0) preorder(lc[cur]);
  if(rc[cur] != 0) preorder(rc[cur]);  
}

void inorder(int cur){
  if(lc[cur] != 0) inorder(lc[cur]);
  cout << char(cur+'A'-1);
  if(rc[cur] != 0) inorder(rc[cur]);
}

void postorder(int cur){
  if(lc[cur] != 0) postorder(lc[cur]);
  if(rc[cur] != 0) postorder(rc[cur]);
  cout << char(cur+'A'-1);  
}


void Input()
{
    cin >> T;
    for(int i =1; i<=T; i++){
        char c,l,r; 
        cin >> c >> l >> r;
        if(l != '.') lc[c-'A'+1] = l-'A'+1;
        if(r != '.') rc[c-'A'+1] = r-'A'+1;
    }

    preorder(1); cout<<'\n';
    inorder(1); cout<<'\n';
    postorder(1); cout<<'\n';

}

void Solution()
{  
}

void Solve()
{
    Input();
    Solution();
}


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solve();
    return 0;
}

    