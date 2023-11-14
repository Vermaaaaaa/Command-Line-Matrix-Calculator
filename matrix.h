#include <vector>



#ifndef MATRIX_H
#define MATRIX_H

class Matrix{
    public:
    //Constructor
    Matrix(int rows, int cols, int choice);

    //Mutators
    void set_index(int row, int col, int value);
    void set_matrix();

    //Accessors 
    void get_index();
    void get_row();
    void get_column();
    void get_matrix();

    private:
    std::vector<std::vector<int>> mat; // 2D vector to store matrix elements
    int _rows;
    int _cols;
          
};


void determinant();
void add();
void subtract();
void invert();

//void set_row(int row_no, int value);
//void set_column();
//void matrix_convert();

#endif