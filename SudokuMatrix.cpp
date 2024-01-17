//
// Created by vhais on 12/20/23.
//
#include "SudokuMatrix.h"
#include <functional>

SudokuMatrix::SudokuMatrix() {
    matrix = new int[size];
    for (int i = 0; i < size; i++) {
        matrix[i] = emptyCell;
    }
}

int SudokuMatrix::getSize() const {
    return size;
}

int SudokuMatrix::getRowSize() const {
    return rowSize;
}

int SudokuMatrix::getBlockSize() const {
    return blockSize;
}

int SudokuMatrix::getEmptyCellValue() const {
    return emptyCell;
}

void SudokuMatrix::setEntry(int row, int col, int item) {
    if (row < rowSize && col < rowSize) {
        matrix[row * rowSize + col] = item;
    }
}

void SudokuMatrix::setEntry(int cell, int item) {
    if (cell < size) {
        matrix[cell] = item;
    }
}

int SudokuMatrix::getValue(int row, int col) const {
    if (row < rowSize && col < rowSize) {
        return matrix[row * rowSize + col];
    }
    return 0;
}

int SudokuMatrix::getValue(int cell) const {
    if (cell < size) {
        return matrix[cell];
    }
    return 0;
}

bool SudokuMatrix::operator==(const SudokuMatrix &other) const {
    if (size != other.size) {
        return false;
    }
    for (int i = 0; i < size; i++) {
        if (matrix[i] != other.getValue(i)) {
            return false;
        }
    }
    return true;
}

std::ostream &operator<<(std::ostream &stream, const SudokuMatrix &squareMatrix) {
    for (int i = 0; i < squareMatrix.size; i++) {
        if (squareMatrix.matrix[i] == squareMatrix.emptyCell) {
            std::cout << squareMatrix.emptyCellRepr << ' ';
        } else {
            std::cout << squareMatrix.matrix[i] << ' ';
        }
        if (i > 0 && (i+1) % squareMatrix.rowSize == 0) {
            std::cout << '\n';
        }
    }
    return stream;
}

std::size_t SudokuMatrixHasher::operator()(const SudokuMatrix &squareMatrix) const {
    size_t hash{};
    size_t hashRow{};
    for (int i = 0; i < squareMatrix.getSize(); i++) {
        if (i % squareMatrix.getRowSize()) {
            if (hash == 0) {
                hash = hashRow;
            } else {
                hash ^= hashRow;
            }
            hashRow = 0;
        }
        hashRow += std::hash<int>()(squareMatrix.getValue(i));
    }
    return hash;
}
