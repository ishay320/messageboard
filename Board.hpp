#pragma once
#include "Direction.hpp"
#include <string>
#include <sys/types.h>
#include <vector>
#define SIZE_MAT_START 64
namespace ariel {
class Board {
private:
  std::vector<std::vector<char>> mat;
  u_int row;
  u_int col;

public:
  Board();
  void post(u_int row, u_int col, ariel::Direction dir, std::string);
  std::string read(u_int row, u_int col, ariel::Direction dir, u_int length);
  void show();
  void resize(u_int row, u_int col);
};
} // namespace ariel