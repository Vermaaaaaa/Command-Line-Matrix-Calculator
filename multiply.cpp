#include "multiply.h"
#include "matrix.h"
#include <iostream>

/*bool is_c(const Matrix &mat1, const Matrix &mat2 ){
    if (mat1.get_col() == mat2.get_row()){
        return true;
    }
    return false;

}*/

void multiply(std::shared_ptr<std::unordered_map<std::string, Matrix>> &map){ //Shared map for the matrices that have been inputted
    Matrix mat1, mat2;
    bool found_flag1 = false;
    bool found_flag2 = false;
    do{
        mat1 = select(map, found_flag1);
        mat2 = select(map, found_flag2);
    }
    while(!found_flag1 || !found_flag2); // Carry on only if both matrices are found

    if (mat1.get_col() != mat2.get_row()){ // Conformable check
        std::cout << "Matrices are not conformable and cannot be multiplied" << std::endl;
        return;
    }

    Matrix mult_mat(mat1.get_row(), mat2.get_col()); // The size of answer will be the amount of rows from mat1 and columns from mat2
    for (int i = 0; i < mat1.get_row(); ++i) {
        for (int j = 0; j < mat2.get_col(); ++j) {
            double mult_ans = 0.0;
            for (int k = 0; k < mat1.get_col(); ++k) {
                mult_ans += mat1.get_index(i, k) * mat2.get_index(k, j); // Matrix multiplication iteration sequence
            }
            mult_mat.set_index(i, j, mult_ans); // Set new index values to answer
        }        
    }
    mult_mat.display(); // Call display function to show answer
    
    bool save_flag = false; // Run through save sequence
    do{
        std::string choice;
        std::cout << "\nWould you like to save this matrix (Y/N)";
        std::cin >> choice;
        if(choice == "N"){save_flag = true;}
        if(choice == "Y"){matrix_save(map, mult_mat); save_flag = true;}
    }
    while(!save_flag);
}
