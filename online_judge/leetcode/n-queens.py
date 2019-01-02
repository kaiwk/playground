class Solution(object):

    def __init__(self):
        self.res = []

    def solveNQueens(self, n):
        """
        :type n: int
        :rtype: List[List[str]]
        """
        board = ['.' * n for _ in range(n)]
        self.dfs(board, n, 0)
        return self.res

    def is_safe(self, board, x, y):
        n = len(board)
        for i in range(1, n):
            if x - i >= 0 and y + i < n:
                if board[x-i][y+i] == 'Q':
                    return False
            if x - i >= 0 and y - i >= 0:
                if board[x-i][y-i] == 'Q':
                    return False
            if x - i >= 0:
                if board[x-i][y] == 'Q':
                    return False
        return True

    def dfs(self, board, n, x):

        if x == n:
            self.res.append(list(board))
            return

        for i in range(n):
            if self.is_safe(board, x, i):
                board[x] = board[x][:i] + 'Q' + board[x][i+1:]
                self.dfs(board, n, x+1)
                board[x] = board[x][:i] + '.' + board[x][i+1:]
