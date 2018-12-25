class Solution(object):
    def multiply(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        i, j = 0, 0
        n1 = len(num1)
        n2 = len(num2)
        n = n1 + n2
        arr = [0] * n
        for i in range(n1-1, -1, -1):
            for j in range(n2-1, -1, -1):
                mul = (ord(num1[i]) - ord('0')) * (ord(num2[j]) - ord('0'))
                arr[i+j+1] += mul % 10
                arr[i+j] += mul // 10

        carry = 0
        for i in range(n-1, -1, -1):
            arr[i] += carry
            if arr[i] > 9:
                carry = arr[i] // 10
                arr[i] = arr[i] % 10
            else:
                carry = 0

        res = ''
        start_zero = True
        for i in range(n):
            if arr[i] != 0:
                start_zero = False
            if start_zero:
                continue
            else:
                res += str(arr[i])

        if start_zero:
            res = '0'

        return res
