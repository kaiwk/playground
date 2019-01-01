class Solution:
    def singleNumber(self, nums):
        n = len(nums)
        ans = 0
        for i in range(32):
            cnt = 0
            for j in range(n):
                if ((nums[j] >> i) & 1) == 1:
                    cnt += 1

            cnt = cnt % 3
            ans |= (cnt << i)

        return self.convert(ans)

    def convert(self, x):
        if x >= 2 ** 31:
            x -= 2 ** 32
        return x
