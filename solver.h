//
// Created by vhais on 12/21/23.
//

#ifndef SUDOKU_SOLVER_H
#define SUDOKU_SOLVER_H

#include "SudokuMatrix.h"
#include <unordered_map>
#include <string>

bool solve(SudokuMatrix& sudokuMatrix);
bool solve(SudokuMatrix& sudokuMatrix, int cellNumber);

#endif //SUDOKU_SOLVER_H
