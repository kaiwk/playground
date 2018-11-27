class Solution(object):

    def addBinary(self, a, b):
        n_a = len(a)
        n_b = len(b)

        carry = False
        ret = ''

        while n_a != 0 or n_b != 0:
            temp = 0
            if n_a != 0 and n_b != 0:
                temp = int(a[n_a-1]) + int(b[n_b-1])
                n_a -= 1
                n_b -= 1
            elif n_a == 0:
                temp = int(b[n_b-1])
                n_b -= 1
            elif n_b == 0:
                temp = int(a[n_a-1])
                n_a -= 1

            if carry:
                temp += 1
            carry = temp >= 2
            ret = str(temp % 2) + ret

        if carry:
            ret = '1' + ret
        return ret
