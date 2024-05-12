from typing import List

# 这个类包含了一个返回整数数组所有可能组合的方法
class Code02_Combinations:
    # 这个函数接受一个可能包含重复元素的整数数组，返回数组的所有可能组合
    # 组合中不包含重复的组合
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        ans = []
        self._backtrack(nums, 0, [], ans)
        return ans

    # 递归函数，用于寻找所有可能的组合
    def _backtrack(self, nums: List[int], start: int, path: List[int], ans: List[List[int]]):
        ans.append(path.copy())
        for i in range(start, len(nums)):
            # 如果当前数字和前一个数字相同，则跳过以防止重复
            if i > start and nums[i] == nums[i - 1]:
                continue
            path.append(nums[i])
            self._backtrack(nums, i + 1, path, ans)
            path.pop()

# 示例使用代码
if __name__ == '__main__':
    nums = [1, 2, 2]  # 示例输入
    obj = Code02_Combinations()
    result = obj.subsetsWithDup(nums)

    # 输出所有可能的组合
    for combination in result:
        print(combination)
