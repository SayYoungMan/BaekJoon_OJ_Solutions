from collections import defaultdict

def printBoard(board):
    for i in range(9):
        for j in range(9):
            print(board[i][j], end=' ')
        print('\n', end='')
    return

def isValid(board):
    counter = set()

    for i in range(9):
        counter.clear()
        for j in range(9):
            num = board[i][j]
            if num == 0: continue
            elif num in counter:
                return False
            else: counter.add(num)

    for j in range(9):
        counter.clear()
        for i in range(9):
            num = board[i][j]
            if num == 0: continue
            elif num in counter: 
                return False
            else: counter.add(num)

    for top in [0, 3, 6]:
        for left in [0, 3, 6]:
            counter.clear()
            for i in range(3):
                for j in range(3):
                    num = board[top+i][left+j]
                    if num == 0: continue
                    elif num in counter: 
                        return False
                    else: counter.add(num)

    return True

def backTrack(board, zeros, zeroLoc):
    if not isValid(board):
        return False

    if zeros == 0:
        printBoard(board)
        return True

    for x, y in zeroLoc:
        for i in range(1, 10):
            tmp = board
            tmpSet = zeroLoc

            tmpSet.discard((x,y))
            tmp[x][y] = i
            
            if (backTrack(tmp, zeros-1, tmpSet)): return True

    return True
    

board = defaultdict(lambda: defaultdict(int))
zeros = 0
zeroLoc = set()

for i in range(9):
    line = list(map(int, input().split()))
    for j, v in enumerate(line):
        board[i][j] = v
        if not v:
            zeros += 1
            zeroLoc.add((i, j))

backTrack(board, zeros, zeroLoc)
