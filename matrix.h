#include <vector>
#include <stdio.h>


#ifndef MATRIX_H
#define MATRIX_H

class Matrix{
    public:
    //Constructor
    Matrix(int rows, int cols);

    //Mutators
    int set_index(int row, int col, double value);
    void set_matrix();

    //Accessors 
    double get_index(int row, int col) const;
    int get_row() const;
    int get_col() const;
    void get_matrix();

    void display() const;

    bool is_square();
    int size() const;

    private:
    std::vector<std::vector<double>> mat; // 2D vector to store matrix elements
    int _rows;
    int _cols;
    double _det;
          
};


void determinant();
void add(const Matrix &mat1, const Matrix &mat2);
void subtract(const Matrix &mat1, const Matrix &mat2);
void invert();
//void set_row(int row_no, int value);
//void set_column();
//void matrix_convert();

void will();

#endif