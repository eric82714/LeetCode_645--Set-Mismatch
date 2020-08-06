class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        length, total, unique = len(nums), sum(nums), sum(set(nums))
        return [total - unique, sum(range(1, length + 1)) - unique]
