#include <iostream>
#include <fstream>
#include "matrix.hpp"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
        return 1;
    }

    std::ifstream file(argv[1]);
    if (!file) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    std::size_t n;
    int type;
    file >> n >> type;

    if (type == 0) {
        Matrix m1(n), m2(n);
        for (std::size_t i = 0; i < n; i++) {
            for (std::size_t j = 0; j < n; j++) {
                int value;
                file >> value;
                m1.set_value(i, j, value);
            }
        }
        for (std::size_t i = 0; i < n; i++) {
            for (std::size_t j = 0; j < n; j++) {
                int value;
                file >> value;
                m2.set_value(i, j, value);
            }
        }

        std::cout << "Matrix 1:\n";
        m1.print_matrix();
        std::cout << "Matrix 2:\n";
        m2.print_matrix();

        Matrix sum = m1 + m2;
        std::cout << "Sum of matrices:\n";
        sum.print_matrix();

        Matrix product = m1 * m2;
        std::cout << "Product of matrices:\n";
        product.print_matrix();

        std::cout << "Main diagonal sum: " << m1.sum_diagonal_major() << std::endl;
        std::cout << "Secondary diagonal sum: " << m1.sum_diagonal_minor() << std::endl;

        m1.swap_rows(0, 1);
        std::cout << "Matrix 1 after swapping rows 0 and 1:\n";
        m1.print_matrix();

        m1.swap_cols(0, 1);
        std::cout << "Matrix 1 after swapping columns 0 and 1:\n";
        m1.print_matrix();

        m1.set_value(0, 0, 99);
        std::cout << "Matrix 1 after updating element (0,0) to 99:\n";
        m1.print_matrix();
    } else if (type == 1) {
        Matrix m1(n), m2(n);
        for (std::size_t i = 0; i < n; i++) {
            for (std::size_t j = 0; j < n; j++) {
                double value;
                file >> value;
                m1.set_value(i, j, value);
            }
        }
        for (std::size_t i = 0; i < n; i++) {
            for (std::size_t j = 0; j < n; j++) {
                double value;
                file >> value;
                m2.set_value(i, j, value);
            }
        }

        std::cout << "Matrix 1:\n";
        m1.print_matrix();
        std::cout << "Matrix 2:\n";
        m2.print_matrix();

        Matrix sum = m1 + m2;
        std::cout << "Sum of matrices:\n";
        sum.print_matrix();

        Matrix product = m1 * m2;
        std::cout << "Product of matrices:\n";
        product.print_matrix();

        std::cout << "Main diagonal sum: " << m1.sum_diagonal_major() << std::endl;
        std::cout << "Secondary diagonal sum: " << m1.sum_diagonal_minor() << std::endl;

        m1.swap_rows(0, 1);
        std::cout << "Matrix 1 after swapping rows 0 and 1:\n";
        m1.print_matrix();

        m1.swap_cols(0, 1);
        std::cout << "Matrix 1 after swapping columns 0 and 1:\n";
        m1.print_matrix();

        m1.set_value(0, 0, 99.0);
        std::cout << "Matrix 1 after updating element (0,0) to 99.0:\n";
        m1.print_matrix();
    }

    file.close();
    return 0;
}
