#include "multiply.h"
#include "matrix.h"
#include <iostream>

void ans = 0.0;

int main() {

}




bool test_mult(const Matrix &mat1, const Matrix &mat2, const Matrix expected){
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
}