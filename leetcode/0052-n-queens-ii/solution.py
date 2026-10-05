# Problem: LeetCode 52
# URL: https://leetcode.com/problems/n-queens-ii/

class Solution:
    def totalNQueens(self, n: int) -> int:
        full = (1 << n) - 1

        def place(cols: int, diag1: int, diag2: int) -> int:
            if cols == full:
                return 1
            total = 0
            free = full & ~(cols | diag1 | diag2)
            while free:
                bit = free & -free
                free -= bit
                total += place(cols | bit, ((diag1 | bit) << 1) & full, (diag2 | bit) >> 1)
            return total

        return place(0, 0, 0)
