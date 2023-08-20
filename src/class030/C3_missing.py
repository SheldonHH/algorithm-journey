# Find the missing number
def missingNumber(nums):
    eorAll, eorHas = 0, 0
    for i, num in enumerate(nums):
        eorAll ^= i
        eorHas ^= num
    eorAll ^= len(nums)
    return eorAll ^ eorHas

if __name__ == "__main__":
    nums = [3, 0, 1] # Example
    print(missingNumber(nums)) # Expected output: 2
