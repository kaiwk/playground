class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:

        # row
        for i in range(9):
            flag = [0] * 10
            for j in range(9):
                if board[i][j] != ".":
                    flag[int(board[i][j])] += 1
            if max(flag) > 1:
                return False

        # column
        for i in range(9):
            flag = [0] * 10
            for j in range(9):
                if board[j][i] != ".":
                    flag[int(board[j][i])] += 1
            if max(flag) > 1:
                return False

        top, left = 0, 0
        while top < 9:
            while left < 9:
                flag = [0] * 10
                for i in range(top, top + 3):
                    for j in range(left, left + 3):
                        if board[i][j] != ".":
                            flag[int(board[i][j])] += 1
                if max(flag) > 1:
                    return False
                left += 3
            top += 3
            left = 0

        return True
