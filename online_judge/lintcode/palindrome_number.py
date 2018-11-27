class Solution:
    # @param {int} num a positive number
    # @return {boolean} true if it's a palindrome or false
    def palindromeNumber(self, num):
        temp = num
        reverse_num = 0

        while temp != 0:
            reverse_num = reverse_num * 10 + temp % 10
            temp = temp // 10

        return reverse_num == num
