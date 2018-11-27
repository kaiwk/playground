"""
Definition of ListNode
class ListNode(object):

    def __init__(self, val, next=None):
        self.val = val
        self.next = next
"""


class Solution:

    def insertionSortList(self, head):

        dummy = ListNode(float('-inf'))
        dummy.next = head
        pre = head
        pcur = head.next

        while pcur:

            if pre.val > pcur.val:
                walk = dummy
                while walk.next and walk.next != pcur:
                    if pcur.val < walk.next.val:
                        pre.next = pcur.next
                        pcur.next = walk.next
                        walk.next = pcur
                        break
                    walk = walk.next
                pcur = pre.next
            else:
                pre = pre.next
                pcur = pcur.next

        return dummy.next
