# Problem: LeetCode 37
# URL: https://leetcode.com/problems/sudoku-solver/

from typing import List


class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        rows = [set() for _ in range(9)]
        cols = [set() for _ in range(9)]
        boxes = [set() for _ in range(9)]
        empty = []
        for r in range(9):
            for c in range(9):
                ch = board[r][c]
                if ch == ".":
                    empty.append((r, c))
                else:
                    rows[r].add(ch)
                    cols[c].add(ch)
                    boxes[(r // 3) * 3 + c // 3].add(ch)

        def solve(idx: int) -> bool:
            if idx == len(empty):
                return True
            r, c = empty[idx]
            b = (r // 3) * 3 + c // 3
            for d in "123456789":
                if d in rows[r] or d in cols[c] or d in boxes[b]:
                    continue
                board[r][c] = d
                rows[r].add(d)
                cols[c].add(d)
                boxes[b].add(d)
                if solve(idx + 1):
                    return True
                rows[r].discard(d)
                cols[c].discard(d)
                boxes[b].discard(d)
                board[r][c] = "."
            return False

        solve(0)
