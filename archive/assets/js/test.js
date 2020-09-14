// Homework 1 for CS402 Fall 2020 by Muhammad Umar

const { performance } = require("perf_hooks");
const ndarray = require("ndarray");

// const a = ndarray(new Float32Array(5), [5, 10]);
// var mat = ndarray(new Float64Array([1, 0, 0, 1]), [2, 2]);

const createMatrix = (rows = 2, columns = 3, real = false) => {
  const matrix = real
    ? ndarray(new Float64Array(rows * columns, [rows, columns]))
    : ndarray(new Uint8Array(rows * columns, [rows, columns]));
  for (let row = 0; row < rows; row++) {
    matrix[row] = new Array(columns);
  }
  return matrix;
};

const multiplyMatrices = (
  matrixA,
  matrixB,
  matrixAShape,
  matrixBShape,
  innerLoop = "column"
) => {
  // rA x cA * rB x cB -> rA x cB
  // 2 x 3 * 3 x 2 = 2 x 2
  const rowsA = matrixAShape.rows;
  const columnsA = matrixAShape.columns;

  const rowsB = matrixBShape.rows;
  const columnsB = matrixBShape.columns;

  // Prepare matrix of new size
  const resultantMatrix = createMatrix(rowsA, columnsB);

  // Do matrix multiplication with conditional innerLoop, defaulting to column if not specified
  switch (innerLoop) {
    case "row":
      for (let row = 0; row < rowsA; row++) {
        for (let column = 0; column < columnsB; column++) {
          let sum = 0;
          for (let index = 0; index < rowsB; index++) {
            // const firstValue = matrixA[row][index];
            // const secondValue = matrixB[index][column];
            // sum += firstValue * secondValue;

            const firstValue = matrixA.get(row, index);
            const secondValue = matrixB.get(index, column);
            sum += firstValue * secondValue;
          }
          // resultantMatrix[row][column] = sum;
          resultantMatrix.set(row, column, sum);
        }
      }
      break;

    case "column":
    default:
      for (let row = 0; row < rowsA; row++) {
        for (let column = 0; column < columnsB; column++) {
          let sum = 0;
          for (let index = 0; index < columnsA; index++) {
            // const firstValue = matrixA[row][index];
            // const secondValue = matrixB[index][column];
            // sum += firstValue * secondValue;

            const firstValue = matrixA.get(row, index);
            const secondValue = matrixB.get(index, column);
            sum += firstValue * secondValue;
          }
          // resultantMatrix[row][column] = sum;
          resultantMatrix.set(row, column, sum);
        }
      }
      break;
  }
  return resultantMatrix;
};

const randomizeMatrix = (matrix, matrixShape, real = false) => {
  const { rows, columns } = matrixShape;
  // console.log(matrix, rows, columns);
  for (let row = 0; row < rows; row++) {
    for (let column = 0; column < columns; column++) {
      const randomNumber = Math.random() * 10;
      matrix.set(row, column, real ? randomNumber : Math.floor(randomNumber));
    }
  }
  return matrix;
};

// const matrixA = createMatrix(2, 3);
// console.log(matrixA);

calculate("integer");
calculate("real");

function calculate(type = "integer") {
  // Disable submit buttons
  // setElement(".submit-results", "disabled", true);

  // Matrix constants
  const matrixAShape = { rows: 400, columns: 600 };
  const matrixBShape = { rows: matrixAShape.columns, columns: 1000 };

  // Defaults to integer type calculation unless stated
  const real = type === "real" ? true : false;
  // Number of times that the operation will run while defaulting to 1
  let benchmarkRuns;
  try {
    benchmarkRuns = Number(
      document && document.getElementById("benchmark-runs").value
    );
  } catch (e) {
    benchmarkRuns = 5;
  }

  let innerLoop;
  try {
    innerLoop = document && document.forms.algorithm.elements.approach.value;
  } catch (e) {
    innerLoop = "column";
  }
  // const benchmarkRuns = 2;

  // Generate matrices
  let matrixA = createMatrix(matrixAShape.rows, matrixAShape.columns, real);
  let matrixB = createMatrix(matrixBShape.rows, matrixBShape.columns, real);

  // ---Example matrices for testing---
  // matrixA = [
  //   [1, 2, 3],
  //   [4, 5, 6],
  // ];
  // matrixB = [
  //   [7, 8],
  //   [9, 10],
  //   [11, 12],
  // ];

  // console.table(matrixA);
  // console.table(matrixB);

  let totalTime = 0;

  // Table Selector
  const selector = real ? "real-results" : "integer-results";

  let tableBody;
  try {
    tableBody = document && document.getElementById(`${selector}-table-body`);
  } catch (e) {
    tableBody = null;
  }

  // Clear table body
  if (tableBody) {
    tableBody.innerHTML = "";
  }

  for (let run = 0; run < benchmarkRuns; run++) {
    // Randomize matrices
    matrixA = randomizeMatrix(matrixA, matrixAShape, real);
    matrixB = randomizeMatrix(matrixB, matrixBShape, real);

    // Multiply integer matrices and measure
    const timeStart = performance.now();
    result = multiplyMatrices(
      matrixA,
      matrixB,
      matrixAShape,
      matrixBShape,
      innerLoop
    );
    const timeEnd = performance.now();

    //Sum time taken for each run
    const timeTaken = timeEnd - timeStart;

    totalTime += timeTaken;
    // insertBenchmarkRow(tableBody, run, timeTaken);
  }

  // Calculate time taken in ms
  const averageTime = totalTime / benchmarkRuns;

  // Print results

  // console.table(result);
  console.log(
    `${
      type[0].toUpperCase() + type.slice(1, type.length)
    } matrix multiplication took ${
      averageTime / 1000
    }s on average while the total time taken for ${benchmarkRuns} runs was ${
      totalTime / 1000
    }s using ${innerLoop} approach.`
  );
}
