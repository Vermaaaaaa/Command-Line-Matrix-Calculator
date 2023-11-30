#ifndef MULTIPLY_H
#define MULTIPLY_H
#include <memory>
#include "matrix.h"

void multiply(std::shared_ptr<std::unordered_map<std::string, Matrix>> &map);

#endif