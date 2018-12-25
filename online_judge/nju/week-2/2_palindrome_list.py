class Node:
    def __init__(self, nxt, val):
        self.nxt = nxt
        self.val = val


def create_list(arr):
    dummy = Node(None, -1)
    p = dummy
    for i in arr:
        p.nxt = Node(None, i)
        p = p.nxt
    return dummy


def print_list(head):
    p = head.nxt
    print(p.val, end='')
    while p.nxt != None:
        p = p.nxt
        print('', p.val, end='')
    print()


def find_k(head, k):
    p = head.nxt
    for _ in range(k):
        p = p.nxt
    return p


def reverse_list(dummy):
    if dummy.nxt is None:
        return dummy.nxt

    pre = dummy.nxt
    cur = pre.nxt
    while cur != None:
        pre.nxt = cur.nxt
        cur.nxt = dummy.nxt
        dummy.nxt = cur
        cur = pre.nxt
    return dummy


def is_palindrome(arr, n):
    dummy = create_list(arr)

    mid = find_k(dummy, (n-1) // 2)
    mid = reverse_list(mid)

    if mid:
        p1 = dummy.nxt
        p2 = mid.nxt
        while p1 != mid.nxt and p2 != None:
            if p1.val == p2.val:
                p1 = p1.nxt
                p2 = p2.nxt
            else:
                return False
        return True
    else:
        return True


while True:
    try:
        # f = open('input.txt')
        # arr = [i for i in f.readline().strip().split(' ')]
        arr = [i for i in input().strip().split()]
        n = int(arr[0])
        arr = arr[1:]
        if is_palindrome(arr, n):
            print('true')
        else:
            print('false')
    except EOFError:
        break
