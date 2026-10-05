# Problem: LeetCode 410
# URL: https://leetcode.com/problems/split-array-largest-sum/

from typing import List


class Solution:
    def splitArray(self, nums: List[int], k: int) -> int:
        def pieces(limit: int) -> int:
            count = 1
            cur = 0
            for x in nums:
                if cur + x > limit:
                    count += 1
                    cur = x
                else:
                    cur += x
            return count

        lo, hi = max(nums), sum(nums)
        while lo < hi:
            mid = (lo + hi) // 2
            if pieces(mid) <= k:
                hi = mid
            else:
                lo = mid + 1
        return lo
