#include <iostream>
#include <stdlib.h>
#include <chrono>
#include <vector>
#include <conio.h>
using namespace std;

vector<vector<double>> createMatrixDouble(int rows, int columns)
{
  srand(time(NULL) * rows * columns);
  // cout << "Hi, you entered create matrix Double\n\n";
  vector<vector<double>> matrix(rows, vector<double>(columns));
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < columns; j++)
    {
      double randomDouble = static_cast<double>(rand()) / (static_cast<double>(RAND_MAX / 100));
      matrix[i][j] = randomDouble;
    }
  }
  return matrix;
}

void printMatrixDouble(vector<vector<double>> matrix)
{
  int rows = matrix.size();
  int columns = matrix[0].size();

  cout << "\nMatrix\n";
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < columns; j++)
    {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
}

vector<vector<double>> multiplyMatricesDouble(vector<vector<double>> matrixA, vector<vector<double>> matrixB)
{
  // rA x cA * rB x cB -> rA x cB
  // 2 x 3 * 3 x 2 = 2 x 2
  double rowsA = matrixA.size();
  double columnsA = matrixA[0].size();

  double rowsB = matrixB.size();
  double columnsB = matrixB[0].size();
  ;
  // Prepare matrix of new size
  vector<vector<double>> resultantMatrix = createMatrixDouble(rowsA, columnsB);

  cout << "\nRow approach\n";
  for (int row = 0; row < rowsA; row++)
  {
    for (int column = 0; column < columnsB; column++)
    {
      double sum = 0;
      for (int index = 0; index < rowsB; index++)
      {
        double firstValue = matrixA[row][index];
        double secondValue = matrixB[index][column];
        sum += firstValue * secondValue;
      }
      resultantMatrix[row][column] = sum;
    }
  }
  return resultantMatrix;
};

void createAndMultiply()
{
  int rowsA = 1000, columnsA = 200;
  int rowsB = columnsA, columnsB = 2000;

  vector<vector<double>> matrixA = createMatrixDouble(rowsA, columnsA);
  vector<vector<double>> matrixB = createMatrixDouble(rowsB, columnsB);
  // printMatrixDouble(matrixA);
  // printMatrixDouble(matrixB);

  // Start measuring
  auto timeStart = chrono::high_resolution_clock::now();
  vector<vector<double>> productMatrix = multiplyMatricesDouble(matrixA, matrixB);

  // End measuring
  auto timeEnd = chrono::high_resolution_clock::now();

  // Calculate duration
  chrono::duration<double> timeTaken = chrono::duration_cast<chrono::duration<double>>(timeEnd - timeStart);

  cout << "\n\nThe double dot product of " << rowsA << " x " << columnsA << " . " << rowsB << " x " << columnsB << " took " << timeTaken.count() << " seconds\n\n";
}

int main()
{

  char x = 'r';
  while (x == 'R' || x == 'r')
  {
    createAndMultiply();
    cout << "\nPress R to run again\n";
    x = getch();
  }
  return 0;
}