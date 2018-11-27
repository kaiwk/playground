class Solution:
    # @param {int} numCourses a total of n courses
    # @param {int[][]} prerequisites a list of prerequisite pairs
    # @return {boolean} true if can finish all courses or false
    def canFinish(self, numCourses, prerequisites):

        # it's wrong, because there will be a repeate connections, and the indegree add repeatedly
        # graph = {i: set() for i in range(numCourses)}
        graph = {i: [] for i in range(numCourses)}
        indegree = [0] * numCourses

        # pre -> c
        for c, pre in prerequisites:
            graph[pre].append(c)
            indegree[c] += 1

        queue = []
        for i, v in enumerate(indegree):
            if v == 0:
                queue.append(i)

        while queue:
            cur = queue.pop(0)
            for c in graph[cur]:
                indegree[c] -= 1
                if indegree[c] == 0:
                    queue.append(c)
            del graph[cur]

        return sum(indegree) == 0 and len(graph) == 0
