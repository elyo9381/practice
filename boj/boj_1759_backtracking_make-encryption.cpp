// #include <bits/stdc++.h>

// #define endl "\n"
// #define MX 20

// using namespace std;

// typedef long long ll;

// /* 조건을 반대로 생각할줄알아야한다. 
//     mo >=1 && ja>=2 이라는 조건은
//     mo ==0 || ja<2 일때는 건너 뛰라는 말이다 

// */

// int n,m;
// char arr[MX];
// char input[MX];
// bool isused[MX];
// int moeum=0,jaeum=0;

// void dfs(int a,int Idx)
// {
//     if(a == n)
//     {
//         if(moeum == 0 || jaeum < 2)return;
            
//         for(int i=0; i<n; i++)
//         {
//             cout << arr[i];
//         }
//         cout<<endl;
//         return;
        
//     }

//     for(int i = Idx; i<m;i++)
//     {
//         if(!isused[i]){

//         arr[a] = input[i];
//          if(arr[a] =='a'||arr[a] =='e'||arr[a] =='i'||arr[a] =='o'||arr[a] =='u')moeum++;
//          else jaeum++;
//          isused[i]=true;
//         dfs(a+1,i);

//         isused[i]=false;
//         if(arr[a] =='a'||arr[a] =='e'||arr[a] =='i'||arr[a] =='o'||arr[a] =='u')moeum--;
//         else jaeum--;
//         }
//     }
// }

// int main(void) {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);

        
//         cin>> n >> m;

//         for(int i = 0 ;i < m; i++){
//             cin>> input[i];
//         }

//         sort(input,input+m);

//         dfs(0,0);


//     return 0;
//     }


#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
char v[16];
bool chk[16];
int n,c;
vector<char> ans;

inline bool isvowel(char c) {
    return c=='a'||c=='i'||c=='o'||c=='u'||c=='e';
}

void dfs(int s, int vo, int co, vector<char> &ans) {
    if(ans.size()==n) {
        if(vo>=1 && co>=2) {
            for(char c: ans) putchar(c);
            puts("");
        }
        return;
    } else if(s==c) return;

    if(isvowel(v[s])) {
        ans.push_back(v[s]);//emplace_back 가능
        dfs(s+1,vo+1,co,ans);
        ans.pop_back();
    } else{
        ans.push_back(v[s]);
        dfs(s+1,vo,co+1,ans);
        ans.pop_back();
    }
    dfs(s+1,vo,co,ans);
}


int main(){
    scanf("%d%d",&n,&c);
    char s[2];
    for(int i=0; i<c; i++){
        scanf("%s",s);
        v[i]=s[0];
    }
    sort(v,v+c);
    dfs(0,0,0,ans);
    return 0;
}