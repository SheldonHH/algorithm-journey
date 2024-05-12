def find(arr, m):
    # Initialize a counter for each bit position
    cnts = [0] * 32
    
    # Count the number of 1s at each bit position across all numbers
    for num in arr:
        for i in range(32):
            cnts[i] += (num >> i) & 1

    ans = 0
    # Use the modulo operation to determine which bits should be set in the result
    for i in range(32):
        if cnts[i] % m != 0:
            ans |= (1 << i)

    return ans

def singleNumber(nums):
    return find(nums, 3)

if __name__ == "__main__":
    nums = [2, 2, 3, 2] # Example
    print(singleNumber(nums)) # Expected output: 3
