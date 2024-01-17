//
// Created by vhais on 12/20/23.
//

#ifndef SUDOKU_SUDOKUMATRIX_H
#define SUDOKU_SUDOKUMATRIX_H

#include <iostream>
#include <cmath>


class SudokuMatrix {
private:
    int*        matrix;
    const int   rowSize{9};
    const int   size{rowSize * rowSize};
    const int   blockSize{static_cast<int>(std::sqrt(rowSize))};
    const int   emptyCell{0};
    const char  emptyCellRepr{'.'};
public:
    explicit SudokuMatrix();
    [[nodiscard]] int getSize() const;
    [[nodiscard]] int getRowSize() const;
    [[nodiscard]] int getBlockSize() const;
    [[nodiscard]] int getEmptyCellValue() const;
    void setEntry(int row, int col, int item);
    void setEntry(int cell, int item);
    [[nodiscard]] int getValue(int row, int col) const;
    [[nodiscard]] int getValue(int cell) const;
    bool operator==(const SudokuMatrix& other) const;
    friend std::ostream& operator<<(std::ostream& stream, const SudokuMatrix& squareMatrix);
};

struct SudokuMatrixHasher {
    std::size_t operator()(const SudokuMatrix& squareMatrix) const;
};


#endif //SUDOKU_SUDOKUMATRIX_H
