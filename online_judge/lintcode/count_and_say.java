public class Solution {
    /**
     * @param n the nth
     * @return the nth sequence
     */
    public String countAndSay(int n) {
        if (n == 1) {
            return "1";
        }
        String str = countAndSay(n-1) + "*";
        char[] carr = str.toCharArray();

        int count = 1;
        String s = "";
        for (int i = 0; i < carr.length-1; ++i) {
            if (carr[i] == carr[i+1]) {
                ++count;
            } else {
                s = s + count + carr[i];
                count = 1;
            }
        }
        return s;
    }
}
