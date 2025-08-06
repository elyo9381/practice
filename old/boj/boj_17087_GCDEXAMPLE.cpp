#include <iostream>

using namespace std;

 

const int MAX = 100000;
int arr[MAX];

 
int GCD(int a, int b)
{
    if (a%b == 0)
        return b;
    return GCD(b, a%b);

}

int lcm(int a, int b)
{
    return a*b / GCD(a,b);
}

 

int main(void)
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int N,S,diff,ans;
        cin >> N >> S;
 
        cin.ignore();

        for(int i =0; i <N; i++)
        {
            int ch;
            cin >>ch;

            diff = S - ch;
            if(diff <0)
            {
                diff = -diff;
            }
            arr[i] = diff;

        }

        ans = arr[0];
        for(int i = 1; i<N; i++)
        {
            ans = GCD(ans,arr[i]);
        }
        cout<< ans<<"\n";
        


        return 0;
}