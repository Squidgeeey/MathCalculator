#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>


/***********************************************
* MatrixTranspose: Converts and displays the transpose of any given matrix
* @author: Jayden Drube
* @parameter: _Matrix is a 4x4 matrix(a 2D array of floats)
* @return: Void
************************************************/
void MatrixTranspose(float _Matrix[4][4]);

/***********************************************
* MatrixDeterminant: Calculates and displays the determinant of any given matrix
* @author: Jayden Drube
* @parameter: _Matrix is a 4x4 matrix(a 2D array of floats)
* @return: int (the result of the determinant)
************************************************/
int MatrixDeterminant(float _Matrix[4][4]);

/***********************************************
* MatrixScalar: Multiplies the provided matrix by the provided scalar value
* @author: Jayden Drube
* @parameter: _Matrix is a 4x4 matrix(a 2D array of floats), _Scalar is a scalar value
* @return: Void
************************************************/
void MatrixScalar(float _Matrix[4][4], float _Scalar);

/***********************************************
* MatrixInverse: Calculates and displays the inverse of any given matrix
* @author: Jayden Drube
* @parameter: _Matrix is a 4x4 matrix(a 2D array of floats)
* @return: Void
************************************************/
void MatrixInverse(float _Matrix[4][4]);

/***********************************************
* MatrixAdd: Adds together two matrices and displays the resultant matrix
* @author: Jayden Drube
* @parameter: _MatrixOne is the first 4x4 matrix(a 2D array of floats), _MatrixTwo is the second matrix to be added with 
* @return: Void
************************************************/
void MatrixAdd(float _MatrixOne[4][4], float _MatrixTwo[4][4]);

/***********************************************
* MatrixAdd: Subtracts the first matrix from the second and displays the resulting matrix
* @author: Jayden Drube
* @parameter: _MatrixOne is the first 4x4 matrix(a 2D array of floats), _MatrixTwo is the second matrix to be added with
* @return: Void
************************************************/
void MatrixSubtract(float _MatrixOne[4][4], float _MatrixTwo[4][4]);

/***********************************************
* MatrixAdd: Adds together two matrices and displays the resultant matrix
* @author: Jayden Drube
* @parameter: _MatrixOne is the first 4x4 matrix(a 2D array of floats), _MatrixTwo is the second matrix to be added with
* @return: Void
************************************************/
void MatrixMultiply(float _MatrixOne[4][4], float _MatrixTwo[4][4]);



int main()
{

	// set up of a 4x4 identity matrix
	float matrixIdentity[4][4] = {
							1, 0, 0, 0,
							0, 1, 0, 0,
							0, 0, 1, 0,
							0, 0, 0, 1
	};

	// variable init
	std::ifstream MatrixFile;
	std::string FilePathName;
	std::string ReadInput;
	std::string Number;

	float scalar = 0;

	float matrixOne[4][4];
	float matrixTwo[4][4];


	//Getting filepath from user
	std::cout << "Please enter the file path: ";
	std::cin >> FilePathName;
	MatrixFile.open(FilePathName);

	// file reading 

	if (MatrixFile.is_open())
	{
		for (int i = 0; i < 4; i++)
		{
			// obtain the information in one row of a matrix and insert it into the correct positions of a 2d array
			std::getline(MatrixFile, Number, ' ');
			matrixOne[i][0] = std::stof(Number);
			std::getline(MatrixFile, Number, ' ');
			matrixOne[i][1] = std::stof(Number);
			std::getline(MatrixFile, Number, ' ');
			matrixOne[i][2] = std::stof(Number);
			std::getline(MatrixFile, Number);
			matrixOne[i][3] = std::stof(Number);
			
		}

		// ignore the blank space between 2 matrices

		MatrixFile.ignore(1000, '\n');

		for (int i = 0; i < 4; i++)
		{
			// obtain the information in one row of a matrix and insert it into the correct positions of a 2d array
			std::getline(MatrixFile, Number, ' ');
			matrixTwo[i][0] = std::stof(Number);
			std::getline(MatrixFile, Number, ' ');
			matrixTwo[i][1] = std::stof(Number);
			std::getline(MatrixFile, Number, ' ');
			matrixTwo[i][2] = std::stof(Number);
			std::getline(MatrixFile, Number);
			matrixTwo[i][3] = std::stof(Number);

		}

		// ignore the blank space between second matrix and scalar value
		MatrixFile.ignore(1000, '\n');

		// obtain scalar value
		std::getline(MatrixFile, Number, ' ');
		scalar = std::stof(Number);

		// console formatting
		std::cout << std::endl << std::endl;


		// Do question 1)
		std::cout << "1) " << std::endl;
		std::cout << MatrixDeterminant(matrixOne) << std::endl;

		// Do question 2)
		std::cout << std::endl << "2) " << std::endl;
		MatrixTranspose(matrixOne);

		// Do question 3)
		std::cout << std::endl << "3) " << std::endl;
		MatrixInverse(matrixOne);

		// Do question 4)
		std::cout << std::endl << "4) " << std::endl;
		MatrixScalar(matrixOne, scalar);

		// Do question 5)
		std::cout << std::endl << "5) " << std::endl;
		MatrixAdd(matrixOne, matrixTwo);

		// Do question 6)
		std::cout << std::endl << "6) " << std::endl;
		MatrixSubtract(matrixOne, matrixTwo);

		// Do question 7)
		std::cout << std::endl << "7) " << std::endl;
		MatrixMultiply(matrixOne, matrixTwo);

		// Do question 8)
		std::cout << std::endl << "8) " << std::endl;
		MatrixMultiply(matrixTwo, matrixOne);


		// Display identity matrix for question 9)
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
				// make the temp matrix the result of multiplying everything in the row and columns that correspond to that position.
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
			// add together the two floats at i and j
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
			// subtract the two floats at i and j
			tempMatrix[i][j] = _MatrixOne[i][j] - _MatrixTwo[i][j];

			std::cout << tempMatrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}


void MatrixInverse(float _Matrix[4][4])
{
	float tempMatrix[4][4];

// calculating determinants of the 3x3 matrices within the provided 4x4 matrix.

	// Filling first row of temp matrix with those determinants.
	tempMatrix[0][0] = ((_Matrix[1][1] * _Matrix[2][2] * _Matrix[3][3]) + (_Matrix[1][2] * _Matrix[2][3] * _Matrix[3][1]) + (_Matrix[1][3] * _Matrix[2][1] * _Matrix[3][2])
		- (_Matrix[1][3] * _Matrix[2][2] * _Matrix[3][1]) - (_Matrix[1][2] * _Matrix[2][1] * _Matrix[3][3]) - (_Matrix[1][1] * _Matrix[2][3] * _Matrix[3][2]));

	tempMatrix[0][1] = -(_Matrix[0][1] * _Matrix[2][2] * _Matrix[3][3]) - (_Matrix[0][2] * _Matrix[2][3] * _Matrix[3][1]) - (_Matrix[0][3] * _Matrix[2][1] * _Matrix[3][2])
		+ (_Matrix[0][3] * _Matrix[2][2] * _Matrix[3][1]) + (_Matrix[0][2] * _Matrix[2][1] * _Matrix[3][3]) + (_Matrix[0][1] * _Matrix[2][3] * _Matrix[3][2]);

	tempMatrix[0][2] = (_Matrix[0][1] * _Matrix[1][2] * _Matrix[3][3]) + (_Matrix[0][2] * _Matrix[1][3] * _Matrix[3][1]) + (_Matrix[0][3] * _Matrix[1][1] * _Matrix[3][2])
		- (_Matrix[0][3] * _Matrix[1][2] * _Matrix[3][1]) - (_Matrix[0][2] * _Matrix[1][1] * _Matrix[3][3]) - (_Matrix[0][1] * _Matrix[1][3] * _Matrix[3][2]);

	tempMatrix[0][3] = -(_Matrix[0][1] * _Matrix[1][2] * _Matrix[2][3]) - (_Matrix[0][2] * _Matrix[1][3] * _Matrix[2][1]) - (_Matrix[0][3] * _Matrix[1][1] * _Matrix[2][2])
		+ (_Matrix[0][3] * _Matrix[1][2] * _Matrix[2][1]) + (_Matrix[0][2] * _Matrix[1][1] * _Matrix[2][3]) + (_Matrix[0][1] * _Matrix[1][3] * _Matrix[2][2]);


	// Filling second row of temp matrix with those determinants.
	tempMatrix[1][0] = -(_Matrix[1][0] * _Matrix[2][2] * _Matrix[3][3]) - (_Matrix[1][2] * _Matrix[2][3] * _Matrix[3][0]) - (_Matrix[1][3] * _Matrix[2][0] * _Matrix[3][2])
		+ (_Matrix[1][3] * _Matrix[2][2] * _Matrix[3][0]) + (_Matrix[1][2] * _Matrix[2][0] * _Matrix[3][3]) + (_Matrix[1][0] * _Matrix[2][3] * _Matrix[3][2]);

	tempMatrix[1][1] = (_Matrix[0][0] * _Matrix[2][2] * _Matrix[3][3]) + (_Matrix[0][2] * _Matrix[2][3] * _Matrix[3][0]) + (_Matrix[0][3] * _Matrix[2][0] * _Matrix[3][2])
		- (_Matrix[0][3] * _Matrix[2][2] * _Matrix[3][0]) - (_Matrix[0][2] * _Matrix[2][0] * _Matrix[3][3]) - (_Matrix[0][0] * _Matrix[2][3] * _Matrix[3][2]);

	tempMatrix[1][2] = -(_Matrix[0][0] * _Matrix[1][2] * _Matrix[3][3]) - (_Matrix[0][2] * _Matrix[1][3] * _Matrix[3][0]) - (_Matrix[0][3] * _Matrix[1][0] * _Matrix[3][2])
		+ (_Matrix[0][3] * _Matrix[1][2] * _Matrix[3][1]) + (_Matrix[0][2] * _Matrix[1][1] * _Matrix[3][3]) + (_Matrix[0][1] * _Matrix[1][3] * _Matrix[3][2]);

	tempMatrix[1][3] = (_Matrix[0][0] * _Matrix[1][2] * _Matrix[2][3]) + (_Matrix[0][2] * _Matrix[1][3] * _Matrix[2][0]) + (_Matrix[0][3] * _Matrix[1][0] * _Matrix[2][2])
		- (_Matrix[0][3] * _Matrix[1][2] * _Matrix[2][0]) - (_Matrix[0][2] * _Matrix[1][0] * _Matrix[2][3]) - (_Matrix[0][0] * _Matrix[1][3] * _Matrix[2][2]);


	// Filling third row of temp matrix with those determinants.
	tempMatrix[2][0] = (_Matrix[1][0] * _Matrix[2][1] * _Matrix[3][3]) + (_Matrix[1][1] * _Matrix[2][3] * _Matrix[3][0]) + (_Matrix[1][3] * _Matrix[2][0] * _Matrix[3][1])
		- (_Matrix[1][3] * _Matrix[2][1] * _Matrix[3][0]) - (_Matrix[1][1] * _Matrix[2][0] * _Matrix[3][3]) - (_Matrix[1][0] * _Matrix[2][3] * _Matrix[3][1]);

	tempMatrix[2][1] = -(_Matrix[0][0] * _Matrix[2][1] * _Matrix[3][3]) - (_Matrix[0][1] * _Matrix[2][3] * _Matrix[3][0]) - (_Matrix[0][3] * _Matrix[2][0] * _Matrix[3][1])
		+ (_Matrix[0][3] * _Matrix[2][1] * _Matrix[3][0]) + (_Matrix[0][1] * _Matrix[2][0] * _Matrix[3][3]) + (_Matrix[0][0] * _Matrix[2][3] * _Matrix[3][1]);

	tempMatrix[2][2] = (_Matrix[0][0] * _Matrix[1][1] * _Matrix[3][3]) + (_Matrix[0][1] * _Matrix[1][3] * _Matrix[3][0]) + (_Matrix[0][3] * _Matrix[1][0] * _Matrix[3][1])
		- (_Matrix[0][3] * _Matrix[1][1] * _Matrix[3][0]) - (_Matrix[0][1] * _Matrix[1][0] * _Matrix[3][3]) - (_Matrix[0][0] * _Matrix[1][3] * _Matrix[3][1]);

	tempMatrix[2][3] = -(_Matrix[0][0] * _Matrix[1][1] * _Matrix[2][3]) - (_Matrix[0][1] * _Matrix[1][3] * _Matrix[2][0]) - (_Matrix[0][3] * _Matrix[1][0] * _Matrix[2][1])
		+ (_Matrix[0][3] * _Matrix[1][1] * _Matrix[2][0]) + (_Matrix[0][1] * _Matrix[1][0] * _Matrix[2][3]) + (_Matrix[0][0] * _Matrix[1][3] * _Matrix[2][1]);


	// Filling fourth row of temp matrix with those determinants.
	tempMatrix[3][0] = -(_Matrix[1][0] * _Matrix[2][1] * _Matrix[3][2]) - (_Matrix[1][1] * _Matrix[2][2] * _Matrix[3][0]) - (_Matrix[1][2] * _Matrix[2][0] * _Matrix[3][1])
		+ (_Matrix[1][2] * _Matrix[2][1] * _Matrix[3][0]) + (_Matrix[1][1] * _Matrix[2][0] * _Matrix[3][2]) + (_Matrix[1][0] * _Matrix[2][2] * _Matrix[3][1]);

	tempMatrix[3][1] = (_Matrix[0][0] * _Matrix[2][1] * _Matrix[3][2]) + (_Matrix[0][1] * _Matrix[2][2] * _Matrix[3][0]) + (_Matrix[0][2] * _Matrix[2][0] * _Matrix[3][1])
		- (_Matrix[0][2] * _Matrix[2][1] * _Matrix[3][0]) - (_Matrix[0][1] * _Matrix[2][0] * _Matrix[3][2]) - (_Matrix[0][0] * _Matrix[2][2] * _Matrix[3][1]);

	tempMatrix[3][2] = -(_Matrix[0][0] * _Matrix[1][1] * _Matrix[3][2]) - (_Matrix[0][1] * _Matrix[1][2] * _Matrix[3][0]) - (_Matrix[0][2] * _Matrix[1][0] * _Matrix[3][1])
		+ (_Matrix[0][2] * _Matrix[1][1] * _Matrix[3][0]) + (_Matrix[0][1] * _Matrix[1][0] * _Matrix[3][2]) + (_Matrix[0][0] * _Matrix[1][2] * _Matrix[3][1]);

	tempMatrix[3][3] = (_Matrix[0][0] * _Matrix[1][1] * _Matrix[2][2]) + (_Matrix[0][1] * _Matrix[1][2] * _Matrix[2][0]) + (_Matrix[0][2] * _Matrix[1][0] * _Matrix[2][1])
		- (_Matrix[0][2] * _Matrix[1][1] * _Matrix[2][0]) - (_Matrix[0][1] * _Matrix[1][0] * _Matrix[2][2]) - (_Matrix[0][0] * _Matrix[1][2] * _Matrix[2][1]);


	// calculate determinant of the original 4x4 matrix
	float det = MatrixDeterminant(_Matrix);
	det = 1 / det;

	// multiplying the new matrix by the calculated determinant
	MatrixScalar(tempMatrix, det);
}


void MatrixScalar(float _Matrix[4][4], float _Scalar)
{

	float tempMatrix[4][4];

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			// multiplying each i and j position by the provided scalar value
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
			//swapping rows / columns
			matrixTemp[i][j] = _Matrix[j][i];
			std::cout << matrixTemp[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

int MatrixDeterminant(float _Matrix[4][4])
{
	int determinant = 

		// doing equation for 4x4 determinant calculation

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