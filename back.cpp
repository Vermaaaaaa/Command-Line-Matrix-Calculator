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

//Original is_integer from CLI 
bool is_integer(const std::string &num) {
  return std::regex_match(num, std::regex("[+-]?[0-9]+"));
}


// Takes a input from the user and appends this input to an array
bool parse_numbers(const std::string &input, std::unique_ptr<double[]>& numbers, int rows, int cols, int &last_index, int &i) {
  std::unique_ptr<double[]> temp_nums = std::make_unique<double[]>(rows*cols + BUFF); //Initalises a temp_array to store our read in values
  std::istringstream iss(input); //Creates istringstream object iss with a constructor being our string
  std::string token; // Initalise variable to hold our tokens
  int counter = 0;
  bool double_f = false;

  //While the iss object encounters an string without whitespace and the counter is not greater than our temp array
  while (iss >> token && counter < rows*cols + BUFF) {
    if (is_double(token)) { //Check if the token from the user is a double and append it to the temp array at a counter
      temp_nums[counter] = std::stod(token);
      counter++;
    } 
    else {err("Invalid number"); double_f = true;} // Else say that within the string there are invalid inputs and return false from the function
    }
  if(counter != cols){err("Invalid number of inputs\n"); i = -1; return false;} //If the counter does not = the number of cols the string passed in must not have enough numbers

  if(!double_f){
    for(int i = 0; i < rows*cols; i++){numbers[last_index + i] = temp_nums[i];}
    last_index += cols; 
    return true;
    //If flag stays false we append the temp array to our matrix array starting at the last index of the current array and increment index by number of columns
  }
      
  return false;
}


Matrix def_mat(int rows, int cols){
  Matrix mat(rows, cols); // Defines a matrix of size rows cols 
  std::unique_ptr<double[]> numbers = std::make_unique<double[]>(rows*cols); //Allocates a double array on the heap of size rows*col which is the size of our matrix
  int last_index = 0; // Keeps track of the last index of the array 
  bool parse_flag = false; //Keeps track to see if parse_numbers is returning false
  do{
    for(int iter = 0; iter < rows; iter++){
      std::string row;
      std::cout << "\nEnter row " << iter + 1 << " values\n";
      std::getline(std::cin, row);
      //Asks user to enter a row of numbers 
      parse_flag = parse_numbers(row, numbers, rows, cols, last_index, iter);
    }
  }
  while(!parse_flag);

//Takes the numbers from the heap allocated array and sets them into a matrix object
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      mat.set_index(i,j,numbers[i * cols + j]);
    }
  }

  mat.display();

  return mat;
}

//Tokenises our string so our string is returned as a string with no white spaces 
void tokenize(std::string &msg){
  std::istringstream iss(msg);
  while(iss >> msg);
}


//Check if the key currently exists in the map otherwise return false
bool map_check(const std::string &msg, std::shared_ptr<std::unordered_map<std::string, Matrix>> &map){
  auto it = map->find(msg);
  return it != map->end(); // If key exists return true
}




void define_matrix_mo(std::shared_ptr<std::unordered_map<std::string, Matrix>> &map) {
  //Checks if map is null and ends function if so 
  if(!map){err("MAP is NULL"); return;}
  int row, col;
  std::string row_string , col_string;
  bool valid_row = false;
  bool valid_col = false;
  bool flag = false;
  std::string mat_name;
  //Enter a map namen from the user and repeats until a unique a matrix name is entered
  do{
    std::cout << "\nEnter a Matrix name (This will include all characters entered including white spaces)\n";
    std::cin.ignore();
    std::getline(std::cin, mat_name);
    flag = map_check(mat_name, map);
  }
  while(flag);  

  do {
    //Takes an iteger for rows and cols and checks if they are integers, repeats until both are integers
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


  //Adds to our map the name and matrix to be accessed elsewhere
  (*map)[mat_name] = mat;
}

//Used for Error and Logging 
void err(const std::string &msg){
  std::cerr << "ERROR: " << msg << std::endl;
}


void log(const std::string &msg){
  std::clog << "LOG: " << msg << std::endl;
}


