class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if not prices:
            return 0

        n = len(prices)
        res = 0
        min_price = prices[0]
        for i in range(n):
            min_price = min(min_price, prices[i])
            res = max(res, prices[i] - min_price)
        return res
