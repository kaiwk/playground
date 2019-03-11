from typing import List

class Solution:
    def calPoints(self, ops: List[str]) -> int:
        points = []


        for s in ops:
            if s == '+':
                points.append(points[-1] + points[-2])
            elif s == 'D':
                points.append(points[-1]*2)
            elif s == 'C':
                points.pop()
            else:               # number
                points.append(int(s))
        return sum(points)
