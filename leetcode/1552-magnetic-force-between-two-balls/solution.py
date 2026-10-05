# Problem: LeetCode 1552
# URL: https://leetcode.com/problems/magnetic-force-between-two-balls/

from typing import List


class Solution:
    def maxDistance(self, position: List[int], m: int) -> int:
        position.sort()

        def can_place(gap: int) -> bool:
            count = 1
            last = position[0]
            for p in position[1:]:
                if p - last >= gap:
                    count += 1
                    last = p
                    if count >= m:
                        return True
            return False

        lo, hi = 1, position[-1] - position[0]
        while lo < hi:
            mid = (lo + hi + 1) // 2
            if can_place(mid):
                lo = mid
            else:
                hi = mid - 1
        return lo
