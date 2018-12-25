import sys

class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        n = len(strs)
        if n == 0:
            return ''

        res = ''
        success = True
        min_len = sys.maxsize

        for s in strs:
            min_len = min(len(s), min_len)

        for i in range(min_len):
            res += strs[0][i]
            for j in range(n):
                if strs[j][i] != res[i]:
                    success = False
                    res = res[:-1]
                    break
            if not success:
                return res
        return res
