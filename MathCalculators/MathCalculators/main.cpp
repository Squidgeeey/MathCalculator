#pragma once
#include <iostream>

void MatrixTranspose(int _Matrix[4][4]);
int MatrixDeterminant(int _Matrix[4][4]);



int main()
{
	float tempMatrix[4][4];

	float matrix[4][4] = { 1, 3, 5, 5,
						   7, 2, 6, 6,
						   3, 7, 3, 2,
						   5, 3, 4, 4

	};

	float matrix2[4][4] = {
							2, 3, 2, 5,
							1, 7, 6, 2,
							3, 0, 1, 4,
							5, 0, 3, 2
	};

	tempMatrix[0][0] = (matrix[1][1] * matrix[2][2] * matrix[3][3])
	

	return 0;
}



void MatrixTranspose(int _Matrix[4][4])
{
	float matrixTemp[4][4];

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			matrixTemp[i][j] = _Matrix[j][i];
			std::cout << matrixTemp[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

int MatrixDeterminant(int _Matrix[4][4])
{
	int determinant = 
		_Matrix[0][3] * _Matrix[1][2] * _Matrix[2][1] * _Matrix[3][0] - _Matrix[0][2] * _Matrix[1][3] * _Matrix[2][1] * _Matrix[3][0] -
		_Matrix[0][3] * _Matrix[1][1] * _Matrix[2][2] * _Matrix[3][0] + _Matrix[0][1] * _Matrix[1][3] * _Matrix[2][2] * _Matrix[3][0] +
		_Matrix[0][2] * _Matrix[1][1] * _Matrix[2][3] * _Matrix[3][0] - _Matrix[0][1] * _Matrix[1][2] * _Matrix[2][3] * _Matrix[3][0] -
		_Matrix[0][3] * _Matrix[1][2] * _Matrix[2][0] * _Matrix[3][1] + _Matrix[0][2] * _Matrix[1][3] * _Matrix[2][0] * _Matrix[3][1] +
		_Matrix[0][3] * _Matrix[1][0] * _Matrix[2][2] * _Matrix[3][1] - _Matrix[0][0] * _Matrix[1][3] * _Matrix[2][2] * _Matrix[3][1] -
		_Matrix[0][2] * _Matrix[1][0] * _Matrix[2][3] * _Matrix[3][1] + _Matrix[0][0] * _Matrix[1][2] * _Matrix[2][3] * _Matrix[3][1] +
		_Matrix[0][3] * _Matrix[1][1] * _Matrix[2][0] * _Matrix[3][2] - _Matrix[0][1] * _Matrix[1][3] * _Matrix[2][0] * _Matrix[3][2] -
		_Matrix[0][3] * _Matrix[1][0] * _Matrix[2][1] * _Matrix[3][2] + _Matrix[0][0] * _Matrix[1][3] * _Matrix[2][1] * _Matrix[3][2] +
		_Matrix[0][1] * _Matrix[1][0] * _Matrix[2][3] * _Matrix[3][2] - _Matrix[0][0] * _Matrix[1][1] * _Matrix[2][3] * _Matrix[3][2] -
		_Matrix[0][2] * _Matrix[1][1] * _Matrix[2][0] * _Matrix[3][3] + _Matrix[0][1] * _Matrix[1][2] * _Matrix[2][0] * _Matrix[3][3] +
		_Matrix[0][2] * _Matrix[1][0] * _Matrix[2][1] * _Matrix[3][3] - _Matrix[0][0] * _Matrix[1][2] * _Matrix[2][1] * _Matrix[3][3] -
		_Matrix[0][1] * _Matrix[1][0] * _Matrix[2][2] * _Matrix[3][3] + _Matrix[0][0] * _Matrix[1][1] * _Matrix[2][2] * _Matrix[3][3];

	return determinant;
}