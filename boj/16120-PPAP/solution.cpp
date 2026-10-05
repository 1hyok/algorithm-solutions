// Problem: PPAP
// URL: https://www.acmicpc.net/problem/16120

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

    vector<char> stk;
    for (const char ch : str)
    {
        if (!stk.empty() && stk.back() == 'A')
        {
            if (stk.size() < 3 || ch == 'A')
            {
                cout << "NP";
                return 0;
            }
            stk.pop_back();
            stk.pop_back();
            continue;
        }
        stk.push_back(ch);
    }
    cout << ((stk.size() != 1) || stk.back() == 'A' ? "NP" : "PPAP");
}
