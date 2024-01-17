//
// Created by vhais on 12/22/23.
//

#include "generator.h"
#include "validations.h"
#include "solver.h"
#include <random>
#include <vector>

#define MAX_VALUE 9

SudokuMatrix generate(int numberOfFields) {
    SudokuMatrix sudoku = getValidSudoku();
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(0, sudoku.getSize() - 1);
    std::vector<int> cellList{};
    for (int i = 0; i < sudoku.getSize(); i++) {
        cellList.push_back(i);
    }
    int fieldsToRemove{ sudoku.getSize() - numberOfFields };
    while (fieldsToRemove >= 0) {
        int index{static_cast<int>(distribution(gen) % cellList.size())};
        sudoku.setEntry(cellList[index], sudoku.getEmptyCellValue());

        cellList.erase(cellList.begin() + index);

        fieldsToRemove--;
    }
    return sudoku;
}

SudokuMatrix generateEasy() {
    return generate(38);
}

SudokuMatrix generateMedium() {
    return generate(30);
}
SudokuMatrix generateHard() {
    return generate(28);
}
SudokuMatrix generateExpert() {
    return generate(25);
}

SudokuMatrix generateEvil() {
    return generate(22);
}

void addCellValue(SudokuMatrix& sudoku, int cellNumber) {
    std::vector<int> numbersLeft{};
    for (int i = 1; i <= MAX_VALUE; i++) {
        numbersLeft.push_back(i);
    }
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(0, numbersLeft.size() - 1);
    do {
        int index{ static_cast<int>(distribution(gen) % numbersLeft.size()) };
        sudoku.setEntry(cellNumber, numbersLeft[index]);
        numbersLeft.erase(numbersLeft.begin() + index);
    } while (!isValid(sudoku) && !numbersLeft.empty());
}

SudokuMatrix getValidSudoku() {
    SudokuMatrix sudoku = SudokuMatrix();
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> position(0, sudoku.getSize() - 1);
    std::uniform_int_distribution<int> value(1, MAX_VALUE);
    int index{};
    do {
        sudoku.setEntry(index, sudoku.getEmptyCellValue());
        index = position(gen);
        sudoku.setEntry(index, value(gen));
    } while (!solve(sudoku));
    return sudoku;
}
