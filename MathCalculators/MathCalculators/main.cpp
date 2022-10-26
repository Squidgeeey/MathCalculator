#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

void MatrixTranspose(float _Matrix[4][4]);
int MatrixDeterminant(float _Matrix[4][4]);
void MatrixScalar(float _Matrix[4][4], float scalar);
void MatrixInverse(float _Matrix[4][4]);
void MatrixAdd(float _MatrixOne[4][4], float _MatrixTwo[4][4]);
void MatrixSubtract(float _MatrixOne[4][4], float _MatrixTwo[4][4]);
void MatrixMultiply(float _MatrixOne[4][4], float _MatrixTwo[4][4]);



int main()
{

	float matrixIdentity[4][4] = {
							1, 0, 0, 0,
							0, 1, 0, 0,
							0, 0, 1, 0,
							0, 0, 0, 1
	};


	std::ifstream MatrixFile;
	std::string FilePathName;
	std::string ReadInput;
	std::string Number;

	float scalar = 0;

	float matrixOne[4][4];
	float matrixTwo[4][4];

	std::cout << "Please enter the file path: ";
	std::cin >> FilePathName;
	MatrixFile.open(FilePathName);


	if (MatrixFile.is_open())
	{
		for (int i = 0; i < 4; i++)
		{
			std::getline(MatrixFile, Number, ' ');
			matrixOne[i][0] = std::stof(Number);
			std::getline(MatrixFile, Number, ' ');
			matrixOne[i][1] = std::stof(Number);
			std::getline(MatrixFile, Number, ' ');
			matrixOne[i][2] = std::stof(Number);
			std::getline(MatrixFile, Number);
			matrixOne[i][3] = std::stof(Number);
			
		}


		MatrixFile.ignore(1000, '\n');

		for (int i = 0; i < 4; i++)
		{
			std::getline(MatrixFile, Number, ' ');
			matrixTwo[i][0] = std::stof(Number);
			std::getline(MatrixFile, Number, ' ');
			matrixTwo[i][1] = std::stof(Number);
			std::getline(MatrixFile, Number, ' ');
			matrixTwo[i][2] = std::stof(Number);
			std::getline(MatrixFile, Number);
			matrixTwo[i][3] = std::stof(Number);

		}

		MatrixFile.ignore(1000, '\n');

		std::getline(MatrixFile, Number, ' ');
		scalar = std::stof(Number);

		std::cout << std::endl << std::endl;

		std::cout << "1) " << std::endl;

		std::cout << MatrixDeterminant(matrixOne) << std::endl;

		std::cout << std::endl << "2) " << std::endl;

		MatrixTranspose(matrixOne);

		std::cout << std::endl << "3) " << std::endl;

		MatrixInverse(matrixOne);

		std::cout << std::endl << "4) " << std::endl;

		MatrixScalar(matrixOne, scalar);

		std::cout << std::endl << "5) " << std::endl;

		MatrixAdd(matrixOne, matrixTwo);

		std::cout << std::endl << "6) " << std::endl;

		MatrixSubtract(matrixOne, matrixTwo);

		std::cout << std::endl << "7) " << std::endl;

		MatrixMultiply(matrixOne, matrixTwo);

		std::cout << std::endl << "8) " << std::endl;

		MatrixMultiply(matrixTwo, matrixOne);

		std::cout << std::endl << "9) " << std::endl;


		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				std::cout << matrixIdentity[i][j] << " ";
			}
			std::cout << std::endl;
		}
			
	}
	return 0;
}





void MatrixMultiply(float _MatrixOne[4][4], float _MatrixTwo[4][4])
{
	float tempMatrix[4][4];

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			float result = 0;
			for (int k = 0; k < 4; ++k)
			{
				result += _MatrixOne[i][k] * _MatrixTwo[k][j];
				tempMatrix[i][j] = result;
			}
			std::cout << tempMatrix[i][j] << " ";
		}
		std::cout << std::endl;
	}

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

	float tempMatrix[4][4];

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			float result;
			result = _Matrix[i][j] * _Scalar;
			tempMatrix[i][j] = result;
			std::cout << tempMatrix[i][j] << " ";
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