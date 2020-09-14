#include <iostream>
#include <stdlib.h>
#include <chrono>
#include <vector>
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

vector<vector<double>> createMatrixDouble(int rows, int columns)
{
  srand(time(NULL) * rows * columns);
  // cout << "Hi, you entered create matrix double\n\n";
  vector<vector<double>> matrix(rows, vector<double>(columns));
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < columns; j++)
    {
      double randomdouble = static_cast<double>(rand()) / (static_cast<double>(RAND_MAX / 100));
      matrix[i][j] = randomdouble;
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

vector<vector<int>> multiplyMatricesInt(vector<vector<int>> matrixA, vector<vector<int>> matrixB, int choice = 1)
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

  // Do matrix multiplication with conditional innerLoop, defaulting to column if not specified
  enum innerLoop
  {
    column = 1,
    row = 2
  };

  switch (choice)
  {
  case innerLoop::row:
  {
    cout << "\nRow approach\n";
    for (int row = 0; row < rowsA; row++)
    {
      for (int column = 0; column < columnsB; column++)
      {
        int sum = 0;
        for (int index = 0; index < rowsB; index++)
        {
          int firstValue = matrixA[row][index];
          int secondValue = matrixB[index][column];
          sum += firstValue * secondValue;
        }
        resultantMatrix[row][column] = sum;
      }
    }
  }
  break;

  case innerLoop::column:
  default:
  {
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
  }
  break;
  }
  return resultantMatrix;
};

vector<vector<double>> multiplyMatricesDouble(vector<vector<double>> matrixA, vector<vector<double>> matrixB, int choice = 1)
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

  // Do matrix multiplication with conditional innerLoop, defaulting to column if not specified
  enum innerLoop
  {
    column = 1,
    row = 2
  };

  switch (choice)
  {
  case innerLoop::row:
  {
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
  }
  break;

  case innerLoop::column:
  default:
  {
    cout << "Column approach";
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
  }
  break;
  }
  return resultantMatrix;
};

int main()
{
  int selection;
  cout << "1)int\n2)double\nPlease choose: ";
  cin >> selection;
  enum dataType
  {
    integer = 1,
    doublePoint = 2
  };

  int rowsA = 1000, columnsA = 200;
  int rowsB = columnsA, columnsB = 2000;
  switch (selection)
  {
    break;
  case dataType::doublePoint:
  {
    vector<vector<double>> matrixA = createMatrixDouble(rowsA, columnsA);
    vector<vector<double>> matrixB = createMatrixDouble(rowsB, columnsB);
    // printMatrixDouble(matrixA);
    // printMatrixDouble(matrixB);

    cout << "Innerloop approach\n1)column\n2)row\nPlease choose: ";
    cin >> selection;

    // Start measuring
    auto timeStart = chrono::high_resolution_clock::now();
    vector<vector<double>> productMatrix = multiplyMatricesDouble(matrixA, matrixB, selection);

    // End measuring
    auto timeEnd = chrono::high_resolution_clock::now();

    // Calculate duration
    chrono::duration<double> timeTaken = chrono::duration_cast<chrono::duration<double>>(timeEnd - timeStart);

    cout << "\n\nThe double dot product took " << timeTaken.count() << " seconds\n\n";
  }
  break;
    // multiplyMatricesInt(matrixA, matrixB);

  case dataType::integer:
  default:
  {
    vector<vector<int>> matrixA = createMatrixInt(rowsA, columnsA);
    vector<vector<int>> matrixB = createMatrixInt(rowsB, columnsB);
    // printMatrixInt(matrixA);
    // printMatrixInt(matrixB);

    cout << "Innerloop approach\n1)column\n2)row\nPlease choose: ";
    cin >> selection;
    // Start measuring
    auto timeStart = chrono::high_resolution_clock::now();
    vector<vector<int>> productMatrix = multiplyMatricesInt(matrixA, matrixB, selection);

    // End measuring
    auto timeEnd = chrono::high_resolution_clock::now();

    // Calculate duration
    chrono::duration<double> timeTaken = chrono::duration_cast<chrono::duration<double>>(timeEnd - timeStart);

    // Print results
    // cout << "\nProduct";
    // printMatrixInt(productMatrix);

    cout << "\n\nThe integer dot product took " << timeTaken.count() << " seconds\n\n";
  }
  break;
  }

  system("pause");
  return 0;
}