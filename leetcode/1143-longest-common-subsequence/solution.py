# Problem: LeetCode 1143
# URL: https://leetcode.com/problems/longest-common-subsequence/

class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        prev = [0] * (len(text2) + 1)
        for a in text1:
            cur = [0] * (len(text2) + 1)
            for j, b in enumerate(text2, 1):
                cur[j] = prev[j - 1] + 1 if a == b else max(prev[j], cur[j - 1])
            prev = cur
        return prev[-1]
