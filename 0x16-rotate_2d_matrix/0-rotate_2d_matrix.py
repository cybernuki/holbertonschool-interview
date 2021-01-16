#!/usr/bin/python3
'''
Rotates 2D matrix in-place (clockwise)
'''


def rotate_2d_matrix(matrix):
	'''rotates matrix clockwise'''
	n = len(matrix)
	for row in range(0, int(n / 2)):
		for col in range(row, n - row - 1):
			temp = matrix[row][col]
			matrix[row][col] = matrix[n - 1 - col][row]
			matrix[n - 1 - col][row] = matrix[n - 1 - row][n - 1 - col]
			matrix[n - 1 - row][n - 1 - col] = matrix[col][n - 1 - row]
			matrix[col][n - 1 - row] = temp
