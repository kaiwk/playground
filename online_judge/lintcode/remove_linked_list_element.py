# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):

    def removeElements(self, head, val):

        phead = ListNode(0)
        phead.next = head

        p = phead
        while p.next:
            if p.next.val == val:
                p.next = p.next.next
            else:
                p = p.next
        return phead.next
