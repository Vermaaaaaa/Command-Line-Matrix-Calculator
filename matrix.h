#include <vector>
#include <unordered_map>
#include <stdio.h>
#include <memory>
#include <string>


#ifndef MATRIX_H
#define MATRIX_H

class Matrix{
    public:
    //Constructors
    Matrix();
    Matrix(const int rows,const int cols);

    //Mutators
    int set_index(int row, int col, double value); //takes the rows and columns of the index to be modified and the value to change it to and changes that index to inputted value
    int set_row(int row, double row_vals[]); //change the values stored in the rows array
    int set_col(int col, double col_vals[]); //change the values stored in a column by acessing a specific index of each rows array


    //Accessors 
    double get_index(int row, int col) const; //takes the inputted location in rows and cols and returns the index's value
    int get_row() const; //returns number of rows
    int get_col() const;  //returns number of columns
  

    void display() const; //prints matrix to console

    bool is_square(); //if matrix is square return true
    int size() const; //number of indexs
    void swap_rows(int row1, int row2); //swap rows used gaussian elimination




    private:
    std::vector<std::vector<double>> mat; // 2D vector to store matrix elements
    int _rows;
    int _cols;

          
};


void determinant(const std::shared_ptr<std::unordered_map<std::string, Matrix>> &map);
void add(std::shared_ptr<std::unordered_map<std::string, Matrix>> &map);
void subtract(std::shared_ptr<std::unordered_map<std::string, Matrix>> &map);

void matrix_save(std::shared_ptr<std::unordered_map<std::string, Matrix>> &map, const Matrix &mat);




Matrix select(const std::shared_ptr<std::unordered_map<std::string, Matrix>> &map, bool &found_flag);


#endif