class Solution:
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        n1 = len(nums1)
        n2 = len(nums2)

        total = n1 + n2
        mid = total // 2

        nums1.append(sys.maxsize)
        nums2.append(sys.maxsize)

        i = 0
        j = 0
        mid1 = 0
        mid2 = 0
        while i + j <= mid:
            mid2 = mid1
            if nums1[i] < nums2[j]:
                mid1 = nums1[i]
                i += 1
            else:
                mid1 = nums2[j]
                j += 1

        if total % 2 == 1:
            return mid1
        else:
            return (mid1 + mid2) / 2
