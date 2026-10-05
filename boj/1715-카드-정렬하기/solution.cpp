// Problem: 카드 정렬하기
// URL: https://www.acmicpc.net/problem/1715

#include <iostream>
#include <vector>
#include <bit>
#include <climits>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; ++i)
    {
        int num;
        cin >> num;
        pq.push(num);
    }

    int compare = 0;
    while (pq.size() > 1)
    {
        const int t1 = pq.top();
        pq.pop();
        const int t2 = pq.top();
        pq.pop();
        compare += t1 + t2;
        pq.push(t1 + t2);
    }

    cout << compare;
}
