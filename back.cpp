#include <iostream>
#include <sstream>
#include <regex>
#include "back.h"
#include "matrix.h"

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

double to_double(const std::string& str){
    
}

bool parse_numbers(const std::string &input, double *numbers) {
    double temp_nums[MAX_LENGTH];
    std::istringstream iss(input);
    std::string token;
    int counter = 0;
    bool double_f = false;

    while (iss >> token && counter < MAX_LENGTH && !double_f) {
        if (is_double(token)) {
                temp_nums[counter] = std::stod(token);
                counter++;
        } 
        else {err("Invalid number"); double_f = true;}
    }
    if(!double_f){numbers = temp_nums; return true;}
    return false;

}


void addition() {
  log("Addition Selected");
  double numbers[MAX_LENGTH];
  std::cout << "\nEnter the first row values\n";
  std::string row;
  do{
    std::getline(std::cin, row);
    parse_numbers(row, numbers);
  }
  while(!parse_numbers(row, numbers));



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

  float tval_1 = to_double(val_1);
  float tval_2 = to_double(val_2);

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

  float tval_1 = to_double(val_1);
  float tval_2 = to_double(val_2);

  std::cout << "Output: " << tval_1 / tval_2 << std::endl;
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

  float tval_1 = to_double(val_1);
  float tval_2 = to_double(val_2);

  std::cout << "Output: " << tval_1 * tval_2 << std::endl;
}


void err(const std::string &msg){
  std::cerr << "ERROR: " << msg << std::endl;
}


void log(const std::string &msg){
  std::clog << "LOG: " << msg << std::endl;
}


