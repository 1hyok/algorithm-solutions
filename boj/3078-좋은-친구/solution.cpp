// Problem: 좋은 친구
// URL: https://www.acmicpc.net/problem/3078

#include <iostream>
#include <vector>
#include <bit>
#include <climits>
#include <queue>


using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector name_queue(21, queue<int>());
    long long cnt = 0;
    for (int rank = 1; rank <= n; ++rank)
    {
        string input;
        cin >> input;
        const auto name_length = input.length();
        auto& curr_queue = name_queue[name_length];

        while (!curr_queue.empty() && rank - curr_queue.front() > k)
        {
            curr_queue.pop();
        }
        cnt += curr_queue.size();
        curr_queue.push(rank);
    }

    cout << cnt;
}
