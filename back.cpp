#include <iostream>
#include <sstream>
#include <regex>
#include "back.h"
#include "matrix.h"
#include <memory>

#define MAX_LENGTH 200

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



bool parse_numbers(const std::string &input, std::unique_ptr<double[]>& numbers, int rows, int cols, int &last_index) {
    std::unique_ptr<double[]> temp_nums = std::make_unique<double[]>(rows*cols);
    std::istringstream iss(input);
    std::string token;
    int counter = 0;
    bool double_f = false;

    while (iss >> token && counter < rows*cols && !double_f) {
        if (is_double(token)) {
          temp_nums[counter] = std::stod(token);
          counter++;
        } 
        else {err("Invalid number"); double_f = true;}
    }

    if(!double_f){
      for(int i = 0; i < rows*cols; i++){numbers[last_index + i] = temp_nums[i];}
      last_index += counter; 
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
    for(int i = 0; i < rows; i++){
      std::string row;
      std::cout << "\nEnter row " << i + 1 << " values\n";
      std::getline(std::cin, row);
      parse_flag = parse_numbers(row, numbers, rows, cols, last_index);
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





void define_matrix_mo(std::shared_ptr<std::unordered_map<std::string, Matrix>> &map) {
  int row, col;
  std::string row_string , col_string;
  bool valid_row = false;
  bool valid_col = false;
  std::cout << "Enter the matrix name (This is case and whitespace dependent)\n";
  std::string mat_name;
  std::getline(std::cin, mat_name);



  do {
    std::cout << "\nEnter number of rows: ";
    std::getline(std::cin, row_string);
    std::cout << "\nEnter number of cols: ";
    std::getline(std::cin, col_string);
    valid_row = is_integer(row_string);
    valid_col = is_integer(col_string);
    // if input is not an integer, print an error message
    if (!valid_col || !valid_row) {
      err("Enter an integer for the rows and columns");
    } else {  // if it is an int, check whether in range
      row = std::stoi(row_string);  // convert to int
      col = std::stoi(col_string);

    }
  } while (!valid_row || !valid_col);


  Matrix mat = def_mat(row,col);

  (*map)[mat_name] = mat;
  

}


void subtraction() {
  log("Subtraction Selected");
  std::cout << "\nEnter 2 values\n";
  std::string val_1;
  std::string val_2;
  do{
    std::cin >> val_1;
    std::cin >> val_2;
    if(!is_double(val_1) || !is_double(val_2)){err("Invalid Data, try again");}
  }
  while(!is_double(val_1) || !is_double(val_2));

  float tval_1 = std::stod(val_1);
  float tval_2 = std::stod(val_2);

  std::cout << "Output: " << tval_1 - tval_2 << std::endl;
  
}


void division() {
  log("Division Selected");
  std::cout << "\nEnter 2 values\n";
  std::string val_1;
  std::string val_2;
  do{
    std::cin >> val_1;
    std::cin >> val_2;
    if(!is_double(val_1) || !is_double(val_2)){err("Invalid Data, try again");}
  }
  while(!is_double(val_1) || !is_double(val_2));

  //float tval_1 = to_double(val_1);
  //float tval_2 = to_double(val_2);

  //std::cout << "Output: " << tval_1 / tval_2 << std::endl;
}


void multiplication() {
  log("Multiplication Selected");
  std::cout << "\nEnter 2 values\n";
  std::string val_1;
  std::string val_2;
  do{
    std::cin >> val_1;
    std::cin >> val_2;
    if(!is_double(val_1) || !is_double(val_2)){err("Invalid Data, try again");}
  }
  while(!is_double(val_1) || !is_double(val_2));

  //float tval_1 = to_double(val_1);
  //float tval_2 = to_double(val_2);

  //std::cout << "Output: " << tval_1 * tval_2 << std::endl;
}


void err(const std::string &msg){
  std::cerr << "ERROR: " << msg << std::endl;
}


void log(const std::string &msg){
  std::clog << "LOG: " << msg << std::endl;
}


