#include <iostream>
#include <sstream>
#include <regex>
#include "back.h"
#include "matrix.h"
#include <memory>

#define BUFF 200

/*
Matches an incominng string where: 
-[+-]? means optional +- signs for +ve and -ve nums -
-[0-9]+([.][0-9]*)?) matches nums that are either 0.1, 1, 1.0  and -minus as well returns true
-[.][0-9]+ matches nums .12 as 0.12 and will return true
*/

bool is_double(const std::string &num) {
  return std::regex_match(num, std::regex("[+-]?([0-9]+([.][0-9]*)?|[.][0-9]+)"));
}

bool is_integer(const std::string &num) {
  return std::regex_match(num, std::regex("[+-]?[0-9]+"));
}



bool parse_numbers(const std::string &input, std::unique_ptr<double[]>& numbers, int rows, int cols, int &last_index, int &i) {
  std::unique_ptr<double[]> temp_nums = std::make_unique<double[]>(rows*cols + BUFF);
  std::istringstream iss(input);
  std::string token;
  int counter = 0;
  bool double_f = false;


  while (iss >> token && counter < rows*cols + BUFF) {
    if (is_double(token)) {
      temp_nums[counter] = std::stod(token);
      counter++;
    } 
    else {err("Invalid number"); double_f = true;}
    }
  if(counter != cols){err("Invalid number of inputs\n"); i = -1; return false;}

  if(!double_f){
    for(int i = 0; i < rows*cols; i++){numbers[last_index + i] = temp_nums[i];}
    last_index += cols; 
    return true;
  }
      
  return false;
}


Matrix def_mat(int rows, int cols){
  Matrix mat(rows, cols);
  std::unique_ptr<double[]> numbers = std::make_unique<double[]>(rows*cols);
  int last_index = 0;
  bool parse_flag = false;
  do{
    for(int iter = 0; iter < rows; iter++){
      std::string row;
      std::cout << "\nEnter row " << iter + 1 << " values\n";
      std::getline(std::cin, row);
      parse_flag = parse_numbers(row, numbers, rows, cols, last_index, iter);
    }
  }
  while(!parse_flag);

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      mat.set_index(i,j,numbers[i * cols + j]);
    }
  }

  mat.display();

  return mat;
}

void tokenize(std::string &msg){
  std::istringstream iss(msg);
  while(iss >> msg);
}

bool map_check(const std::string &msg, std::shared_ptr<std::unordered_map<std::string, Matrix>> &map){
  auto it = map->find(msg);
  return it != map->end(); // If key exists return true
}




void define_matrix_mo(std::shared_ptr<std::unordered_map<std::string, Matrix>> &map) {
  if(!map){err("MAP is NULL"); return;}
  int row, col;
  std::string row_string , col_string;
  bool valid_row = false;
  bool valid_col = false;
  bool flag = false;
  std::string mat_name;
  do{
    std::cout << "\nEnter a Matrix name (This will include all characters entered including white spaces)\n";
    std::cin.ignore();
    std::getline(std::cin, mat_name);
    flag = map_check(mat_name, map);
  }
  while(flag);  

  do {
    std::cout << "\nEnter number of rows: ";
    std::getline(std::cin, row_string);
    tokenize(row_string);
    std::cout << "\nEnter number of cols: ";
    std::getline(std::cin, col_string);
    tokenize(col_string);
    valid_row = is_integer(row_string);
    valid_col = is_integer(col_string);
    // if input is not an integer, print an error message
    if (!valid_col || !valid_row) {err("Enter an integer for the rows and columns");} 
    else {  // if it is an int, check whether in range
      row = std::stoi(row_string);  // convert to int
      col = std::stoi(col_string);
    }
  } while (!valid_row || !valid_col);

  Matrix mat = def_mat(row, col);

  (*map)[mat_name] = mat;
}


void err(const std::string &msg){
  std::cerr << "ERROR: " << msg << std::endl;
}


void log(const std::string &msg){
  std::clog << "LOG: " << msg << std::endl;
}


