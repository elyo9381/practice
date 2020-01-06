#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1000000;  // 6 <= n <= 1,000,000

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 에라토네스의 체를 사용하여 1~MAX범위에서 소수만 찾아냄
    vector<bool> check(MAX + 1);
    vector<int> prime_vec;

    check[0] = check[1] = true;
    for (int i = 2; i <= MAX; i++)
    {
        if (check[i] == false)
        {
            prime_vec.push_back(i);

            for (int j = i * 2; j <= MAX; j += i)
                check[j] = true;
        }
    }

    int N;
    while (cin >> N && N != 0)
    {
        // N = prime_vec[i] + b 이 되는 소수 b를 찾음. 즉, b = N - prime_vec[i] 가 소수인지 아닌지 판단하면 됨.
        bool is_find = false;

        for (int i = 0; prime_vec[i] < N; i++)
        {
            int a = prime_vec[i];
            int b = N-prime_vec[i];

            if (check[b] == false)
            {
                cout << N << " = " << a << " + " << b << "\n";
                is_find = true;
                break;
            }
        }

        if (!is_find)
            cout << "Goldbach's conjecture is wrong.\n";
    }
}