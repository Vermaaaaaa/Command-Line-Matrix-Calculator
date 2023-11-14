#include <iostream>
#include <vector>

class Matrix {
private:
    std::vector<std::vector<int>> data; // 2D vector to store matrix elements
    int rows;
    int cols;

public:
    // Constructor to create a matrix with the given dimensions
    Matrix(int numRows, int numCols) : rows(numRows), cols(numCols) {
        // Resize the vector to the specified dimensions and initialize elements to 0
        data.resize(rows, std::vector<int>(cols, 0));
    }

    // Function to set the value of a specific element in the matrix
    void setElement(int row, int col, int value) {
        if (row >= 0 && row < rows && col >= 0 && col < cols) {
            data[row][col] = value;
        } else {
            std::cerr << "Invalid matrix index" << std::endl;
        }
    }

    // Function to get the value of a specific element in the matrix
    int getElement(int row, int col) const {
        if (row >= 0 && row < rows && col >= 0 && col < cols) {
            return data[row][col];
        } else {
            std::cerr << "Invalid matrix index" << std::endl;
            return 0; // Return a default value in case of an error
        }
    }

    // Function to display the matrix
    void display() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    // Create a 3x3 matrix
    Matrix myMatrix(3, 3);

    // Set some values in the matrix
    myMatrix.setElement(0, 0, 1);
    myMatrix.setElement(1, 1, 5);
    myMatrix.setElement(2, 2, 9);

    // Display the matrix
    std::cout << "Matrix:" << std::endl;
    myMatrix.display();

    return 0;
}
