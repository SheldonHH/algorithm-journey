class Code03_MaximumSumCircularSubarray:
    def max_subarray_sum_circular(self, nums):
        n = len(nums)
        all_sum = nums[0]
        max_sum = nums[0]
        min_sum = nums[0]
        max_pre = nums[0]
        min_pre = nums[0]

        for i in range(1, n):
            all_sum += nums[i]
            max_pre = max(nums[i], nums[i] + max_pre)
            max_sum = max(max_sum, max_pre)
            min_pre = min(nums[i], nums[i] + min_pre)
            min_sum = min(min_sum, min_pre)

        # Handle the case where all elements are negative
        if all_sum == min_sum:
            return max_sum
        # Return the maximum of normal max subarray and circular subarray
        return max(max_sum, all_sum - min_sum)

# Example usage
if __name__ == "__main__":
    solution = Code03_MaximumSumCircularSubarray()
    nums = [5, -3, 5]
    print("Maximum Circular Subarray Sum:", solution.max_subarray_sum_circular(nums))
