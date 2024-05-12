import random

# 插入、删除和获取随机元素O(1)时间且允许有重复数字的结构
class RandomizedCollection:
    def __init__(self):
        self.idx = {}  # Maps values to sets of indices where they appear in the list
        self.nums = []  # Stores all elements, including duplicates

    def insert(self, val):
        """ Inserts a value to the collection. Returns true if the collection did not already contain the specified element. """
        self.nums.append(val)
        if val in self.idx:
            self.idx[val].add(len(self.nums) - 1)
            return False
        else:
            self.idx[val] = {len(self.nums) - 1}
            return True

    def remove(self, val):
        """ Removes a value from the collection. Returns true if the collection contained the specified element. """
        if val not in self.idx or not self.idx[val]:
            return False
        last_element = self.nums[-1]
        idx_to_remove = self.idx[val].pop()  # Remove any index of the element to be removed

        # If it's not the last element, swap it with the last one
        if idx_to_remove != len(self.nums) - 1:
            self.nums[idx_to_remove] = last_element
            self.idx[last_element].add(idx_to_remove)
            self.idx[last_element].remove(len(self.nums) - 1)

        self.nums.pop()  # Remove the last element from the list

        if not self.idx[val]:
            del self.idx[val]

        return True

    def getRandom(self):
        """ Get a random element from the collection. """
        return random.choice(self.nums
