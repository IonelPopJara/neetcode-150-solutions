import copy

def zero(matrix):
    matrixCopy = copy.deepcopy(matrix)
    for row in range(len(matrix)):
        for col in range(len(matrix[row])):
        # print(f'matrix[{row}][{col}] = {matrix[row][col]}')
            if matrixCopy[row][col] == 0:
                # Iterate through all the columns in the same row
                for tmpCol in range(len(matrix[row])):
                    matrix[row][tmpCol] = 0
                
                # Iterate through all the rows in the same column
                for tmpRow in range(len(matrix)):
                    matrix[tmpRow][col] = 0
                    
    # matrix = matrixCopy

def printMatrix(matrix):
    for row in matrix:
        for item in row:
            print(item, end=" ")
        print(" ")
    print("")

matrix = [[1, 1, 1], [1, 0, 1], [1, 1, 1]]
# matrix = [[1, 1, 1, 1], [1, 1, 0, 1], [1, 1, 1, 1]]

printMatrix(matrix)

zero(matrix)

printMatrix(matrix)