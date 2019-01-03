# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        dummy = ListNode(-1)
        dummy.next = head
        pj = dummy
        pi = dummy
        j = 0

        # n = 2
        # j = 0, pj -> dummy, pi -> dummy
        # j = 1, pj -> 1, pi -> dummy
        # j = 2, pj -> 2, pi -> dummy
        # j = 3, pj -> 3, pi -> dummy
        # j = 4, pj -> 4, pi -> 1          4 > n + 1 (3)
        # j = 5, pj -> 5, pi -> 2
        # j = 6, pj -> none, pi -> 3
        while pj != None:
            j += 1
            if j > n+1:
                pi = pi.next
            pj = pj.next
        pi.next = pi.next.next
        return dummy.next
