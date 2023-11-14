#include "matrix.h"
#include <iostream>
#include <regex>
#include <stdexcept>


void main_menu();
int get_user_input();
void select_menu_item(int input);
void print_main_menu();
void go_back_to_main_menu();
bool is_integer(std::string num);
void addition();
void subtraction();
void division();
void multiplication();

void err(const std::string msg);
void log(const std::string msg);

bool isFloat(const std::string& s);
float to_float(const std::string& str);

int main(int argc, char const *argv[]) {
  (void) argc;
  (void) argv;

  main_menu();
  return 0;
}

void main_menu() {
  print_main_menu();
  int input = get_user_input();
  select_menu_item(input);
}

int get_user_input() {
  int input;
  std::string input_string;
  bool valid_input = false;
  int menu_items = 5;

  do {
    std::cout << "\nSelect item: ";
    std::getline(std::cin, input_string);
    valid_input = is_integer(input_string);
    // if input is not an integer, print an error message
    if (!valid_input) {
      err("Enter an integer");
    } else {  // if it is an int, check whether in range
      input = std::stoi(input_string);  // convert to int
      if (input >= 1 && input <= menu_items) {
        valid_input = true;
      } else {
        err("Invalid menu item!");
        valid_input = false;
      }
    }
  } while (!valid_input);

  return input;
}

void select_menu_item(int input) {
  switch (input) {
    case 1:
      addition();
      break;
    case 2:
      subtraction();
      break;
    case 3:
      division();
      break;
    case 4:
      multiplication();
      break;
    default:
      exit(1);
      break;
  }
}

void print_main_menu() {
  std::cout << "\n----------- Main menu -----------\n";
  std::cout << "|\t\t\t\t\t\t|\n";
  std::cout << "|\t1. Addition\t\t|\n";
  std::cout << "|\t2. Subtraction\t\t|\n";
  std::cout << "|\t3. Division\t\t|\n";
  std::cout << "|\t4. Multiplication\t\t|\n";
  std::cout << "|\t5. Exit\t\t\t\t|\n";
  std::cout << "|\t\t\t\t\t\t|\n";
  std::cout << "---------------------------------\n";
}

void go_back_to_main() {
  std::string input;
  do {
    std::cout << "\nEnter 'b' or 'B' to go back to main menu: ";
    std::cin >> input;
  } while (input != "b" && input != "B");
  main_menu();
}

// https://codereview.stackexchange.com/questions/162569/checking-if-each-char-in-a-string-is-a-decimal-digit
bool is_integer(std::string num) {
  return std::regex_match(num, std::regex("[+-]?[0-9]+"));
}




void addition() {
  log("Addition Selected");
  std::cout << "\nEnter 2 values\n";
  std::string val_1;
  std::string val_2;
  do{
    std::cin >> val_1;
    std::cin >> val_2;
    if(!isFloat(val_1) || !isFloat(val_2)){err("Invalid Data, try again");}
  }
  while(!isFloat(val_1) || !isFloat(val_2));

  float tval_1 = to_float(val_1);
  float tval_2 = to_float(val_2);

  std::cout << "Output: " << tval_1 + tval_2 << std::endl;
  go_back_to_main();
}
void subtraction() {
  log("Subtraction Selected");
  std::cout << "\nEnter 2 values\n";
  std::string val_1;
  std::string val_2;
  do{
    std::cin >> val_1;
    std::cin >> val_2;
    if(!isFloat(val_1) || !isFloat(val_2)){err("Invalid Data, try again");}
  }
  while(!isFloat(val_1) || !isFloat(val_2));

  float tval_1 = to_float(val_1);
  float tval_2 = to_float(val_2);

  std::cout << "Output: " << tval_1 - tval_2 << std::endl;
  go_back_to_main();
}
void division() {
  log("Division Selected");
  std::cout << "\nEnter 2 values\n";
  std::string val_1;
  std::string val_2;
  do{
    std::cin >> val_1;
    std::cin >> val_2;
    if(!isFloat(val_1) || !isFloat(val_2)){err("Invalid Data, try again");}
  }
  while(!isFloat(val_1) || !isFloat(val_2));

  float tval_1 = to_float(val_1);
  float tval_2 = to_float(val_2);

  std::cout << "Output: " << tval_1 / tval_2 << std::endl;
  go_back_to_main();
}
void multiplication() {
  log("Multiplication Selected");
  std::cout << "\nEnter 2 values\n";
  std::string val_1;
  std::string val_2;
  do{
    std::cin >> val_1;
    std::cin >> val_2;
    if(!isFloat(val_1) || !isFloat(val_2)){err("Invalid Data, try again");}
  }
  while(!isFloat(val_1) || !isFloat(val_2));

  float tval_1 = to_float(val_1);
  float tval_2 = to_float(val_2);

  std::cout << "Output: " << tval_1 * tval_2 << std::endl;
  go_back_to_main();
}

void err(const std::string msg){
  std::cerr << "ERROR: " << msg << std::endl;
}

void log(const std::string msg){
  std::clog << "LOG: " << msg << std::endl;
}

bool isFloat(const std::string& s) {
    try {
        std::stof(s);
    } catch (...) {
        return false;
    }
    return typeid(std::stof(s)) == typeid(float);
}


float to_float(const std::string& str){
      try {
        // Convert string to float
        return std::stof(str);

    } catch (const std::invalid_argument& ia) {
        std::cerr << "Invalid argument: " << ia.what() << std::endl; // Catch Invalid Arg
    } catch (const std::out_of_range& oor) {
        std::cerr << "Out of range: " << oor.what() << std::endl; // Catch out of range
    }
    return -1;
}