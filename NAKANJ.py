import sys
from collections import deque
for _ in xrange(int(sys.stdin.readline().strip())):
    chess_board = [[0]*8 for i in xrange(8)]
    color = [[1]*8 for i in xrange(8)]
    start, end = sys.stdin.readline().strip().split()
    row, column, end_row, end_column = 8-int(start[1]), ord(start[0])-97,8-int(end[1]), ord(end[0])-97,
    Q = deque()
    Q.appendleft((row, column))
    length = 1
    while length :
        row, column = Q.pop()
        length -= 1
        for i in xrange(-2, 3, 4):
             if row + i < 8 and row + i >=0:
                 for j in xrange(-1,2,2):
                     if column + j < 8 and column + j >= 0:
                         if color[row+i][column+j]:
                            chess_board[row+i][column+j] = chess_board[row][column] + 1
                            color[row+i][column+j] = 0
                            Q.appendleft((row+i, column+j))
                            length += 1
        for j in xrange(-2, 3, 4):
             if column + j < 8 and column + j >=0:
                 for i in xrange(-1,2,2):
                     if row + i < 8 and row + i >= 0:
                         if color[row+i][column+j]:
                            chess_board[row+i][column+j] = chess_board[row][column] + 1
                            color[row+i][column+j] = 0
                            Q.appendleft((row+i, column+j))
                            length += 1
        color[row][column] = 0

    sys.stdout.write(str(chess_board[end_row][end_column]) + '\n')
