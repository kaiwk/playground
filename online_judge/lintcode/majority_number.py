class Solution(object):

    def majorityNumber(self, nums):

        majority = nums[0]
        count = 1
        for i in range(1, nums):
            if majority == nums[i]:
                count += 1
            elif count == 0:
                majority = nums[i]
            else:
                count -= 1

        return majority
