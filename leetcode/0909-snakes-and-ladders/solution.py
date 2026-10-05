# Problem: LeetCode 909
# URL: https://leetcode.com/problems/snakes-and-ladders/

from collections import deque
from typing import List


class Solution:
    def snakesAndLadders(self, board: List[List[int]]) -> int:
        n = len(board)
        cells = []
        for i, row in enumerate(reversed(board)):
            cells.extend(row if i % 2 == 0 else reversed(row))
        target = n * n
        dist = [-1] * (target + 1)
        dist[1] = 0
        queue = deque([1])
        while queue:
            cur = queue.popleft()
            for step in range(1, 7):
                nxt = cur + step
                if nxt > target:
                    break
                dest = cells[nxt - 1] if cells[nxt - 1] != -1 else nxt
                if dist[dest] == -1:
                    dist[dest] = dist[cur] + 1
                    if dest == target:
                        return dist[dest]
                    queue.append(dest)
        return dist[target]
