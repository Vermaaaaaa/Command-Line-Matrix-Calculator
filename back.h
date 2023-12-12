#ifndef BACK_H
#define BACK_H

#include <string>
#include "matrix.h"
#include <memory>
#include <unordered_map>


bool is_double(const std::string &num);
bool is_integer(const std::string &num);

bool parse_numbers(const std::string &input, std::unique_ptr<double[]> &numbers, int rows, int cols, int &last_index, int &i);

void define_matrix_mo(std::shared_ptr<std::unordered_map<std::string, Matrix>> &map);

void err(const std::string &msg);
void log(const std::string &msg);


Matrix def_mat(int rows, int cols);

float to_float(const std::string& str);

bool map_check(const std::string &msg, const std::shared_ptr<std::unordered_map<std::string, Matrix>> &map);
void tokenize(std::string &msg);

#endif