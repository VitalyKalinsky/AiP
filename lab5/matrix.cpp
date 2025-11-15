#include "matrix.h"
#include <cassert>
#include <iostream>
void m_zero(Matrix *A, int m, int n)
{
    assert(A != nullptr && m > 0 && n > 0);
    A->rows = m;
    A->cols = n;
    A->data = new double *[m];
    for (int i = 0; i < m; i++)
    {
        A->data[i] = new double[n]();
    }
}
void m_id(Matrix *A, int n)
{
    assert(A != nullptr && n > 0);
    m_zero(A, n, n);
    for (int i = 0; i < n; i++)
    {
        A->data[i][i] = 1;
    }
}
void m_free(Matrix *A)
{
    assert(A != nullptr);
    for (int i = 0; i < A->rows; i++)
    {
        delete[] A->data[i];
    }
    delete[] A->data;
    A->data = nullptr;
}

void m_copy(const Matrix *src, Matrix *dst)
{
    assert(src != nullptr && dst != nullptr);
    m_zero(dst, src->rows, src->cols);
    for (int i = 0; i < src->rows; i++)
    {
        for (int j = 0; j < src->cols; j++)
        {
            dst->data[i][j] = src->data[i][j];
        }
    }
}
int m_width(const Matrix *A)
{
    return A->cols;
}

int m_height(const Matrix *A)
{
    return A->rows;
}

double m_get(const Matrix *A, int i, int j)
{
    return A->data[i][j];
}

void m_set(Matrix *A, int i, int j, double value)
{
    if (i < 0 || i >= A->rows || j < 0 || j >= A->cols)
    {
        printf("Неправильные индексы: (%d , %d)\n", i, j);
        return;
    }
    A->data[i][j] = value;
}

int m_add(Matrix *A, const Matrix *B)
{
    if (A->rows != B->rows || A->cols != B->cols)
    {
        return 1;
    }

    for (int i = 0; i < A->rows; i++)
    {
        for (int j = 0; j < A->cols; j++)
        {
            A->data[i][j] += B->data[i][j];
        }
    }
    return 0;
}
void m_neg(Matrix *A)
{
    assert(A != nullptr);
    for (int i = 0; i < A->rows; i++)
    {
        for (int j = 0; j < A->cols; j++)
        {
            A->data[i][j] = -(A->data[i][j]);
        }
    }
}
int m_mult(Matrix *const A, const Matrix *B, Matrix *dst)
{
    if (A->cols != B->rows)
    {
        return 1;
    }
    m_zero(dst, A->rows, B->cols); // NxM * MxK = N * K

    for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < B->cols; j++) {
            for (int k = 0; k < A->cols; k++) {
                dst->data[i][j] += A->data[i][k] * B->data[k][j];
            }
        }
    }
    
    return 0;
}

using namespace std;
void print_matrix(Matrix *const matrix)
{
    assert(matrix != nullptr && matrix->rows > 0 && matrix->cols > 0);
    cout << "[";
    for (int i = 0; i < matrix->rows; i++)
    {
        cout << "[";
        for (int j = 0; j < matrix->cols; j++)
        {
            printf("%.10g%s", matrix->data[i][j], ((j == matrix->cols - 1) ? "]" : ", "));
        }
        cout << ((i == matrix->rows - 1) ? "]\n" : ", ");
    }
}