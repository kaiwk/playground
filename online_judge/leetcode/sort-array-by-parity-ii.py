# Solution 1
class Solution(object):
    def sortArrayByParityII(self, A):
        """
        :type A: List[int]
        :rtype: List[int]
        """
        i = 0
        n = len(A)
        for j in range(n):
            if A[j] % 2 == 0:
                A[i], A[j] = A[j], A[i]
                i += 1

        k = n // 2
        if k % 2 == 0:
            for j in range(k):
                if j % 2 == 1:
                    A[j], A[k+j-1] = A[k+j-1], A[j]
        else:
            for j in range(k):
                if j % 2 == 1:
                    A[j], A[k+j] = A[k+j], A[j]

        return A

# Solution 2
class Solution2(object):
    def sortArrayByParityII(self, A):
        """
        :type A: List[int]
        :rtype: List[int]
        """
        i = 0
        j = 1
        n = len(A)
        while i < n and j < n:
            while i < n and A[i] % 2 == 0:
                i += 2
            while j < n and A[j] % 2 == 1:
                j += 2
            if i < n and j < n:
                A[i], A[j] = A[j], A[i]

        return A
