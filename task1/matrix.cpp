#include "matrix.hpp"
#include <vector>
#include <stdexcept>

class Matrix
{
public:
    Matrix() = default;
    Matrix(int numRows, int numCols)
    {
        Reset(numRows, numCols);
    }

    void Reset(int numRows, int numCols)
    {
        if (numRows <= 0 || numCols <= 0) {
            rows = 0;
            cols = 0;
            matrix.clear();
        }
        else {
            rows = numRows;
            cols = numCols;
            matrix.resize(rows, std::vector<int>(cols, 0));  // инициализируем нулями
        }
    }

    int& At(int row, int col)
    {
        if (row < 0 || row >= rows || col < 0 || col >= cols) {
            throw std::out_of_range("Index out of range");
        }
        return matrix[row][col];
    }

    const int& At(int row, int col) const
    {
        if (row < 0 || row >= rows || col < 0 || col >= cols) {
            throw std::out_of_range("Index out of range");
        }
        return matrix[row][col];
    }

    int GetRows() const
    {
        return rows;
    }

    int GetCols() const
    {
        return cols;
    }

    bool operator==(const Matrix& m2)
    {
        if (rows != m2.rows || cols != m2.cols) return false;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] != m2.matrix[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }

    bool operator!=(const Matrix& m2)
    {
        return !(*this == m2);
    }

    Matrix operator+(const Matrix& m2)
    {
        if (rows != m2.rows || cols != m2.cols) {
            throw std::invalid_argument("Matrix sizes do not match for addition");
        }
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.At(i, j) = this->At(i, j) + m2.At(i, j);
            }
        }
        return result;
    }

private:
    int rows = 0;
    int cols = 0;
    std::vector<std::vector<int>> matrix;
};

// Пример использования:
int main() {
    Matrix m1(2, 3);
    Matrix m2(2, 3);
    //m1.Reset(0,0);
    m1.At(0, 0) = 1;
    m1.At(0, 1) = 2;
    m1.At(0, 2) = 3;

    m2.At(0, 0) = 4;
    m2.At(0, 1) = 5;
    m2.At(0, 2) = 6;

    Matrix m3 = m1 + m2;

    return 0;
}
