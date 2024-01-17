#include "SudokuMatrix.h"
#include "generator.h"
#include "solver.h"
#include <iostream>

/*
 * class representing square matrix:
 *      * type integer
 *      * default values 0
 *      * hashcode equal to sum of hashcodes of all arrays
 *      * equals checking if items inside of arrays are equal
 * validate sudoku solution:
 *      * isValid()
 *      * must have good performance
 *      * works on objects of square matrix
 *      * (optional) ability to check sudoku with more than 9 numbers
 * solve sudoku:
 *      * solve()
 *      * method will take square matrix object
 *      * uses recursion with caching
 *      * uses isValid() method
 * generate sudoku;
 *      * generate()
 *      * creates a solvable sudoku
 */

void validSudoku(SudokuMatrix& s) {
    s.setEntry(0, 0, 4);
    s.setEntry(0, 1, 3);
    s.setEntry(0, 2, 5);
    s.setEntry(0, 3, 2);
    s.setEntry(0, 4, 6);
    s.setEntry(0, 5, 9);
    s.setEntry(0, 6, 7);
    s.setEntry(0, 7, 8);
    s.setEntry(0, 8, 1);
    s.setEntry(1, 0, 6);
    s.setEntry(1, 1, 8);
    s.setEntry(1, 2, 2);
    s.setEntry(1, 3, 5);
    s.setEntry(1, 4, 7);
    s.setEntry(1, 5, 1);
    s.setEntry(1, 6, 4);
    s.setEntry(1, 7, 9);
    s.setEntry(1, 8, 3);
    s.setEntry(2, 0, 1);
    s.setEntry(2, 1, 9);
    s.setEntry(2, 2, 7);
    s.setEntry(2, 3, 8);
    s.setEntry(2, 4, 3);
    s.setEntry(2, 5, 4);
    s.setEntry(2, 6, 5);
    s.setEntry(2, 7, 6);
    s.setEntry(2, 8, 2);
    s.setEntry(3, 0, 8);
    s.setEntry(3, 1, 2);
    s.setEntry(3, 2, 6);
    s.setEntry(3, 3, 1);
    s.setEntry(3, 4, 9);
    s.setEntry(3, 5, 5);
    s.setEntry(3, 6, 3);
    s.setEntry(3, 7, 4);
    s.setEntry(3, 8, 7);
    s.setEntry(4, 0, 3);
    s.setEntry(4, 1, 7);
    s.setEntry(4, 2, 4);
    s.setEntry(4, 3, 6);
    s.setEntry(4, 4, 8);
    s.setEntry(4, 5, 2);
    s.setEntry(4, 6, 9);
    s.setEntry(4, 7, 1);
    s.setEntry(4, 8, 5);
    s.setEntry(5, 0, 9);
    s.setEntry(5, 1, 5);
    s.setEntry(5, 2, 1);
    s.setEntry(5, 3, 7);
    s.setEntry(5, 4, 4);
    s.setEntry(5, 5, 3);
    s.setEntry(5, 6, 6);
    s.setEntry(5, 7, 2);
    s.setEntry(5, 8, 8);
    s.setEntry(6, 0, 5);
    s.setEntry(6, 1, 1);
    s.setEntry(6, 2, 9);
    s.setEntry(6, 3, 3);
    s.setEntry(6, 4, 2);
    s.setEntry(6, 5, 6);
    s.setEntry(6, 6, 8);
    s.setEntry(6, 7, 7);
    s.setEntry(6, 8, 4);
    s.setEntry(7, 0, 2);
    s.setEntry(7, 1, 4);
    s.setEntry(7, 2, 8);
    s.setEntry(7, 3, 9);
    s.setEntry(7, 4, 5);
    s.setEntry(7, 5, 7);
    s.setEntry(7, 6, 1);
    s.setEntry(7, 7, 3);
    s.setEntry(7, 8, 6);
    s.setEntry(8, 0, 7);
    s.setEntry(8, 1, 6);
    s.setEntry(8, 2, 3);
    s.setEntry(8, 3, 4);
    s.setEntry(8, 4, 1);
    s.setEntry(8, 5, 8);
    s.setEntry(8, 6, 2);
    s.setEntry(8, 7, 5);
    s.setEntry(8, 8, 9);
}

SudokuMatrix hardSudoku() {
    SudokuMatrix s = SudokuMatrix();
    s.setEntry(0, 4, 9);
    s.setEntry(0, 5, 6);
    s.setEntry(1, 1, 4);
    s.setEntry(1, 3, 2);
    s.setEntry(1, 5, 8);
    s.setEntry(1, 7, 6);
    s.setEntry(2, 3, 7);
    s.setEntry(2, 4, 5);
    s.setEntry(2, 6, 8);
    s.setEntry(2, 8, 2);
    s.setEntry(3, 0, 3);
    s.setEntry(3, 4, 6);
    s.setEntry(4, 3, 3);
    s.setEntry(5, 2, 9);
    s.setEntry(5, 5, 5);
    s.setEntry(5, 6, 6);
    s.setEntry(5, 7, 3);
    s.setEntry(6, 3, 5);
    s.setEntry(6, 4, 3);
    s.setEntry(6, 7, 2);
    s.setEntry(7, 0, 2);
    s.setEntry(7, 1, 5);
    s.setEntry(7, 4, 4);
    s.setEntry(7, 7, 1);
    s.setEntry(8, 0, 6);
    s.setEntry(8, 1, 1);
    s.setEntry(8, 6, 4);
    s.setEntry(8, 8, 5);
    return s;
}

SudokuMatrix masterSudoku() {
    auto s = SudokuMatrix();
    s.setEntry(0, 0, 6);
    s.setEntry(0, 4, 5);
    s.setEntry(1, 3, 2);
    s.setEntry(1, 6, 7);
    s.setEntry(2, 0, 3);
    s.setEntry(2, 1, 4);
    s.setEntry(2, 5, 7);
    s.setEntry(2, 8, 1);
    s.setEntry(3, 2, 2);
    s.setEntry(3, 8, 5);
    s.setEntry(4, 0, 4);
    s.setEntry(4, 1, 5);
    s.setEntry(4, 3, 9);
    s.setEntry(4, 7, 3);
    s.setEntry(5, 2, 6);
    s.setEntry(5, 5, 4);
    s.setEntry(6, 2, 5);
    s.setEntry(7, 0, 7);
    s.setEntry(7, 1, 1);
    s.setEntry(7, 5, 2);
    s.setEntry(7, 8, 3);
    s.setEntry(8, 4, 8);
    s.setEntry(8, 7, 9);
    return s;
}

int main() {
//    auto s = SudokuMatrix();
//    validSudoku(s);
//    auto s2 = hardSudoku();
//    solve(s2);
//    std::cout << s2;
//    auto s = masterSudoku();
//    solve(s);
//    std::cout << s;
    auto s = generateExpert();
    std::cout << s << '\n' << '\n';
    solve(s);
    std::cout << s;
    return 0;
}
