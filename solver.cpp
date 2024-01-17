//
// Created by vhais on 12/21/23.
//

#include "solver.h"
#include "validations.h"
#define MAX_VALUE 9

bool solve(SudokuMatrix& sudokuMatrix) {
    return solve(sudokuMatrix, 0);
}

bool solve(SudokuMatrix& sudokuMatrix, int cellNumber) {
    if (cellNumber >= sudokuMatrix.getSize()) {
        return true;
    }
    if (sudokuMatrix.getValue(cellNumber) != sudokuMatrix.getEmptyCellValue()) {
        return solve(sudokuMatrix, cellNumber+1);
    }
    for (int i = 1; i <= MAX_VALUE; i++) {
        sudokuMatrix.setEntry(cellNumber, i);
        if (isValid(sudokuMatrix) && solve(sudokuMatrix, cellNumber+1)) {
            return true;
        }
    }
    sudokuMatrix.setEntry(cellNumber, sudokuMatrix.getEmptyCellValue());
    return false;
}
