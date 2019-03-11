class Solution:
    def countDigitOne(self, n: int) -> int:

        if n <= 0:
            return 0

        cnt = 0
        num_str = str(n)
        num_len = len(num_str)

        for i in range(num_len):
            d = int(num_str[i])
            if num_str[:i]:
                base = int(num_str[:i]) * 10 ** (num_len - i - 1)
            else:
                base = 0

            if d > 1:
                cnt += base + 10 ** (num_len - i - 1)
            elif d == 1:
                if num_str[i+1:]:
                    extra = int(num_str[i+1:])
                else:
                    extra = 0
                cnt += base + extra + 1
            else:
                cnt += base

        return cnt
