// Problem: 두 용액
// URL: https://www.acmicpc.net/problem/2470

#include <algorithm>
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
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    ranges::sort(arr);

    int result_a = 0, result_b = 1;
    int min_abs = abs(arr[result_a] + arr[result_b]);
    for (int i = 0; i < n; ++i)
    {
        int low = i + 1, high = n - 1;
        while (low <= high)
        {
            const int mid = (low + high) / 2;
            const int sum = arr[i] + arr[mid];
            if (sum > 0)
            {
                if (sum < min_abs)
                {
                    min_abs = sum;
                    result_a = i;
                    result_b = mid;
                }
                high = mid - 1;
                continue;
            }
            if (-sum < min_abs)
            {
                min_abs = -sum;
                result_a = i;
                result_b = mid;
            }
            low = mid + 1;
        }
    }
    cout << arr[result_a] << " " << arr[result_b];
}
