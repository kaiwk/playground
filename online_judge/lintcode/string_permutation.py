class Solution(object):
    # @param {string} A a string
    # @param {string} B a string
    # @return {boolean} a boolean
    def stringPermutation(self, A, B):

        if len(A) != len(B):
            return False

        is_permutation = True
        for c in A:
            if A.count(c) != B.count(c):
                is_permutation = False
                break
        return is_permutation


print(Solution().stringPermutation('abcd', 'dcba'))
