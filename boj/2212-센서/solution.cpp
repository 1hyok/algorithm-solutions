// Problem: 센서
// URL: https://www.acmicpc.net/problem/2212

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

    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    vector<int> interval(n - 1);
    for (int i = 0; i < n - 1; ++i)
    {
        interval[i] = arr[i + 1] - arr[i];
    }

    sort(interval.begin(), interval.end());

    int sum = 0;
    for (int i = 0; i < n - 1 - (k - 1); ++i)
    {
        sum += interval[i];
    }

    cout << sum;
}
