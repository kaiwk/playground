class Solution {
public:
    int getSum(int a, int b) {
        int sum = 0, carry = 0;
        for (unsigned mask = 1; mask != 0; mask <<= 1) {
            sum |= (a^b^carry)&mask;
            carry = ((a&b) | ((a^b)&carry)) << 1;
        }
        return sum;
    }
};
