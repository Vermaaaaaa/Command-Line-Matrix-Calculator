
#include <iostream>
#include <stdexcept>
#include "back.h"
#include "matrix.h"
#include <unordered_map>
#include <memory>
#include <iomanip>



void main_menu(std::shared_ptr<std::unordered_map<std::string, Matrix>> &map);
int get_user_input();
void select_menu_item(int input, std::shared_ptr<std::unordered_map<std::string, Matrix>> &map);
void print_main_menu();
void go_back_to_main(std::shared_ptr<std::unordered_map<std::string, Matrix>> &map);
void display_map(std::shared_ptr<std::unordered_map<std::string, Matrix>> &map);



int main(int argc, char const *argv[]) {
  (void) argc;
  (void) argv;

  //Allocates a map on the heap as we need the map to persist throughout the entire program
  std::shared_ptr<std::unordered_map<std::string, Matrix>> map = std::make_shared<std::unordered_map<std::string, Matrix>>();


  main_menu(map);

  return 0;
}

//Prints main menu frontend to the user and starts dealing with user inputs
void main_menu(std::shared_ptr<std::unordered_map<std::string, Matrix>> &map) {
  print_main_menu();
  int input = get_user_input();
  select_menu_item(input,map);
}



int get_user_input() {
  int input;
  std::string input_string;
  bool valid_input = false;
  int menu_items = 7;


  do {
    std::cout << "\nSelect item: ";
    std::cin >> input_string;
    //If input is a b or B due to back the function does not return an erro 
    if(input_string == "b" || input_string == "B"){return 0; valid_input = true;}
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

//Switch inputs for each menu item and returns back to the main menu

void select_menu_item(int input, std::shared_ptr<std::unordered_map<std::string, Matrix>> &map) {
  switch (input) {
    case 1:
      define_matrix_mo(map);
      go_back_to_main(map);
      break;
    case 2:
      display_map(map);
      go_back_to_main(map);
      break;
    case 3:
      add(map);
      go_back_to_main(map);
      break;
    case 4:
      subtract(map);
      go_back_to_main(map);
      break;
    case 5:
      //Multiply matrix
      go_back_to_main(map);
      break;
    case 6:
      //determinant();
      go_back_to_main(map);
      break;
    case 7:
      exit(1);
      system("cls");
      break;
    default:
      break;
  }
}

//Main Menu design

void print_main_menu() {
  std::cout << "\n----------- Main menu -----------\n";
  std::cout << "|\t" << std::setw(27) << "|\n";
  std::cout << "|\t1. Define Matrix" << std::setw(11) << "|\n";
  std::cout << "|\t2. Display Matrices" << std::setw(8) << "|\n";
  std::cout << "|\t3. Add Matrices" << std::setw(12) << "|\n";
  std::cout << "|\t4. Subtract Matrices" << std::setw(7) << "|\n";
  std::cout << "|\t5. Multiply Matrices" << std::setw(7) << "|\n";
  std::cout << "|\t6. Det of Matrix" << std::setw(11) << "|\n";
  std::cout << "|\t7. Exit" << std::setw(20) << "|\n";
  std::cout << "|\t" << std::setw(27) << "|\n";
  std::cout << "---------------------------------\n";
}


//Uses b or B to return to the main menu

void go_back_to_main(std::shared_ptr<std::unordered_map<std::string, Matrix>> &map) {
  std::string input;
  do {
    std::cout << "\nEnter 'b' or 'B' to go back to main menu: ";
    std::cin >> input;
  } while (input != "b" && input != "B");
  main_menu(map);
}



void display_map(std::shared_ptr<std::unordered_map<std::string, Matrix>> &map){
  if(!map){err("NULL Map"); return;} //Checks if map is empty
  for (auto it = map->begin(); it != map->end(); it++){ // Using an iterator, iterates through the map extracting key value pairs to be displayed
    const std::string& key = it->first;
    const Matrix& mat = it->second;

    //Displays Matrix name and Value
    std::cout << "Name: " << key << std::endl;
    std::cout << "Matrix:" << std::endl;
    mat.display();

    std::cout << "----------------------" << std::endl;
    }
}

