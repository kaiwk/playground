class Solution(object):
    def findRedundantConnection(self, edges):
        """
        :type edges: List[List[int]]
        :rtype: List[int]
        """
        n = len(edges)
        uf = UnionFind(n)
        for u, v in edges:
            if not uf.union(u, v):
                return [u, v]

class UnionFind:
    def __init__(self, n):
        self.parent = [-1] * (n+1)
        self.rank = [1] * (n+1)

        for i in range(1, n+1):
            self.parent[i] = i

    def find(self, x):
        if self.parent[x] == x:
            return x
        self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, x, y):
        rootX = self.find(x)
        rootY = self.find(y)

        if rootX == rootY:
            return False
        if self.rank[rootX] < self.rank[rootY]:
            self.parent[rootX] = rootY
            self.rank[rootY] += self.rank[rootX]
        else:
            self.parent[rootY] = rootX
            self.rank[rootX] += self.rank[rootY]

        return True
