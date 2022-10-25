#pragma once
#include <iostream>

void MatrixTranspose(float _Matrix[4][4]);
int MatrixDeterminant(float _Matrix[4][4]);
void MatrixScalar(float _Matrix[4][4], float scalar);
void MatrixInverse(float _Matrix[4][4]);
void MatrixAdd(float _MatrixOne[4][4], float _MatrixTwo[4][4]);
void MatrixSubtract(float _MatrixOne[4][4], float _MatrixTwo[4][4]);



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

	

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			float result = 0;
			for (int k = 0; k < 4; ++k)
			{
				result += matrix[i][k] * matrix2[k][j];
				tempMatrix[i][j] = result;
			}
			std::cout << tempMatrix[i][j] << " ";
		}
		std::cout << std::endl;
	}

	return 0;
}

void MatrixAdd(float _MatrixOne[4][4], float _MatrixTwo[4][4])
{
	float tempMatrix[4][4];

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			tempMatrix[i][j] = _MatrixOne[i][j] + _MatrixTwo[i][j];
			
			std::cout << tempMatrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void MatrixSubtract(float _MatrixOne[4][4], float _MatrixTwo[4][4])
{
	float tempMatrix[4][4];

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			tempMatrix[i][j] = _MatrixOne[i][j] - _MatrixTwo[i][j];

			std::cout << tempMatrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}


void MatrixInverse(float _Matrix[4][4])
{
	float tempMatrix[4][4];

	tempMatrix[0][0] = ((_Matrix[1][1] * _Matrix[2][2] * _Matrix[3][3]) + (_Matrix[1][2] * _Matrix[2][3] * _Matrix[3][1]) + (_Matrix[1][3] * _Matrix[2][1] * _Matrix[3][2])
		- (_Matrix[1][3] * _Matrix[2][2] * _Matrix[3][1]) - (_Matrix[1][2] * _Matrix[2][1] * _Matrix[3][3]) - (_Matrix[1][1] * _Matrix[2][3] * _Matrix[3][2]));

	tempMatrix[0][1] = -(_Matrix[0][1] * _Matrix[2][2] * _Matrix[3][3]) - (_Matrix[0][2] * _Matrix[2][3] * _Matrix[3][1]) - (_Matrix[0][3] * _Matrix[2][1] * _Matrix[3][2])
		+ (_Matrix[0][3] * _Matrix[2][2] * _Matrix[3][1]) + (_Matrix[0][2] * _Matrix[2][1] * _Matrix[3][3]) + (_Matrix[0][1] * _Matrix[2][3] * _Matrix[3][2]);

	tempMatrix[0][2] = (_Matrix[0][1] * _Matrix[1][2] * _Matrix[3][3]) + (_Matrix[0][2] * _Matrix[1][3] * _Matrix[3][1]) + (_Matrix[0][3] * _Matrix[1][1] * _Matrix[3][2])
		- (_Matrix[0][3] * _Matrix[1][2] * _Matrix[3][1]) - (_Matrix[0][2] * _Matrix[1][1] * _Matrix[3][3]) - (_Matrix[0][1] * _Matrix[1][3] * _Matrix[3][2]);

	tempMatrix[0][3] = -(_Matrix[0][1] * _Matrix[1][2] * _Matrix[2][3]) - (_Matrix[0][2] * _Matrix[1][3] * _Matrix[2][1]) - (_Matrix[0][3] * _Matrix[1][1] * _Matrix[2][2])
		+ (_Matrix[0][3] * _Matrix[1][2] * _Matrix[2][1]) + (_Matrix[0][2] * _Matrix[1][1] * _Matrix[2][3]) + (_Matrix[0][1] * _Matrix[1][3] * _Matrix[2][2]);



	tempMatrix[1][0] = -(_Matrix[1][0] * _Matrix[2][2] * _Matrix[3][3]) - (_Matrix[1][2] * _Matrix[2][3] * _Matrix[3][0]) - (_Matrix[1][3] * _Matrix[2][0] * _Matrix[3][2])
		+ (_Matrix[1][3] * _Matrix[2][2] * _Matrix[3][0]) + (_Matrix[1][2] * _Matrix[2][0] * _Matrix[3][3]) + (_Matrix[1][0] * _Matrix[2][3] * _Matrix[3][2]);

	tempMatrix[1][1] = (_Matrix[0][0] * _Matrix[2][2] * _Matrix[3][3]) + (_Matrix[0][2] * _Matrix[2][3] * _Matrix[3][0]) + (_Matrix[0][3] * _Matrix[2][0] * _Matrix[3][2])
		- (_Matrix[0][3] * _Matrix[2][2] * _Matrix[3][0]) - (_Matrix[0][2] * _Matrix[2][0] * _Matrix[3][3]) - (_Matrix[0][0] * _Matrix[2][3] * _Matrix[3][2]);

	tempMatrix[1][2] = -(_Matrix[0][0] * _Matrix[1][2] * _Matrix[3][3]) - (_Matrix[0][2] * _Matrix[1][3] * _Matrix[3][0]) - (_Matrix[0][3] * _Matrix[1][0] * _Matrix[3][2])
		+ (_Matrix[0][3] * _Matrix[1][2] * _Matrix[3][1]) + (_Matrix[0][2] * _Matrix[1][1] * _Matrix[3][3]) + (_Matrix[0][1] * _Matrix[1][3] * _Matrix[3][2]);

	tempMatrix[1][3] = (_Matrix[0][0] * _Matrix[1][2] * _Matrix[2][3]) + (_Matrix[0][2] * _Matrix[1][3] * _Matrix[2][0]) + (_Matrix[0][3] * _Matrix[1][0] * _Matrix[2][2])
		- (_Matrix[0][3] * _Matrix[1][2] * _Matrix[2][0]) - (_Matrix[0][2] * _Matrix[1][0] * _Matrix[2][3]) - (_Matrix[0][0] * _Matrix[1][3] * _Matrix[2][2]);



	tempMatrix[2][0] = (_Matrix[1][0] * _Matrix[2][1] * _Matrix[3][3]) + (_Matrix[1][1] * _Matrix[2][3] * _Matrix[3][0]) + (_Matrix[1][3] * _Matrix[2][0] * _Matrix[3][1])
		- (_Matrix[1][3] * _Matrix[2][1] * _Matrix[3][0]) - (_Matrix[1][1] * _Matrix[2][0] * _Matrix[3][3]) - (_Matrix[1][0] * _Matrix[2][3] * _Matrix[3][1]);

	tempMatrix[2][1] = -(_Matrix[0][0] * _Matrix[2][1] * _Matrix[3][3]) - (_Matrix[0][1] * _Matrix[2][3] * _Matrix[3][0]) - (_Matrix[0][3] * _Matrix[2][0] * _Matrix[3][1])
		+ (_Matrix[0][3] * _Matrix[2][1] * _Matrix[3][0]) + (_Matrix[0][1] * _Matrix[2][0] * _Matrix[3][3]) + (_Matrix[0][0] * _Matrix[2][3] * _Matrix[3][1]);

	tempMatrix[2][2] = (_Matrix[0][0] * _Matrix[1][1] * _Matrix[3][3]) + (_Matrix[0][1] * _Matrix[1][3] * _Matrix[3][0]) + (_Matrix[0][3] * _Matrix[1][0] * _Matrix[3][1])
		- (_Matrix[0][3] * _Matrix[1][1] * _Matrix[3][0]) - (_Matrix[0][1] * _Matrix[1][0] * _Matrix[3][3]) - (_Matrix[0][0] * _Matrix[1][3] * _Matrix[3][1]);

	tempMatrix[2][3] = -(_Matrix[0][0] * _Matrix[1][1] * _Matrix[2][3]) - (_Matrix[0][1] * _Matrix[1][3] * _Matrix[2][0]) - (_Matrix[0][3] * _Matrix[1][0] * _Matrix[2][1])
		+ (_Matrix[0][3] * _Matrix[1][1] * _Matrix[2][0]) + (_Matrix[0][1] * _Matrix[1][0] * _Matrix[2][3]) + (_Matrix[0][0] * _Matrix[1][3] * _Matrix[2][1]);



	tempMatrix[3][0] = -(_Matrix[1][0] * _Matrix[2][1] * _Matrix[3][2]) - (_Matrix[1][1] * _Matrix[2][2] * _Matrix[3][0]) - (_Matrix[1][2] * _Matrix[2][0] * _Matrix[3][1])
		+ (_Matrix[1][2] * _Matrix[2][1] * _Matrix[3][0]) + (_Matrix[1][1] * _Matrix[2][0] * _Matrix[3][2]) + (_Matrix[1][0] * _Matrix[2][2] * _Matrix[3][1]);

	tempMatrix[3][1] = (_Matrix[0][0] * _Matrix[2][1] * _Matrix[3][2]) + (_Matrix[0][1] * _Matrix[2][2] * _Matrix[3][0]) + (_Matrix[0][2] * _Matrix[2][0] * _Matrix[3][1])
		- (_Matrix[0][2] * _Matrix[2][1] * _Matrix[3][0]) - (_Matrix[0][1] * _Matrix[2][0] * _Matrix[3][2]) - (_Matrix[0][0] * _Matrix[2][2] * _Matrix[3][1]);

	tempMatrix[3][2] = -(_Matrix[0][0] * _Matrix[1][1] * _Matrix[3][2]) - (_Matrix[0][1] * _Matrix[1][2] * _Matrix[3][0]) - (_Matrix[0][2] * _Matrix[1][0] * _Matrix[3][1])
		+ (_Matrix[0][2] * _Matrix[1][1] * _Matrix[3][0]) + (_Matrix[0][1] * _Matrix[1][0] * _Matrix[3][2]) + (_Matrix[0][0] * _Matrix[1][2] * _Matrix[3][1]);

	tempMatrix[3][3] = (_Matrix[0][0] * _Matrix[1][1] * _Matrix[2][2]) + (_Matrix[0][1] * _Matrix[1][2] * _Matrix[2][0]) + (_Matrix[0][2] * _Matrix[1][0] * _Matrix[2][1])
		- (_Matrix[0][2] * _Matrix[1][1] * _Matrix[2][0]) - (_Matrix[0][1] * _Matrix[1][0] * _Matrix[2][2]) - (_Matrix[0][0] * _Matrix[1][2] * _Matrix[2][1]);


	float det = MatrixDeterminant(_Matrix);
	det = 1 / det;

	MatrixScalar(tempMatrix, det);
}


void MatrixScalar(float _Matrix[4][4], float _Scalar)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			float result;
			result = _Matrix[i][j] * _Scalar;
			_Matrix[i][j] = result;
			std::cout << _Matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
};

void MatrixTranspose(float _Matrix[4][4])
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

int MatrixDeterminant(float _Matrix[4][4])
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

/*

	tempMatrix[0][0] = (matrix[1][1] * matrix[2][2] * matrix[3][3]) + (matrix[1][2] * matrix[2][3] * matrix[3][1]) + (matrix[1][3] * matrix[2][1] * matrix[3][2])
						- (matrix[1][3] * matrix[2][2] * matrix[3][1]) - (matrix[1][2] * matrix[2][1] * matrix[3][3]) - (matrix[1][1] * matrix[2][3] * matrix[3][2]);

	tempMatrix[0][1] = - (matrix[0][1] * matrix[2][2] * matrix[3][3]) - (matrix[0][2] * matrix[2][3] * matrix[3][1]) - (matrix[0][3] * matrix[2][1] * matrix[3][2])
		 + (matrix[0][3] * matrix[2][2] * matrix[3][1]) + (matrix[0][2] * matrix[2][1] * matrix[3][3]) + (matrix[0][1] * matrix[2][3] * matrix[3][2]);

	tempMatrix[0][2] = (matrix[0][1] * matrix[1][2] * matrix[3][3]) + (matrix[0][2] * matrix[1][3] * matrix[3][1]) + (matrix[0][3] * matrix[1][1] * matrix[3][2])
		- (matrix[0][3] * matrix[1][2] * matrix[3][1]) - (matrix[0][2] * matrix[1][1] * matrix[3][3]) - (matrix[0][1] * matrix[1][3] * matrix[3][2]);

	tempMatrix[0][3] = -(matrix[0][1] * matrix[1][2] * matrix[2][3]) - (matrix[0][2] * matrix[1][3] * matrix[2][1]) - (matrix[0][3] * matrix[1][1] * matrix[2][2])
		+ (matrix[0][3] * matrix[1][2] * matrix[2][1]) + (matrix[0][2] * matrix[1][1] * matrix[2][3]) + (matrix[0][1] * matrix[1][3] * matrix[2][2]);



	tempMatrix[1][0] = - (matrix[1][0] * matrix[2][2] * matrix[3][3]) - (matrix[1][2] * matrix[2][3] * matrix[3][0]) - (matrix[1][3] * matrix[2][0] * matrix[3][2])
		+ (matrix[1][3] * matrix[2][2] * matrix[3][0]) + (matrix[1][2] * matrix[2][0] * matrix[3][3]) + (matrix[1][0] * matrix[2][3] * matrix[3][2]);

	tempMatrix[1][1] = (matrix[0][0] * matrix[2][2] * matrix[3][3]) + (matrix[0][2] * matrix[2][3] * matrix[3][0]) + (matrix[0][3] * matrix[2][0] * matrix[3][2])
		- (matrix[0][3] * matrix[2][2] * matrix[3][0]) - (matrix[0][2] * matrix[2][0] * matrix[3][3]) - (matrix[0][0] * matrix[2][3] * matrix[3][2]);

	tempMatrix[1][2] = -(matrix[0][0] * matrix[1][2] * matrix[3][3]) - (matrix[0][2] * matrix[1][3] * matrix[3][0]) - (matrix[0][3] * matrix[1][0] * matrix[3][2])
		+ (matrix[0][3] * matrix[1][2] * matrix[3][1]) + (matrix[0][2] * matrix[1][1] * matrix[3][3]) + (matrix[0][1] * matrix[1][3] * matrix[3][2]);

	tempMatrix[1][3] = (matrix[0][0] * matrix[1][2] * matrix[2][3]) + (matrix[0][2] * matrix[1][3] * matrix[2][0]) + (matrix[0][3] * matrix[1][0] * matrix[2][2])
		- (matrix[0][3] * matrix[1][2] * matrix[2][0]) - (matrix[0][2] * matrix[1][0] * matrix[2][3]) - (matrix[0][0] * matrix[1][3] * matrix[2][2]);



	tempMatrix[2][0] = (matrix[1][0] * matrix[2][1] * matrix[3][3]) + (matrix[1][1] * matrix[2][3] * matrix[3][0]) + (matrix[1][3] * matrix[2][0] * matrix[3][1])
		- (matrix[1][3] * matrix[2][1] * matrix[3][0]) - (matrix[1][1] * matrix[2][0] * matrix[3][3]) - (matrix[1][0] * matrix[2][3] * matrix[3][1]);

	tempMatrix[2][1] = -(matrix[0][0] * matrix[2][1] * matrix[3][3]) - (matrix[0][1] * matrix[2][3] * matrix[3][0]) - (matrix[0][3] * matrix[2][0] * matrix[3][1])
		+ (matrix[0][3] * matrix[2][1] * matrix[3][0]) + (matrix[0][1] * matrix[2][0] * matrix[3][3]) + (matrix[0][0] * matrix[2][3] * matrix[3][1]);

	tempMatrix[2][2] = (matrix[0][0] * matrix[1][1] * matrix[3][3]) + (matrix[0][1] * matrix[1][3] * matrix[3][0]) + (matrix[0][3] * matrix[1][0] * matrix[3][1])
		- (matrix[0][3] * matrix[1][1] * matrix[3][0]) - (matrix[0][1] * matrix[1][0] * matrix[3][3]) - (matrix[0][0] * matrix[1][3] * matrix[3][1]);

	tempMatrix[2][3] = -(matrix[0][0] * matrix[1][1] * matrix[2][3]) - (matrix[0][1] * matrix[1][3] * matrix[2][0]) - (matrix[0][3] * matrix[1][0] * matrix[2][1])
		+ (matrix[0][3] * matrix[1][1] * matrix[2][0]) + (matrix[0][1] * matrix[1][0] * matrix[2][3]) + (matrix[0][0] * matrix[1][3] * matrix[2][1]);



	tempMatrix[3][0] = -(matrix[1][0] * matrix[2][1] * matrix[3][2]) - (matrix[1][1] * matrix[2][2] * matrix[3][0]) - (matrix[1][2] * matrix[2][0] * matrix[3][1])
		+ (matrix[1][2] * matrix[2][1] * matrix[3][0]) + (matrix[1][1] * matrix[2][0] * matrix[3][2]) + (matrix[1][0] * matrix[2][2] * matrix[3][1]);

	tempMatrix[3][1] = (matrix[0][0] * matrix[2][1] * matrix[3][2]) + (matrix[0][1] * matrix[2][2] * matrix[3][0]) + (matrix[0][2] * matrix[2][0] * matrix[3][1])
		- (matrix[0][2] * matrix[2][1] * matrix[3][0]) - (matrix[0][1] * matrix[2][0] * matrix[3][2]) - (matrix[0][0] * matrix[2][2] * matrix[3][1]);

	tempMatrix[3][2] = -(matrix[0][0] * matrix[1][1] * matrix[3][2]) - (matrix[0][1] * matrix[1][2] * matrix[3][0]) - (matrix[0][2] * matrix[1][0] * matrix[3][1])
		+ (matrix[0][2] * matrix[1][1] * matrix[3][0]) + (matrix[0][1] * matrix[1][0] * matrix[3][2]) + (matrix[0][0] * matrix[1][2] * matrix[3][1]);

	tempMatrix[3][3] = (matrix[0][0] * matrix[1][1] * matrix[2][2]) + (matrix[0][1] * matrix[1][2] * matrix[2][0]) + (matrix[0][2] * matrix[1][0] * matrix[2][1])
		- (matrix[0][2] * matrix[1][1] * matrix[2][0]) - (matrix[0][1] * matrix[1][0] * matrix[2][2]) - (matrix[0][0] * matrix[1][2] * matrix[2][1]);


*/