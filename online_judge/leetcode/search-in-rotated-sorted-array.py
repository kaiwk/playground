class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        n = len(nums)
        low = 0
        high = n - 1
        while low <= high:
            mid = (low + high) // 2

            if nums[mid] == target:
                return mid

            if (nums[mid] - nums[n-1]) * (target - nums[n-1]) > 0:
                if target > nums[mid]:
                    low = mid + 1
                else:
                    high = mid - 1
            elif target < nums[n-1]:
                low = mid + 1
            elif target > nums[n-1]:
                high = mid - 1
            else:
                return n - 1

        return -1
