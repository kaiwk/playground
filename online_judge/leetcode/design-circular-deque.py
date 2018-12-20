class MyCircularDeque(object):

    def __init__(self, k):
        """
        Initialize your data structure here. Set the size of the deque to be k.
        :type k: int
        """
        self.capacity = k
        self.size = 0
        self.head = None
        self.rear = None


    def insertFront(self, value):
        """
        Adds an item at the front of Deque. Return true if the operation is successful.
        :type value: int
        :rtype: bool
        """
        if self.isFull():
            return False

        if self.isEmpty():
            self.head = Node(None, self.head, value)
            self.rear = self.head
        else:
            node = Node(None, self.head, value)
            self.head.pre = node
            self.head = node

        self.size += 1
        return True


    def insertLast(self, value):
        """
        Adds an item at the rear of Deque. Return true if the operation is successful.
        :type value: int
        :rtype: bool
        """
        if self.isFull():
            return False

        if self.isEmpty():
            self.head = Node(self.head, None, value)
            self.rear = self.head
        else:
            node = Node(self.rear, None, value)
            self.rear.nxt = node
            self.rear = node

        self.size += 1
        return True


    def deleteFront(self):
        """
        Deletes an item from the front of Deque. Return true if the operation is successful.
        :rtype: bool
        """
        if self.isEmpty():
            return False

        self.head = self.head.nxt
        if self.head:
            self.head.pre = None
        self.size -= 1
        return True


    def deleteLast(self):
        """
        Deletes an item from the rear of Deque. Return true if the operation is successful.
        :rtype: bool
        """
        if self.isEmpty():
            return False

        self.rear = self.rear.pre
        if self.rear:
            self.rear.nxt = None
        self.size -= 1
        return True


    def getFront(self):
        """
        Get the front item from the deque.
        :rtype: int
        """
        if self.isEmpty():
            return -1

        return self.head.val


    def getRear(self):
        """
        Get the last item from the deque.
        :rtype: int
        """
        if self.isEmpty():
            return -1

        return self.rear.val


    def isEmpty(self):
        """
        Checks whether the circular deque is empty or not.
        :rtype: bool
        """
        return self.size == 0


    def isFull(self):
        """
        Checks whether the circular deque is full or not.
        :rtype: bool
        """
        return self.size == self.capacity


class Node:
    def __init__(self, pre, nxt, val=-1):
        self.pre = pre
        self.nxt = nxt
        self.val = val

# Your MyCircularDeque object will be instantiated and called as such:
# obj = MyCircularDeque(k)
# param_1 = obj.insertFront(value)
# param_2 = obj.insertLast(value)
# param_3 = obj.deleteFront()
# param_4 = obj.deleteLast()
# param_5 = obj.getFront()
# param_6 = obj.getRear()
# param_7 = obj.isEmpty()
# param_8 = obj.isFull()
