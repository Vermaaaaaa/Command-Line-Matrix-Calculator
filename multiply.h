#ifndef MULTIPLY_H
#define MULTIPLY_H
#include <memory>
#include "matrix.h"

void multiply(std::shared_ptr<std::unordered_map<std::string, Matrix>> &map);
bool multiply2(const Matrix &mat1,const Matrix &mat2);

#endif