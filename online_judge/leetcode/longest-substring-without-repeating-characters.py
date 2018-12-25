class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        n = len(s)
        m = {}
        res = 0
        j = 0
        for i in range(n):
            if s[i] in m:
                j = max(m[s[i]] + 1, j)
            m[s[i]] = i
            res = max(res, i + 1 - j)
        return res
