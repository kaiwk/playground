class Solution(object):
    # @param {int} numCourses a total of n courses
    # @param {int[][]} prerequisites a list of prerequisite pairs
    # @return {int[]} the course order
    def findOrder(self, numCourses, prerequisites):

        graph = {i: [] for i in range(numCourses)}
        indegree = [0] * numCourses

        # pre -> c
        for c, pre in prerequisites:
            graph[pre].append(c)
            indegree[c] += 1

        zeros = []
        for i, v in enumerate(indegree):
            if v == 0:
                zeros.append(i)

        ret = []
        while zeros:
            cur = zeros.pop(0)
            ret.append(cur)
            for c in graph[cur]:
                indegree[c] -= 1
                if indegree[c] == 0:
                    zeros.append(c)
            del graph[cur]

        if len(graph) == 0 and sum(indegree) == 0:
            return ret
        else:
            return []
