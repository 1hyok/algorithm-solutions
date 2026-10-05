// Problem: N과 M (9)
// URL: https://www.acmicpc.net/problem/15663

#include <iostream>
#include <vector>
#include <bit>
#include <climits>
#include <algorithm>

using namespace std;

vector<int> arr;
vector<bool> visit;
vector<int> result;
int n, m;

void go(const int idx, const int depth)
{
    // cout << "n:" << n << '\n';
    // cout << "m:" << m << '\n';
    // cout << "idx:" << idx << '\n';
    // cout << "depth:" << depth << '\n';
    if (depth == m)
    {
        for (const int& result1 : result)
        {
            cout << result1 << " ";
        }
        cout << '\n';
        return;
    }
    for (int i = 0; i < n; ++i)
    {
        if (visit[i] || (i - 1 >= 0 && !visit[i - 1] && arr[i - 1] == arr[i]))
        {
            continue;
        }
        visit[i] = true;
        result[depth] = arr[i];
        go(i, depth + 1);
        visit[i] = false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    arr.resize(n);
    visit.resize(n);
    result.resize(m);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    go(-1, 0);
}
