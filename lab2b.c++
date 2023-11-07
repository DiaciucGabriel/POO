#include <iostream>
#include <iomanip>
#include <cstring>

class Complex {
public:
    Complex() : real(0.0), imag(0.0) {}
    Complex(double r, double i) : real(r), imag(i) {}

    double getReal() const { return real; }
    double getImag() const { return imag; }

    void setReal(double r) { real = r; }
    void setImag(double i) { imag = i; }

    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    Complex operator*(const Complex& other) const {
        return Complex(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
    }

    Complex operator*(double scalar) const {
        return Complex(real * scalar, imag * scalar);
    }

private:
    double real;
    double imag;
};

class Matrix {
public:
    Matrix() : data(nullptr), rows(0), cols(0), errorCode(0) {}

    Matrix(int numRows, int numCols) : rows(numRows), cols(numCols), errorCode(0) {
        data = new Complex*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new Complex[cols];
        }
    }

    Matrix(const Matrix& other) : rows(other.rows), cols(other.cols), errorCode(0) {
        data = new Complex*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new Complex[cols];
            for (int j = 0; j < cols; ++j) {
                data[i][j] = other.data[i][j];
            }
        }
    }

    ~Matrix() {
        if (data != nullptr) {
            for (int i = 0; i < rows; ++i) {
                delete[] data[i];
            }
            delete[] data;
        }
    }

    Complex get(int row, int col) const {
        if (row >= 0 && row < rows && col >= 0 && col < cols) {
            return data[row][col];
        }
     
        return Complex();
    }

    void set(int row, int col, const Complex& value) {
        if (row >= 0 && row < rows && col >= 0 && col < cols) {
            data[row][col] = value;
        } else {
            errorCode = -1; // Eroare: Indicii invalizi
        }
    }

    Matrix operator+(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            Matrix result(0, 0);
            result.errorCode = -2; // Eroare: Dimensiuni incompatibile
            return result;
        }

        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }

        return result;
    }

    Matrix operator-(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            Matrix result(0, 0);
            result.errorCode = -2; // Eroare: Dimensiuni incompatibile
            return result;
        }

        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }

        return result;
    }

    Matrix operator*(const Matrix& other) const {
        if (cols != other.rows) {
            Matrix result(0, 0);
            result.errorCode = -2; // Eroare: Dimensiuni incompatibile
            return result;
        }

        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                result.data[i][j] = Complex();
                for (int k = 0; k < cols; ++k) {
                    result.data[i][j] = result.data[i][j] + (data[i][k] * other.data[k][j]);
                }
            }
        }

        return result;
    }

    Matrix operator*(double scalar) const {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] * scalar;
            }
        }
        return result;
    }

    int getErrorCode() const {
        return errorCode;
    }

    void print() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << std::fixed << std::setprecision(2) << data[i][j].getReal() << "+" << data[i][j].getImag() << "i" << "\t";
            }
            std::cout << std::endl;
        }
    }

private:
    Complex** data;
    int rows;
    int cols;
    int errorCode;
};

int main() {
    Matrix a(2, 2);
    Matrix b(2, 2);
    
    a.set(0, 0, Complex(1, 2));
    a.set(0, 1, Complex(3, 4));
    a.set(1, 0, Complex(5, 6));
    a.set(1, 1, Complex(7, 8));

    b.set(0, 0, Complex(8, 7));
    b.set(0, 1, Complex(6, 5));
    b.set(1, 0, Complex(4, 3));
    b.set(1, 1, Complex(2, 1));

    std::cout << "Matrix A:" << std::endl;
    a.print();
    std::cout << std::endl;

    std::cout << "Matrix B:" << std::endl;
    b.print();
    std::cout << std::endl;

    Matrix sum = a + b;
    Matrix diff = a - b;
    Matrix product = a * b;
    Matrix scalarProduct = a * 2.5;

    std::cout << "Sum of A and B:" << std::endl;
    sum.print();
    std::cout << std::endl;

    std::cout << "Difference of A and B:" << std::endl;
    diff.print();
    std::cout << std::endl;

    std::cout << "Product of A and B:" << std::endl;
    product.print();
    std::cout << std::endl;

    std::cout << "Scalar product of A with 2.5:" << std::endl;
    scalarProduct.print();
    std::cout << std::endl;

    if (sum.getErrorCode() != 0) {
        std::cout << "Error in the sum operation. Error code: " << sum.getErrorCode() << std::endl;
    }

    return 0;
}
