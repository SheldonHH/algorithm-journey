class MinimumPathSum:
    # Bruteforce recursive method
    def min_path_sum1(self, grid):
        return self.f1(grid, len(grid) - 1, len(grid[0]) - 1)

    def f1(self, grid, i, j):
        if i == 0 and j == 0:
            return grid[0][0]
        up = float('inf')
        left = float('inf')
        if i > 0:
            up = self.f1(grid, i - 1, j)
        if j > 0:
            left = self.f1(grid, i, j - 1)
        return grid[i][j] + min(up, left)

    # Memoized recursion
    def min_path_sum2(self, grid):
        n = len(grid)
        m = len(grid[0])
        dp = [[-1] * m for _ in range(n)]
        return self.f2(grid, n - 1, m - 1, dp)

    def f2(self, grid, i, j, dp):
        if dp[i][j] != -1:
            return dp[i][j]
        if i == 0 and j == 0:
            ans = grid[0][0]
        else:
            up = float('inf')
            left = float('inf')
            if i > 0:
                up = self.f2(grid, i - 1, j, dp)
            if j > 0:
                left = self.f2(grid, i, j - 1, dp)
            ans = grid[i][j] + min(up, left)
        dp[i][j] = ans
        return ans

    # Dynamic programming
    def min_path_sum3(self, grid):
        n = len(grid)
        m = len(grid[0])
        dp = [[0] * m for _ in range(n)]
        dp[0][0] = grid[0][0]
        for i in range(1, n):
            dp[i][0] = dp[i - 1][0] + grid[i][0]
        for j in range(1, m):
            dp[0][j] = dp[0][j - 1] + grid[0][j]
        for i in range(1, n):
            for j in range(1, m):
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j]
        return dp[n - 1][m - 1]

    # Dynamic programming with space optimization
    def min_path_sum4(self, grid):
        n = len(grid)
        m = len(grid[0])
        dp = [0] * m
        dp[0] = grid[0][0]
        for j in range(1, m):
            dp[j] = dp[j - 1] + grid[0][j]
        for i in range(1, n):
            dp[0] += grid[i][0]
            for j in range(1, m):
                dp[j] = min(dp[j - 1], dp[j]) + grid[i][j]
        return dp[m - 1]

# Example usage:
grid = [[1, 3, 1], [1, 5, 1], [4, 2, 1]]
solver = MinimumPathSum()
print(solver.min_path_sum1(grid))  # Recursive method
print(solver.min_path_sum2(grid))  # Memoized recursion
print(solver.min_path_sum3(grid))  # DP
print(solver.min_path_sum4(grid))  # DP with space optimization
