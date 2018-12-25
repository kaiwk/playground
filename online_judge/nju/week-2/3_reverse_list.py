class Node:
    def __init__(self, nxt, val):
        self.nxt = None
        self.val = val


def print_node_list(head):
    p = head.nxt
    print(p.val, end='')
    while p.nxt != None:
        p = p.nxt
        print('', p.val, end='')
    print()


def reverse_k(start, k):
    if k == 0:
        return

    p = start.nxt
    p1 = p
    p2 = p1.nxt
    for _ in range(k):
        start.nxt = p2
        p1.nxt = p2.nxt
        p2.nxt = p
        p = p2
        p2 = p1.nxt

    return p1


while True:
    try:
        # f = open('input.txt')
        # inp = [i for i in f.readline().strip().split(' ')]

        inp = [i for i in input().strip().split(' ')]
        n = int(inp[0])
        k = int(inp[-1])
        arr = inp[1:n+1]

        # head -> 0 -> 1 -> 2
        head = Node(None, -1)
        p = head
        for i in range(n):
            p.nxt = Node(None, arr[i])
            p = p.nxt

        p = head
        for i in range(n//k):
            p = reverse_k(p, k-1)

        print_node_list(head)

    except EOFError:
        break
