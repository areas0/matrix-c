#ifndef OPERATIONS_H
#define OPERATIONS_H


#include "./matrix.h"
#include <stdio.h>
#include <math.h>

Matrix *HadamarProduct(Matrix *m1, Matrix *m2);
Matrix *addMatrix(Matrix *m1, Matrix *m2);
Matrix *matrixMultiplication(Matrix *matrix1, Matrix *matrix2);
Matrix *transposeMatrix(Matrix *m);
Matrix *subMatrix(Matrix *m1, Matrix *m2);
void MatrixMultiplicationDigit(Matrix *m, double factor);
void AddMatricesIP(Matrix *m1, Matrix *m2);
void HadamarProductIP(Matrix *m1, Matrix *m2);
void SubMatricesIP(Matrix *m1, Matrix *m2);
double GetSum(Matrix *matrix);
void Equal(Matrix *m1, Matrix *m2);

#endif