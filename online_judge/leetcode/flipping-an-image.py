class Solution(object):
    def flipAndInvertImage(self, A):
        """
        :type A: List[List[int]]
        :rtype: List[List[int]]
        """
        res = []
        for ls in A:
            rls = list(reversed(ls))
            for j in range(len(rls)):
                if rls[j] == 0:
                    rls[j] = 1
                else:
                    rls[j] = 0
            res.append(rls)
        return res
