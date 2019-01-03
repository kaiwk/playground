class LRUCache:

    def __init__(self, capacity):
        """
        :type capacity: int
        """
        self.capacity = capacity
        self.size = 0
        self.cache = dict()
        self.linked_list = LinkedList()

    def get(self, key):
        """
        :type key: int
        :rtype: int
        """
        node = self.cache.get(key)
        if node:
            new_node = Node(None, None, key, node.val)
            self.linked_list.add_first(new_node)
            self.cache[key] = new_node # update the cache node
            self.linked_list.delete(node)
            return self.linked_list.first().val
        return -1

    def put(self, key, value):
        """
        :type key: int
        :type value: int
        :rtype: void
        """
        new_node = Node(None, None, key, value)
        node = self.cache.get(key)
        if node:
            self.linked_list.add_first(new_node)
            self.linked_list.delete(node)
        else:
            self.linked_list.add_first(new_node)
            self.size += 1

        self.cache[key] = new_node # update the cache node

        if self.size > self.capacity:
            node = self.linked_list.last()
            del self.cache[node.key]
            self.linked_list.delete_last()
            self.size -= 1

    def __repr__(self):
        res = ''
        for k, v in self.cache.items():
            res += '{{k:{},v:{}}}'.format(k, v.val)
        return '<LRU cache: ' + res + '>'


class LinkedList:

    def __init__(self):
        self.head = Node(None, None, -1, -1)
        self.rear = Node(None, None, -1, -1)
        self.head.nxt = self.rear
        self.rear.pre = self.head
        self.size = 0

    def first(self):
        return self.head.nxt

    def last(self):
        return self.rear.pre

    def add_first(self, inserted):
        self.insert(self.head, inserted)

    def delete_last(self):
        self.delete(self.rear.pre)

    def insert(self, node, inserted):
        inserted.pre = node
        inserted.nxt = node.nxt
        node.nxt = inserted
        if inserted.nxt:
            inserted.nxt.pre = inserted
        self.size += 1

    def delete(self, node):
        node.pre.nxt = node.nxt
        node.nxt.pre = node.pre
        del node
        self.size -= 1

    def __repr__(self):
        res = ''
        node = self.head.nxt
        while node != self.rear:
            res += str(node.key)
            if node.nxt != self.rear:
                res += '->'
            node = node.nxt
        return '<LinkedList: ' + res + '>'


class Node:

    def __init__(self, pre, nxt, key, val):
        self.pre = pre
        self.nxt = nxt
        self.key = key
        self.val = val

    def __repr__(self):
        return '<Node: k:{},v:{}>'.format(self.key, self.val)


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
