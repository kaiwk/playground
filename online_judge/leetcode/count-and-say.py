class Solution(object):
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        res = '1'
        for _ in range(1, n):
            j = 0
            new_res = ''
            while j < len(res):
                count = 0
                val = int(res[j])
                while j < len(res) and val == int(res[j]):
                    count += 1
                    j += 1
                new_res += (str(count) + str(val))
            res = new_res
        return res
