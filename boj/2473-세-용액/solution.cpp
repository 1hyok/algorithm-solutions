// Problem: 세 용액
// URL: https://www.acmicpc.net/problem/2473

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
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    int result_a = 0, result_b = 1, result_c = 2;
    auto min_abs = abs(static_cast<long long>(arr[result_a]) + arr[result_b] + arr[result_c]);

    for (int mid = 1; mid < n - 1; ++mid)
    {
        int left = mid - 1, right = mid + 1;
        while (left >= 0 && right < n)
        {
            const auto sum = static_cast<long long>(arr[left]) + arr[mid] + arr[right];
            if (abs(sum) < min_abs)
            {
                min_abs = abs(sum);
                result_a = left;
                result_b = mid;
                result_c = right;
            }
            if (sum > 0)
            {
                left--;
            }
            else
            {
                right++;
            }
        }
    }
    cout << arr[result_a] << " " << arr[result_b] << " " << arr[result_c];
}
