#include <bits/stdc++.h>
// #include <vector>
using namespace std;

/* 입출력에 대한 모든것  */
const int mod =9901;
const int maxn = 100000;

long long dp[maxn+1][3];

int buf[maxn+1];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    

    // 한줄에 공백까지 다 입력 받아서 배열에 
    // 0이 아닐때까지 출력한다. 

    // char input[101];
    // while(true){
    //     cin.getline(input,101);
    //     if(strlen(input) == 0)
    //         break;
    //     printf("%s\n", input);
    // }


    // // fgets를 통해서 받기 
    // // fgets는 뒤에 개행문자가 붇는다.
    // char str[102];
    // // fgets str을 통해서 str사이즈만큼 입력받고
    // // stdin 표준입력버퍼에서 문자열을 가져온다.

    // while(fgets(str, sizeof(str), stdin)!=NULL)
    //     printf("%s",str);


    // cin의 다른방법 으로 입력받기 
    // while (!cin.eof()){
    //     cin.getline(str, 105);
    //     printf("%s\n", str);
    // }

    #include <bits/stdc++.h>
// #include <vector>
using namespace std;

/* */
const int mod =9901;
const int maxn = 1000000;

// long long dp[maxn+1][3];

// int buf[maxn+1];

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
    
//     // getliine 개행문자를 포함해서 읽음
//     // char gl[1000];
//     // cin.getline(gl,1000);
//     // int a=strlen(gl);
//     // cout<<gl[a]<<endl;


//     // fgets를 통해서 받기 
//     // fgets도 개행문자를 받음 
//     char str[1000001];
//     // fgets str을 통해서 str사이즈만큼 입력받고
//     // stdin 표준입력버퍼에서 문자열을 가져온다.

//     fgets(str, sizeof(str), stdin);
//     int cnt=0;
//     int len = strlen(str);

//     if(str[0] == ' ') cnt--;

//     for(int i=0; i<len;i++)
//     {
//         if(str[i]==' ') cnt++;
//     }

//     if(str[len-1]==' ') cnt--;
    
//     cout<<cnt+1<<endl;


//     return 0;
//     }


    return 0;

}



