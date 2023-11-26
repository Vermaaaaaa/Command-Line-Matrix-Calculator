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
    Matrix(int rows, int cols);

    //Mutators
    int set_index(int row, int col, double value);
    void set_matrix();
    int set_row(int row_no, double value);


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


void determinant(std::shared_ptr<std::unordered_map<std::string, Matrix>> &map);
void add(std::shared_ptr<std::unordered_map<std::string, Matrix>> &map);
void subtract(std::shared_ptr<std::unordered_map<std::string, Matrix>> &map);
void multiply();

void matrix_save(std::shared_ptr<std::unordered_map<std::string, Matrix>> &map, const Matrix &mat);



Matrix select(const std::shared_ptr<std::unordered_map<std::string, Matrix>> &map, bool &found_flag);

void will();
void angus();
void rahul();

#endif