#ifndef BACK_H
#define BACK_H

#include <string>


bool is_double(const std::string &num);
bool is_integer(std::string num);

bool parse_numbers(const std::string &input, double *numbers);

void addition();
void subtraction();
void division();
void multiplication();

void err(const std::string &msg);
void log(const std::string &msg);

float to_float(const std::string& str);

#endif