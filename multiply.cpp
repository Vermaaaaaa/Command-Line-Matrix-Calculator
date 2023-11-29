#include "multiply.h"
#include "matrix.h"
#include "back.h"
#include <iostream>

/*bool is_c(const Matrix &mat1, const Matrix &mat2 ){
    if (mat1.get_col() == mat2.get_row()){
        return true;
    }
    return false;

}*/

void multiply(std::shared_ptr<std::unordered_map<std::string, Matrix>> &map){
    Matrix mat1, mat2;
    bool found_flag1 = false;
    bool found_flag2 = false;
    do{
        mat1 = select(map, found_flag1);
        mat2 = select(map, found_flag2);
    }
    while(!found_flag1 || !found_flag2);

    if (mat1.get_col() == mat2.get_row()){
        std::cout << "Matrices are not conformable and cannot be multiplied" << std::endl;
        
    }
}
