//
// Created by vhais on 12/22/23.
//

#ifndef SUDOKU_GENERATOR_H
#define SUDOKU_GENERATOR_H

#include "SudokuMatrix.h"

SudokuMatrix generate(int numberOfFields);
SudokuMatrix generateEasy();
SudokuMatrix generateMedium();
SudokuMatrix generateHard();
SudokuMatrix generateExpert();
SudokuMatrix generateEvil();

void addCellValue(SudokuMatrix& sudoku, int cellNumber);
SudokuMatrix getValidSudoku();

#endif //SUDOKU_GENERATOR_H
