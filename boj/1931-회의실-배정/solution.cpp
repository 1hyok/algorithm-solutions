// Problem: 회의실 배정
// URL: https://www.acmicpc.net/problem/1931

#include <algorithm>
#include <iostream>
#include <vector>
#include <bit>
#include <climits>


using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int, int>> meetings(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> meetings[i].first >> meetings[i].second;
    }

    sort(meetings.begin(), meetings.end(), [](const pair<int, int>& a, const pair<int, int>& b)
    {
        if (a.second == b.second)
        {
            return a.first < b.first;
        }
        return a.second < b.second;
    });

    int cnt = 0;
    int prev = -1;
    for (int i = 0; i < n; ++i)
    {
        if (meetings[i].first >= prev)
        {
            cnt++;
            prev = meetings[i].second;
        }
    }

    cout << cnt;
}
