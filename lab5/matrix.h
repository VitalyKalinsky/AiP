#ifndef MATRIX_H
#define MATRIX_H

struct Matrix
{
    double **data;
    int rows;
    int cols;
};

void m_zero(Matrix *A, int m, int n);
void m_id(Matrix *A, int n);
void m_free(Matrix *A);
void m_copy(const Matrix *src, Matrix *dst);
int m_width(const Matrix *A);
int m_height(const Matrix *A);
double m_get(const Matrix *A, int i, int j);
void m_set(Matrix *A, int i, int j, double value);

int m_add(Matrix *A, const Matrix *B);
void m_neg(Matrix *A);
int m_mult(Matrix *const A, const Matrix *B, Matrix *dst);
void print_matrix(Matrix * const matrix);
#endif