class Solution:
    def solveNQueens(self, n: int):
        MASK = (1 << n) - 1
        ans, board = [], [0] * n  # board[r] = column index of queen at row r

        def dfs(row: int, cols: int, d1: int, d2: int):
            if row == n:
                ans.append(["." * c + "Q" + "." * (n - c - 1) for c in board])
                return
            avail = ~(cols | d1 | d2) & MASK  # bits = free columns this row
            while avail:
                p = avail & -avail          # take lowest available column bit
                avail ^= p
                c = p.bit_length() - 1      # column index
                board[row] = c
                # place p; for next row, diagonals shift: ↘ is <<1, ↙ is >>1
                dfs(row + 1,
                    cols | p,
                    ((d1 | p) << 1) & MASK,
                    ((d2 | p) >> 1))

        dfs(0, 0, 0, 0)
        return ans