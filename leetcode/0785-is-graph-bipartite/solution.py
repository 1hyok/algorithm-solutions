# Problem: LeetCode 785
# URL: https://leetcode.com/problems/is-graph-bipartite/

from collections import deque
from typing import List


class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        color = [0] * len(graph)
        for start in range(len(graph)):
            if color[start]:
                continue
            color[start] = 1
            queue = deque([start])
            while queue:
                u = queue.popleft()
                for v in graph[u]:
                    if color[v] == 0:
                        color[v] = -color[u]
                        queue.append(v)
                    elif color[v] == color[u]:
                        return False
        return True
