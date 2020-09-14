#include <iostream>
#include <stdlib.h>
#include <chrono>
#include <vector>
#include <conio.h>
using namespace std;

vector<vector<int>> createMatrixInt(int rows, int columns)
{
  srand(time(NULL) * rows * columns);
  // cout << "Hi, you entered create matrix Int\n\n";

  vector<vector<int>> matrix(rows, vector<int>(columns));
  // cout << "Hi, you entered create matrix";
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < columns; j++)
    {
      matrix[i][j] = rand() % 100;
    }
  }
  return matrix;
}

void printMatrixInt(vector<vector<int>> matrix)
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

vector<vector<int>> multiplyMatricesInt(vector<vector<int>> matrixA, vector<vector<int>> matrixB)
{
  // rA x cA * rB x cB -> rA x cB
  // 2 x 3 * 3 x 2 = 2 x 2
  int rowsA = matrixA.size();
  int columnsA = matrixA[0].size();

  int rowsB = matrixB.size();
  int columnsB = matrixB[0].size();
  ;
  // Prepare matrix of new size
  vector<vector<int>> resultantMatrix = createMatrixInt(rowsA, columnsB);
  cout << "\nColumn approach\n";
  for (int row = 0; row < rowsA; row++)
  {
    for (int column = 0; column < columnsB; column++)
    {
      int sum = 0;
      for (int index = 0; index < columnsA; index++)
      {
        int firstValue = matrixA[row][index];
        int secondValue = matrixB[index][column];
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

  vector<vector<int>> matrixA = createMatrixInt(rowsA, columnsA);
  vector<vector<int>> matrixB = createMatrixInt(rowsB, columnsB);
  // printMatrixInt(matrixA);
  // printMatrixInt(matrixB);

  // Start measuring
  auto timeStart = chrono::high_resolution_clock::now();
  vector<vector<int>> productMatrix = multiplyMatricesInt(matrixA, matrixB);

  // End measuring
  auto timeEnd = chrono::high_resolution_clock::now();

  // Calculate duration
  chrono::duration<double> timeTaken = chrono::duration_cast<chrono::duration<double>>(timeEnd - timeStart);

  // Print results
  // cout << "\nProduct";
  // printMatrixInt(productMatrix);

  cout << "\n\nThe integer dot product of " << rowsA << " x " << columnsA << " . " << rowsB << " x " << columnsB << " took " << timeTaken.count() << " seconds\n\n";
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