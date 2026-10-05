// Problem: 쇠막대기
// URL: https://www.acmicpc.net/problem/10799

#include <iostream>
#include <vector>
#include <bit>
#include <climits>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    cin >> str;
    vector<int> stk;
    int cnt = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == ')')
        {
            if (i - stk.back() == 1)
            {
                cnt += stk.size() - 1;
            }
            else
            {
                cnt++;
            }
            stk.pop_back();
            continue;
        }
        stk.push_back(i);
    }

    cout << cnt;
}
