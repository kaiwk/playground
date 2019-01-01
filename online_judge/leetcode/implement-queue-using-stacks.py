class MyQueue:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.s1 = []
        self.s2 = []
        self.size = 0

    def push(self, x):
        """
        Push element x to the back of queue.
        :type x: int
        :rtype: void
        """
        self.s1.append(x)
        self.size += 1

    def pop(self):
        """
        Removes the element from in front of queue and returns that element.
        :rtype: int
        """
        if self.empty():
            return -1

        if not self.s2:
            self.swap()

        self.size -= 1
        return self.s2.pop()

    def peek(self):
        """
        Get the front element.
        :rtype: int
        """
        if self.empty():
            return -1

        if not self.s2:
            self.swap()

        return self.s2[-1]

    def empty(self):
        """
        Returns whether the queue is empty.
        :rtype: bool
        """
        return self.size == 0

    def swap(self):
        k = len(self.s1)
        for _ in range(k):
            self.s2.append(self.s1.pop())



# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()
