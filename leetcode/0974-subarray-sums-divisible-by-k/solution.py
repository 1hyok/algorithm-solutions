# Problem: LeetCode 974
# URL: https://leetcode.com/problems/subarray-sums-divisible-by-k/

from typing import List


class Solution:
    def subarraysDivByK(self, nums: List[int], k: int) -> int:
        seen = [0] * k
        seen[0] = 1
        prefix = 0
        result = 0
        for x in nums:
            prefix = (prefix + x) % k
            result += seen[prefix]
            seen[prefix] += 1
        return result
