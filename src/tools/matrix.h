#ifndef MATRIX_H
#define MATRIX_H
#include <stdlib.h>
#include <err.h>
#include <string.h>
#include <time.h>
#include <math.h>
typedef struct Matrix Matrix;
struct Matrix
{
    double *data;
    size_t line;
    size_t col;
};
#include "./operations.h"
void Init_Random(void);
double CappedRandom(void);

void FreeMatrix(Matrix *matrix);
void CopyMatrix(Matrix *src, Matrix *dst);
Matrix *copyMatrixNIP(Matrix *src);
void CopyMatrix(Matrix *src, Matrix *dst);
Matrix *InitMatrixRandom(size_t line, size_t col);
Matrix *GenerateIdentity(size_t line, size_t col);
Matrix *GenerateMatrixOnes(size_t line, size_t col);
Matrix *InitMatrix(size_t line, size_t col);
Matrix *InitMatrixFULL(size_t line, size_t col);
void print(char *s, Matrix *m);
#endif
