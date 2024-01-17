//
// Created by vhais on 12/20/23.
//

#ifndef SUDOKU_VALIDATIONS_H
#define SUDOKU_VALIDATIONS_H
#include "SudokuMatrix.h"

bool isValid(const SudokuMatrix& sudokuMatrix);
bool areRowsValid(const SudokuMatrix& sudokuMatrix);
bool areColsValid(const SudokuMatrix& sudokuMatrix);
bool areBlocksValid(const SudokuMatrix& sudokuMatrix);
bool isBlockValid(int blockNumber, const SudokuMatrix& sudokuMatrix);

#endif //SUDOKU_VALIDATIONS_H
