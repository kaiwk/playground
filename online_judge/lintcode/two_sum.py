class Solution:
    """
    @param nums {int[]} n array of Integer
    @param target {int} = nums[index1] + nums[index2]
    @return {int[]} [index1 + 1, index2 + 1] (index1 < index2)
    """
    def twoSum(self, nums, target):
        index1 = 0
        index2 = len(nums) - 1
        while nums[index1] + nums[index2] != target and index1 < index2:
            if nums[index1] + nums[index2] > target:
                index2 -= 1
            elif nums[index1] + nums[index2] < target:
                index1 += 1

        if index1 < index2:
            return [index1+1, index2+1]
