# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):

    def addLists(self, l1, l2):
        p1 = l1
        p2 = l2

        p = ListNode(0)
        ret = p
        carry = False
        while p1 or p2:
            temp = 0
            if p1:
                temp += p1.val
                p1 = p1.next
            if p2:
                temp += p2.val
                p2 = p2.next
            if carry:
                temp += 1
            carry = temp > 9

            temp_node = ListNode(temp % 10)
            p.next = temp_node
            p = p.next

        if carry:
            p.next = ListNode(1)

        return ret.next
