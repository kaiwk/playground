class Solution(object):
    def reverseString(self, s):
        """
        :type s: str
        :rtype: str
        """
        n = len(s)
        s_arr = list(s)
        k = n // 2

        for i in range(k):
            s_arr[i], s_arr[n-i-1] = s_arr[n-i-1], s_arr[i]

        return ''.join(s_arr)
