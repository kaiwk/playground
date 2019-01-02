class Solution(object):
    def restoreIpAddresses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        n = len(s)
        if n > 12:
            return []

        res = []
        for i in range(1, n):
            for j in range(i+1, n):
                for k in range(j+1, n):
                    ip_str = s[:i] + '.' + s[i:j] + '.' + s[j:k] + '.' + s[k:]
                    if self.is_valid_ip(ip_str):
                        res.append(ip_str)
        return res

    def is_valid_ip(self, ip_str):
        ip_nums = ip_str.split('.')

        for i in ip_nums:
            if i.startswith('0') and len(i) != 1:
                return False

            if int(i) > 255:
                return False

        return True
