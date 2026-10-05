// Problem: 과일 탕후루
// URL: https://www.acmicpc.net/problem/30804

#include <iostream>
#include <vector>
#include <bit>
#include <stack>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> fruit(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> fruit[i];
    }

    vector<int> check(10);
    int left = 0, right = 0, cnt = 1;
    check[fruit[left]]++;
    int max_cnt = 1;
    while (left <= right)
    {
        if (cnt <= 2)
        {
            max_cnt = max(max_cnt, right - left + 1);
            if (right == n - 1)
            {
                break;
            }
            right++;
            if (check[fruit[right]]++ == 0)
            {
                cnt++;
            }
            continue;
        }

        if (--check[fruit[left]] == 0)
        {
            cnt--;
        }
        left++;
    }

    cout << max_cnt;
}
