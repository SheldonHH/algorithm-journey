class Code06_MaximumSubmatrix:
    @staticmethod
    def getMaxMatrix(grid):
        n = len(grid)
        m = len(grid[0])
        max_sum = float('-inf')
        result = [0, 0, 0, 0]  # 存储结果的坐标 (a, b, c, d)
        nums = [0] * m
        for up in range(n):
            nums = [0] * m
            for down in range(up, n):
                pre = float('-inf')
                l = 0
                for r in range(m):
                    nums[r] += grid[down][r]
                    if pre >= 0:
                        pre += nums[r]
                    else:
                        pre = nums[r]
                        l = r
                    if pre > max_sum:
                        max_sum = pre
                        result = [up, l, down, r]
        return result

