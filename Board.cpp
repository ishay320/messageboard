#include "Board.hpp"
#include "Direction.hpp"
#include <cstdio>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>
using namespace ariel;

/**
 * @brief add a flier to the board
 *
 * @param row
 * @param col
 * @param dir
 * @param s the post
 * x is row and y is col
 */
void Board::post(u_int row, u_int col, Direction dir, std::string s) {
  if (row < 0 || col < 0) { // check for exception
    throw "cant add to minus param";
  }

  if (row + s.length() >= (this->row) ||
      col + s.length() >= (this->col)) { // check for size
    this->resize(
        row > this->row ? row + s.length() + 1 : this->row + s.length(),
        col > this->col ? col + s.length() + 1 : this->col + s.length());
  }
  for (u_int i = 0; i < s.length(); i++) { // add the post
    u_int x = row + (Direction::Vertical == dir ? i : 0);
    u_int y = col + (Direction::Horizontal == dir ? i : 0);
    char c = s.at((unsigned long)i);
    this->mat.at((unsigned long)x).at((unsigned long)y) = c;
  }
}

/**
 * @brief reads a line from the board
 *
 * @param row
 * @param col
 * @param dir
 * @param length
 * @return std::string
 */
std::string Board::read(u_int row, u_int col, Direction dir, u_int length) {

  if (row < 0 || col < 0 || length < 0) { // check for exception
    throw "cant read from minus param";
  }

  std::string post;
  if (row > this->row || col > this->col) { // check if mat is big enough
    for (int i = 0; i < length; i++) {
      post += "_";
    }
    return post;
  }
  if (row + length >= (this->row) ||
      col + length >= (this->col)) { // check for size
    this->resize(row > this->row ? row + length + 1 : this->row + length,
                 col > this->col ? col + length + 1 : this->col + length);
  }
  for (u_int i = 0; i < length; i++) { // add the post to the string
    post += (this->mat.at((row + (Direction::Vertical == dir ? i : 0)))
                 .at((col + (Direction::Horizontal == dir ? i : 0))));
  }
  return post;
}

void Board::show() {
  for (int i = 0; i < this->row; i++) {
    for (int j = 0; j < this->col; j++) {
      std::cout << this->mat.at((unsigned long)i).at((unsigned long)j);
    }
    std::cout << std::endl;
  }
}

/**
 * @brief Construct a new Board:: Board object
 *  defult is define in hpp file
 */
Board::Board() {
  std::vector<std::vector<char>> vec(SIZE_MAT_START,
                                     std::vector<char>(SIZE_MAT_START, '_'));
  this->mat = vec;
  this->row = SIZE_MAT_START;
  this->col = SIZE_MAT_START;
}

/**
 * @brief resize the mat to the spec params
 *
 * @param row
 * @param col
 */
void Board::resize(u_int row, u_int col) {
  if (row < 0 || col < 0) { // check for exception
    throw "cant resize to minus param";
  }
  std::vector<std::vector<char>> vec(
      (unsigned long)row, std::vector<char>((unsigned long)col, '_'));
  for (int i = 0; i < this->row; ++i) {
    for (int j = 0; j < this->col; ++j) {
      vec.at((unsigned long)i).at((unsigned long)j) =
          this->mat.at((unsigned long)i).at((unsigned long)j);
    }
  }
  this->mat = vec;
  this->row = row;
  this->col = col;
}
