// Problem: 개똥벌레
// URL: https://www.acmicpc.net/problem/3020

#include <iostream>
#include <vector>
#include <bit>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, h;
    cin >> n >> h;
    vector<int> floor(h + 1);
    vector<int> ceiling(h + 1);

    for (int i = 0; i < n; ++i)
    {
        int input;
        cin >> input;
        if (i % 2 == 0)
        {
            floor[input]++;
        }
        else
        {
            ceiling[h - input + 1]++;
        }
    }

    // // 누적합 계산 후에 이걸 추가해봐
    // cout << "floor array: ";
    // for (int i = 1; i <= h; i++)
    // {
    //     cout << floor[i] << " ";
    // }
    // cout << endl;
    //
    // cout << "ceiling array: ";
    // for (int i = 1; i <= h; i++)
    // {
    //     cout << ceiling[i] << " ";
    // }
    // cout << endl;
    //
    // // 각 구간별 장애물 개수도 출력
    // cout << "obstacles per section: ";
    // for (int i = 1; i <= h; i++)
    // {
    //     cout << ceiling[i] + floor[i] << " ";
    // }
    // cout << endl;

    for (int i = 2; i <= h; ++i)
    {
        ceiling[i] += ceiling[i - 1];
        floor[h - i + 1] += floor[h - i + 2];
    }

    // // 누적합 계산 후에 이걸 추가해봐
    // cout << "floor array: ";
    // for (int i = 1; i <= h; i++)
    // {
    //     cout << floor[i] << " ";
    // }
    // cout << endl;
    //
    // cout << "ceiling array: ";
    // for (int i = 1; i <= h; i++)
    // {
    //     cout << ceiling[i] << " ";
    // }
    // cout << endl;
    //
    // // 각 구간별 장애물 개수도 출력
    // cout << "obstacles per section: ";
    // for (int i = 1; i <= h; i++)
    // {
    //     cout << ceiling[i] + floor[i] << " ";
    // }
    // cout << endl;

    int result = 200000;
    int cnt = 1;
    for (int i = 1; i <= h; ++i)
    {
        if (ceiling[i] + floor[i] < result)
        {
            result = ceiling[i] + floor[i];
            cnt = 1;
            continue;
        }
        if (ceiling[i] + floor[i] == result)cnt++;
    }

    cout << result << " " << cnt;
}
