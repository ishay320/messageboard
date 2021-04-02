#include "Board.hpp"
#include "Direction.hpp"
#include "doctest.h"
#include <iostream>

using namespace std;
using ariel::Direction;

TEST_CASE("empty cases") {
  ariel::Board board;
  CHECK(board.read(0, 0, Direction::Horizontal, 0) == "");
  CHECK(board.read(0, 0, Direction::Vertical, 0) == "");
  CHECK(board.read(0, 0, Direction::Horizontal, 1) == "_");
  CHECK(board.read(0, 0, Direction::Vertical, 1) == "_");
  CHECK(board.read(100, 100, Direction::Horizontal, 0) == "");
  CHECK(board.read(100, 100, Direction::Vertical, 0) == "");
  CHECK(board.read(100, 100, Direction::Horizontal, 1) == "_");
  CHECK(board.read(100, 100, Direction::Vertical, 1) == "_");
}
TEST_CASE("good cases") {
  ariel::Board board;
  board.post(100, 200, Direction::Horizontal, "abcd");
  CHECK(board.read(100, 200, Direction::Horizontal, 4) == "abcd");
  CHECK(board.read(99, 201, Direction::Vertical, 3) == "_b_");

  board.post(100, 200, Direction::Horizontal, "efgh");
  CHECK(board.read(100, 200, Direction::Horizontal, 4) == "efgh");
  CHECK(board.read(99, 201, Direction::Vertical, 3) == "_f_");

  board.post(99, 202, Direction::Vertical, "xyz");
  CHECK(board.read(99, 202, Direction::Vertical, 3) == "xyz");
  CHECK(board.read(100, 200, Direction::Horizontal, 6) == "efyh__");
}
TEST_CASE("bad cases") {
  ariel::Board board;
  CHECK_THROWS(board.post(-1, 0, Direction::Horizontal, "abcd"));
  CHECK_THROWS(board.post(0, -1, Direction::Horizontal, "abcd"));
  CHECK_THROWS(board.post(-1, -1, Direction::Horizontal, "abcd"));

  CHECK_THROWS(board.read(-1, 0, Direction::Horizontal, 4));
  CHECK_THROWS(board.read(0, -1, Direction::Horizontal, 4));
  CHECK_THROWS(board.read(-1, -1, Direction::Horizontal, 4));
  CHECK_THROWS(board.read(0, 0, Direction::Horizontal, -1));
  CHECK_THROWS(board.read(-1, 0, Direction::Horizontal, -1));
  CHECK_THROWS(board.read(0, -1, Direction::Horizontal, -1));
  CHECK_THROWS(board.read(-1, -1, Direction::Horizontal, -1));
}
