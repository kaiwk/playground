class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        n = len(digits)-1
        carry = 0

        digits[n] = digits[n] + 1
        if digits[n] > 9:
            digits[n] = digits[n] % 10
            carry = 1
        else:
            return digits

        n -= 1
        while carry != 0 and n >= 0:
            digits[n] = digits[n] + carry
            if digits[n] > 9:
                digits[n] = digits[n] % 10
                carry = 1
            else:
                carry = 0
            n -= 1

        if carry == 1:
            digits = [1] + digits

        return digits
