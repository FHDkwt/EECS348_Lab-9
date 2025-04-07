// including header file and neccesary libraries
#include <iostream>
#include <fstream>
#include "matrix.hpp"
// defining main function
int main(int argc, char *argv[]) {
    // opening file
    if (argc != 2) 
    {
        std::cerr <<"Usage: "<<argv[0]<< " <input_file>" << std::endl;
        return 1;
    }
    std::ifstream file(argv[1]);
    if (!file) 
    {
        std::cerr<<"Error opening file." << std::endl;
        return 1;
    }
    // reading matrix size and type from file
    std::size_t n;
    int type;
    file>>n>>type;
    if (type == 0) 
    {
        Matrix<int> mat1(n),mat2(n);
        for (std::size_t i =0;i<n;i++) 
        {   // reading values into first matrix from file
            for (std::size_t j =0;j<n;j++) 
            {
                int value;
                file>>value;
                mat1.set_value(i,j,value);
            }
        }
        for (std::size_t i = 0;i<n;i++) 
        {    // reading values into second matrix from file
            for (std::size_t j =0;j<n;j++) 
            {
                int value;
                file>>value;
                mat2.set_value(i,j,value);
            }
        }
         // performing matrix operation - addition
        std::cout<<"Matrix 1:\n";
        mat1.print_matrix();
        std::cout <<"Matrix 2:\n";
        mat2.print_matrix();
        Matrix<int> sum = mat1+mat2;
        std::cout << "Sum of matrices:\n";
        sum.print_matrix();
         // performing matrix operation - multiplication
        Matrix<int> product = mat1*mat2;
        std::cout << "Product of matrices:\n";
        product.print_matrix();
         // performing matrix operation - calculating and displaying diagonal sums for both matrices
        std::cout <<"Main diagonal sum:" << mat1.sum_diagonal_major() << std::endl;
        std::cout <<"Secondary diagonal sum: " << mat1.sum_diagonal_minor() << std::endl;
         // performing matrix operation - swapping rows
        mat1.swap_rows(0,1);
        std::cout<<"Matrix 1 after swapping rows 0 and 1:\n";
        mat1.print_matrix();
         // performing matrix operation - swapping columns
        mat1.swap_cols(0,1);
        std::cout<<"Matrix 1 after swapping columns 0 and 1:\n";
        mat1.print_matrix();
        // performing matrix operation - updating elements
        mat1.set_value(0,0,99);
        std::cout << "Matrix 1 after updating element:\n";
        mat1.print_matrix();
    } 
    else if (type == 1) 
    {
        Matrix<double> mat1(n), mat2(n);
        for (std::size_t i =0;i<n;i++) 
        {
            for (std::size_t j=0;j<n;j++) 
            {
                double value;
                file >>value;
                mat1.set_value(i,j,value);
            }
        }
        for (std::size_t i =0;i<n;i++) 
        {
            for (std::size_t j =0;j<n;j++) 
            {
                double value;
                file>> value;
                mat2.set_value(i,j,value);
            }
        }
        std::cout <<"Matrix 1:\n";
        mat1.print_matrix();
        std::cout <<"Matrix 2:\n";
        mat2.print_matrix();
        Matrix<double> sum = mat1+mat2;
        std::cout <<"Sum of matrices = \n";
        sum.print_matrix();
        Matrix<double> product = mat1*mat2;
        std::cout<<"Product of matrice = :\n";
        product.print_matrix();
        std::cout << "Main diagonal sum ="<< mat1.sum_diagonal_major()<< std::endl;
        std::cout << "Secondary diagonal sum = "<< mat1.sum_diagonal_minor() << std::endl;
        mat1.swap_rows(0,1);
        std::cout <<"Matrix 1 after swapping rows:\n";
        mat1.print_matrix();
        mat1.swap_cols(0,1);
        std::cout <<"Matrix 1 after swapping columns:\n";
        mat1.print_matrix();
        mat1.set_value(0,0,99.0);
        std::cout << "Matrix 1 after updating elements:\n";
        mat1.print_matrix();
    }
    file.close();
    return 0;
}
