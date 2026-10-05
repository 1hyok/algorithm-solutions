# Problem: LeetCode 2050
# URL: https://leetcode.com/problems/parallel-courses-iii/

from collections import deque
from typing import List


class Solution:
    def minimumTime(self, n: int, relations: List[List[int]], time: List[int]) -> int:
        graph = [[] for _ in range(n)]
        indegree = [0] * n
        for a, b in relations:
            graph[a - 1].append(b - 1)
            indegree[b - 1] += 1
        finish = time[:]
        queue = deque(i for i in range(n) if indegree[i] == 0)
        while queue:
            u = queue.popleft()
            for v in graph[u]:
                finish[v] = max(finish[v], finish[u] + time[v])
                indegree[v] -= 1
                if indegree[v] == 0:
                    queue.append(v)
        return max(finish)
