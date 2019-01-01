class Solution(object):
    # dfs
    def findCircleNum(self, M):
        """
        :type M: List[List[int]]
        :rtype: int
        """
        n = len(M)
        visited = [False] * n
        cnt = 0
        for i in range(n):
            if not visited[i]:
                visited[i] = True
                self.dfs(M, n, i, visited)
                cnt += 1
        return cnt


    def dfs(self, M, n, p, visited):
        for i in range(n):
            if M[p][i] == 1 and not visited[i]:
                visited[i] = True
                self.dfs(M, n, i, visited)


# Solution 2
class Solution2:
    def findCircleNum(self, M):
        n = len(M)
        uf = UnionFind(n)
        for i in range(n):
            for j in range(n):
                if M[i][j] == 1:
                    uf.union(i, j)
        return uf.union_num


class UnionFind:
    def __init__(self, n):
        self.parent = [0] * n
        self.rank = [0] * n

        for i in range(n):
            self.parent[i] = i

        self.union_num = n

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

        if self.rank[rootX] > self.rank[rootY]:
            self.parent[rootY] = rootX
            self.rank[rootX] += self.rank[rootY]
        else:
            self.parent[rootX] = rootY
            self.rank[rootY] += self.rank[rootX]

        self.union_num -= 1
        return True
