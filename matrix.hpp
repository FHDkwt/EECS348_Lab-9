// header file
#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__
// including nrequired libraries
#include <cstdint>
#include <vector>
#include <iostream>
#include <iomanip>
#include <stdexcept> 

// defining template class for Matrix
template <typename T>
// defining class "Matrix"
class Matrix {
private:
    std::vector<std::vector<T>> data; // vector to store matrix elements
    std::size_t size;        
public:
    // defining constructor to initialize NxN matrix
    Matrix(std::size_t N):size(N) {
        data.resize(N,std::vector<T>(N,0));
    }
    // defining constructor to initialize 2D vector matrix
    Matrix(std::vector<std::vector<T>> nums):data(nums),size(nums.size()) {}
    // defining addition overloading operator for matrix addition
    Matrix operator+(const Matrix &rhs) const {
        Matrix result(size);
        for (std::size_t i = 0;i<size;i++) 
        {
            for (std::size_t j = 0;j<size;j++) 
            {
                result.data[i][j] = data[i][j]+rhs.data[i][j];
            }
        }
        return result;
    }
    // defining multiplication overloading operator for matrix multiplication
    Matrix operator*(const Matrix &rhs) const {
        Matrix result(size);
        for (std::size_t i = 0;i<size;i++) 
        {
            for (std::size_t j = 0;j<size;j++) 
            {
                for (std::size_t k = 0;k<size;k++) 
                {
                    result.data[i][j] += data[i][k]*rhs.data[k][j];
                }
            }
        }
        return result;
    }
    // defining function to set value 
    void set_value(std::size_t i,std::size_t j,T n) {
        if (i<size && j<size) 
        {
            data[i][j] = n;
        }
    }
    // defining function to get value 
    T get_value(std::size_t i,std::size_t j) const {
        if (i >= size || j >= size) 
        {
            throw std::out_of_range("Index out of bound");
        }
        return data[i][j];
    }
    // defining function for matrix size
    std::size_t get_size() const {
        return size;
    }
    //  defining function for calculating sum of main diagonal elements of matrix
    T sum_diagonal_major() const {
        T sum = 0;
        for (std::size_t i = 0;i<size;i++) 
        {
            sum += data[i][i];
        }
        return sum;
    }
    //  defining function for calculating sum of secondary diagonal elements of matrix
    T sum_diagonal_minor() const {
        T sum = 0;
        for (std::size_t i=0;i<size;i++) 
        {
            sum += data[i][size - 1 - i];
        }
        return sum;
    }
    //  defining function to swap two rows of matrix
    void swap_rows(std::size_t r1,std::size_t r2) {
        if (r1<size&&r2<size) 
        {
            std::swap(data[r1],data[r2]);
        }
    }
    //  defining function to swap two columns of matrix
    void swap_cols(std::size_t c1,std::size_t c2) {
        if (c1<size && c2<size) 
        {
            for (std::size_t i=0; i<size;i++) 
            {
                std::swap(data[i][c1],data[i][c2]);
            }
        }
    }
    //  defining function to print matrix
    void print_matrix() const {
        for (std::size_t i=0; i <size;i++) 
        {
            for (std::size_t j=0;j<size;j++) 
            {
                std::cout<<std::setw(5)<<data[i][j];
            }
            std::cout<<std::endl;
        }
    }
};
#endif // __MATRIX_HPP__
