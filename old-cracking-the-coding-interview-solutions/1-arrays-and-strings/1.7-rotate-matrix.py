def rotate(mat):
    l = 0
    r = len(mat) - 1
    while l < r:
        for i in range(r-l):
            top = l
            bottom = r
            
            tmp = mat[top][l + i]
            
            mat[top][l + i] = mat[bottom - i][l]
            
            mat[bottom - i][l] = mat[bottom][r - i]
            
            mat[bottom][r - i] = mat[top + i][r]
            
            mat[top + i][r] = tmp
        l += 1
        r -= 1

def printNxNMatrix(mat, n):
    for i in range(n):
        for j in range(n):
            print(mat[i][j], end="")
        print("")
    print("")

matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
matrixRes = [[7, 4, 1], [8, 5, 2], [9, 6, 3]]

printNxNMatrix(matrix, 3)

rotate(matrix)

printNxNMatrix(matrix, 3)

"""
Notes:
I was clueless with this problem so I searched the answer online
"""