#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__

#include <cstdint>
#include <vector>
#include <iostream>
#include <iomanip>

// Class definition for Matrix
class Matrix {
private:
    std::vector<std::vector<int>> data; // 2D vector to store matrix elements
    std::size_t size;                   // Size of the N x N matrix

public:
    // Constructor: Initializes an N x N matrix with zeros
    Matrix(std::size_t N) : size(N) {
        data.resize(N, std::vector<int>(N, 0));
    }

    // Constructor: Initializes matrix with given 2D vector
    Matrix(std::vector<std::vector<int>> nums) : data(nums), size(nums.size()) {}

    // Addition operator overloading for matrix addition
    Matrix operator+(const Matrix &rhs) const {
        Matrix result(size);
        for (std::size_t i = 0; i < size; i++) {
            for (std::size_t j = 0; j < size; j++) {
                result.data[i][j] = data[i][j] + rhs.data[i][j];
            }
        }
        return result;
    }

    // Multiplication operator overloading for matrix multiplication
    Matrix operator*(const Matrix &rhs) const {
        Matrix result(size);
        for (std::size_t i = 0; i < size; i++) {
            for (std::size_t j = 0; j < size; j++) {
                for (std::size_t k = 0; k < size; k++) {
                    result.data[i][j] += data[i][k] * rhs.data[k][j];
                }
            }
        }
        return result;
    }

    // Function to set value at specified position
    void set_value(std::size_t i, std::size_t j, int n) {
        if (i < size && j < size) {
            data[i][j] = n;
        }
    }

    // Function to get value at specified position
    int get_value(std::size_t i, std::size_t j) const {
        if (i < size && j < size) {
            return data[i][j];
        }
        return 0; // Return 0 if indices are out of bounds
    }

    // Function to get matrix size
    int get_size() const {
        return size;
    }

    // Function to calculate sum of main diagonal elements
    int sum_diagonal_major() const {
        int sum = 0;
        for (std::size_t i = 0; i < size; i++) {
            sum += data[i][i];
        }
        return sum;
    }

    // Function to calculate sum of secondary diagonal elements
    int sum_diagonal_minor() const {
        int sum = 0;
        for (std::size_t i = 0; i < size; i++) {
            sum += data[i][size - 1 - i];
        }
        return sum;
    }

    // Function to swap two rows
    void swap_rows(std::size_t r1, std::size_t r2) {
        if (r1 < size && r2 < size) {
            std::swap(data[r1], data[r2]);
        }
    }

    // Function to swap two columns
    void swap_cols(std::size_t c1, std::size_t c2) {
        if (c1 < size && c2 < size) {
            for (std::size_t i = 0; i < size; i++) {
                std::swap(data[i][c1], data[i][c2]);
            }
        }
    }

    // Function to print matrix with formatted output
    void print_matrix() const {
        for (std::size_t i = 0; i < size; i++) {
            for (std::size_t j = 0; j < size; j++) {
                std::cout << std::setw(5) << data[i][j];
            }
            std::cout << std::endl;
        }
    }
};

#endif // __MATRIX_HPP__
