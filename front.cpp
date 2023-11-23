
#include <iostream>
#include <stdexcept>
#include "back.h"
#include "matrix.h"
#include <unordered_map>
#include <memory>


void main_menu();
int get_user_input();
void select_menu_item(int input, std::shared_ptr<std::unordered_map<std::string, Matrix>> &map);
void print_main_menu();
void go_back_to_main();



int main(int argc, char const *argv[]) {
  (void) argc;
  (void) argv;


  main_menu();

  return 0;
}

void main_menu() {
  std::shared_ptr<std::unordered_map<std::string, Matrix>> map = std::make_shared<std::unordered_map<std::string, Matrix>>();
  print_main_menu();
  int input = get_user_input();
  select_menu_item(input, map);
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

void select_menu_item(int input,std::shared_ptr<std::unordered_map<std::string, Matrix>> &map) {
  switch (input) {
    case 1:
      define_matrix_mo(map);
      go_back_to_main();
      break;
    case 2:
      //add();
      go_back_to_main();
      break;
    case 3:
      //subtract();
      go_back_to_main();
      break;
    case 4:
      invert();
      go_back_to_main();
      break;
    case 5:
      determinant();
      go_back_to_main();
      break;
    default:
      exit(1);
      break;
  }
}

void print_main_menu() {
  std::cout << "\n----------- Main menu -----------\n";
  std::cout << "|\t\t\t\t\t\t|\n";
  std::cout << "|\t1. Define Matrix\t\t|\n";
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


