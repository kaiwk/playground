class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        record = dict()
        for i in range(len(nums)):
            if nums[i] in record:
                return [record[nums[i]], i]
            record[target-nums[i]] = i
        return [-1, -1]
