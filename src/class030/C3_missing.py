# 寻找缺失数字
def missingNumber(nums):
    eorAll, eorHas = 0, 0  # 初始化两个异或变量，eorAll 用来记录从 0 到 n 的异或结果，eorHas 用来记录数组中所有元素的异或结果

    # 遍历数组的索引和元素
    for i, num in enumerate(nums):
        eorAll ^= i  # 异或当前索引，通过索引异或建立完整序列的异或结果
        eorHas ^= num  # 异或当前元素，记录数组中存在的数字的异或结果

    eorAll ^= len(nums)  # 最后再将 n（即数组长度，因为数组是从0开始到n-1的n个数）也进行异或操作，以包含序列最后的数字

    return eorAll ^ eorHas  # 返回两个异或结果的异或，即为缺失的数字

# 主函数
if __name__ == "__main__":
    nums = [3, 0, 1]  # 示例数组
    print(missingNumber(nums))  # 预期输出：2，因为 2 是缺失的数字