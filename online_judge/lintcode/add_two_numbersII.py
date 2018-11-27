# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # @param l1: the first list
    # @param l2: the second list
    # @return: the sum list of l1 and l2
    def addLists2(self, l1, l2):
        num1 = 0
        num2 = 0
        p1 = l1
        p2 = l2
        while p1:
            num1 = num1 * 10 + p1.val
            p1 = p1.next
        while p2:
            num2 = num2 * 10 + p2.val
            p2 = p2.next

        res = num1 + num2

        phead = ListNode(0)
        p_temp = None

        while res != 0:
            temp = ListNode(res % 10)
            phead.next = temp
            temp.next = p_temp
            p_temp = temp
            res = res // 10

        ret = phead.next

        if not ret:
            ret = ListNode(0)

        return ret
