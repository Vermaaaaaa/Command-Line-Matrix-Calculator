#include <cassert>
#include "multiply.h"
#include "matrix.h"
#include <iostream>

int main(){
    Matrix mat1(2,2), mat2(2,2), mat3(2,2), mat4(2,2);

    mat1.set_index(0,0,2);
    mat1.set_index(0,1,4);
    mat1.set_index(1,0,6);
    mat1.set_index(1,1,8);

    
    mat2.set_index(0,0,3);
    mat2.set_index(0,1,4);
    mat2.set_index(1,0,6);
    mat2.set_index(1,1,5);

    mat3 = multiply2(mat1,mat2);
    mat4 = multiply2(mat1,mat2);

    assert(mat3.get_index(0, 0) == 5);
    assert(mat3.get_index(0, 1) == 8);
    assert(mat3.get_index(1, 0) == 12);
    assert(mat3.get_index(1, 1) == 13);
    
    // If any of these assertions fail, the program will terminate with an error.

    // Additional checks, you might want to verify the size of the matrices.
    assert(mat3.get_row() == 2);
    assert(mat3.get_col() == 2);

    assert(mat4.get_index(0, 0) == -1);
    assert(mat4.get_index(0, 1) == 0);
    assert(mat4.get_index(1, 0) == 0);
    assert(mat4.get_index(1, 1) == 3);

    // If any of these assertions fail, the program will terminate with an error.

    // Additional checks, you might want to verify the size of the matrices.
    assert(mat4.get_row() == 2);
    assert(mat4.get_col() == 2);

    std::cout << "All tests passed" << std::endl;

    return 0;
}



/*bool test_mult(const Matrix &mat1, const Matrix &mat2, const Matrix expected){
    std::cout << "mult(" << mat1 << "," << mat2 << ") : ";
    ans = multiply(std::shared_ptr<std::unordered_map<std::string, Matrix>> &map);
     if (ans == expected) {
        std::cout << "Passed" << std::endl;
        return true;
     }
     else {
        std::cout << "Failed, " << ans << " (expected " << expected << ")" << std::endl;
        return false;
     }   
}

bool run_test_mult() {
    std::cout << "Testing multiplication..." << std::endl;
    int passed = 0;
    if (test_mult()) passed ++;
    if (test_mult()) passed ++;
    if (test_mult()) passed ++;
    if (test_mult()) passed ++;
    if (test_mult()) passed ++;
    std::cout << "Multiples passed " << passed << " tests." << std::endl;
    return passed;
}*/