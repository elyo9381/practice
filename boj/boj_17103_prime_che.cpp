#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1000000;

/*에라스토 테네스의 체를 이용해서 풀었고 
골드바흐 파티션은 소수 두개를 더해서 짝수가 나오는 수이다.
소수가 중복되어도 가능하니 이를 고려했어야했다. */

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;


    vector<bool> check(MAX+1);
    vector<int> prime;
    for(int i =2; i<=MAX;i++)
    {
        if(check[i] == false)
        {
            prime.push_back(i);

            for (int j = i * 2; j <= MAX; j += i)
                check[j] = true;
        }
    }

    cin  >> t;
    cin.ignore();

    for(;t!=0;t--)
    {
        int num; 
        cin >> num; 
        int sum =0;

        for(int i = 0 ; prime[i]<num;i++)
        {
            int a = prime[i];
            int b = num - prime[i];
           if(num - prime[i] >= prime[i] && !check[b])
            sum++;
        }

        cout<<sum<<"\n";
        
        
    }

}