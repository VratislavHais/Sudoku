//
// Created by vhais on 12/20/23.
//

#include "validations.h"
#include <unordered_set>
#define MAX_VALUE 9

bool isValid(const SudokuMatrix& sudokuMatrix) {
    return areRowsValid(sudokuMatrix) && areColsValid(sudokuMatrix) && areBlocksValid(sudokuMatrix);
}

bool areRowsValid(const SudokuMatrix& sudokuMatrix) {
    std::unordered_set<int> encountered;
    for (int i = 0; i < sudokuMatrix.getSize(); i++) {
        if (i % sudokuMatrix.getRowSize() == 0) {
            encountered.clear();
        }
        if (sudokuMatrix.getValue(i) == sudokuMatrix.getEmptyCellValue()) {
            continue;
        }
        bool isInBound = sudokuMatrix.getValue(i) > 0 && sudokuMatrix.getValue(i) <= MAX_VALUE;
        if (!isInBound || encountered.find(sudokuMatrix.getValue(i)) != encountered.end()) {
            return false;
        }
        encountered.insert(sudokuMatrix.getValue(i));
    }
    return true;
}

bool areColsValid(const SudokuMatrix& sudokuMatrix) {
    std::unordered_set<int> encountered;
    for (int col = 0; col < sudokuMatrix.getSize(); col++) {
        for (int row = 0; row < sudokuMatrix.getSize(); row++) {
            if (sudokuMatrix.getValue(row, col) == sudokuMatrix.getEmptyCellValue()) {
                continue;
            }
            bool isInBound = sudokuMatrix.getValue(row, col) > 0 && sudokuMatrix.getValue(row, col) <= MAX_VALUE;
            if (!isInBound || encountered.find(sudokuMatrix.getValue(row, col)) != encountered.end()) {
                return false;
            }
            encountered.insert(sudokuMatrix.getValue(row, col));
        }
        encountered.clear();
    }
    return true;
}

bool areBlocksValid(const SudokuMatrix& sudokuMatrix) {
    for (int block = 0; block < sudokuMatrix.getRowSize(); block++) {
        if (!isBlockValid(block, sudokuMatrix)) {
            return false;
        }
    }
    return true;
}

bool isBlockValid(int blockNumber, const SudokuMatrix& sudokuMatrix) {
    std::unordered_set<int> encountered{};
    for (int row = 0; row < sudokuMatrix.getBlockSize(); row++) {
        for (int col = 0; col < sudokuMatrix.getBlockSize(); col++) {
            int blockRow{sudokuMatrix.getBlockSize() * (blockNumber / sudokuMatrix.getBlockSize()) + row};
            int blockCol{sudokuMatrix.getBlockSize() * (blockNumber % sudokuMatrix.getBlockSize()) + col};
            int cellValue{sudokuMatrix.getValue(blockRow, blockCol)};
            if (cellValue == sudokuMatrix.getEmptyCellValue()) {
                continue;
            }
            bool isInBound = sudokuMatrix.getValue(blockRow, blockCol) > 0 && sudokuMatrix.getValue(blockRow, blockCol) <= MAX_VALUE;
            if (!isInBound || encountered.find(cellValue) != encountered.end()) {
                return false;
            }
            encountered.insert(cellValue);
        }
    }
    return true;
}
