// Problem: 창고 다각형
// URL: https://www.acmicpc.net/problem/2304

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; ++i)
    {
        int l, h;
        cin >> l >> h;
        arr[i] = {l, h};
    }

    ranges::sort(arr);

    // 가장 높은 기둥 찾기
    int highest_idx = 0;
    for (int i = 0; i < n; ++i)
    {
        if (arr[i].second > arr[highest_idx].second)
        {
            highest_idx = i;
        }
    }

    int area = 0;
    int max_h = 0;

    // 왼쪽에서 최고점까지
    for (int i = 0; i < highest_idx; i++) {
        max_h = max(max_h, arr[i].second);
        area += max_h * (arr[i+1].first - arr[i].first);
    }

    // 오른쪽에서 최고점까지
    max_h = 0;
    for (int i = n-1; i > highest_idx; i--) {
        max_h = max(max_h, arr[i].second);
        area += max_h * (arr[i].first - arr[i-1].first);
    }

    // 최고점 기둥 면적
    area += arr[highest_idx].second;

    cout << area << '\n';

    return 0;
}
