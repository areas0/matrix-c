#include "operations.h"

/* Hadamard matricial product: uses 2 matrices of same dimension and multiplies
** one by one values. Operation is done not in place.
** @return Matrix the value of the product (Matrix type)
*/
Matrix *HadamarProduct(Matrix *m1, Matrix *m2)
{
	if (m1->col != m2->col || m1->line != m2->line)
	{
		errx(1,"Sizes are different (Hadamar Product)");
	}
	Matrix *res = InitMatrix(m1->line, m2->col);
	size_t cols = m2->col;
	for (size_t i = 0; i < m1->line; i++)
	{
		for (size_t j = 0; j < m1->col; j++)
		{
			size_t index = i*cols+j;
			res->data[index] = m1->data[index] * m2->data[index];
		}
		
	}
	return res;
}

/* Hadamard matricial product: uses 2 matrices of same dimension and multiplies
 one by one values. Operation is done in place! M1 is modified!
@return nothing
*/
void HadamarProductIP(Matrix *m1, Matrix *m2)
{
	if (m1->col != m2->col || m1->line != m2->line)
	{
		errx(1,"Sizes are different (Hadamar Product)");
	}
	size_t cols = m2->col;
	for (size_t i = 0; i < m1->line; i++)
	{
		for (size_t j = 0; j < m1->col; j++)
		{
			size_t index = i*cols+j;
			m1->data[index] = m1->data[index] * m2->data[index];
		}
		
	}
}

/* Matrix multiplication: not in place!
** crashes the program if the dimensions are not valid
** @param two matrices to multiply
*/
Matrix *matrixMultiplication(Matrix *matrix1, Matrix *matrix2)
{
	if (matrix1->col != matrix2->line)
	{
		errx(1, "Matrix multiplication failed due to difference in size");
	}
	Matrix *result = InitMatrix(matrix1->line, matrix2->col);
	size_t c1 = matrix1->col;
	size_t c2 = matrix2->col;
	for (size_t i = 0; i < matrix1->line; i++)
    {
	    for (size_t j = 0; j < matrix2->col; j++)
	    {
		    size_t current = c2 * i + j;
			result->data[current] = 0;
		    for (size_t k = 0; k < c1; k++)
		    {
			    result->data[current] += matrix1->data[c1*i+k] * matrix2->data[c2*k+j];
		    }
	    }
    }
	return result;
}

// adds two matrices
Matrix *addMatrix(Matrix *m1, Matrix *m2)
{
	if (m1->col != m2->col || m1->line != m2->line)
	{
		errx(1,"Sizes are different (AddMatrix)");
	}
	Matrix *r = InitMatrix(m1->line, m1->col);
	size_t cols = m1->col;
    for (size_t i = 0; i < m1->line; i++)
    {
	    for (size_t j = 0; j < cols; j++)
	    {
			size_t index = i*cols+j;
		    r->data[index] = m1->data[index] + m2->data[index];
	    }
    }
	return r;
}

// Substracts two matrices
// @return a new matrix which is the result of the operation
Matrix *subMatrix(Matrix *m1, Matrix *m2)
{
	if (m1->col != m2->col || m1->line != m2->line)
	{
		errx(1,"Sizes are different (SubMatrix)");
	}
	Matrix *r = InitMatrix(m1->line, m1->col);
	size_t cols = m1->col;
    for (size_t i = 0; i < m1->line; i++)
    {
	    for (size_t j = 0; j < m1->col; j++)
	    {
			size_t index = i*cols+j;
		    r->data[index] = m1->data[index] - m2->data[index];
	    }
    }
	return r;
}

// Transpition function
// Not IN place
// @return a matrix of dim col*line from a given matrix m of dim line*col
Matrix *transposeMatrix(Matrix *m)
{
	Matrix *r = InitMatrix(m->col,m->line);
	size_t line = m->line;
	size_t col = m->col;
    for (size_t i = 0 ; i < line ; i++)
    {
	    for (size_t j = 0; j < col; j++)
	    {
		    r->data[j*line+i] = m->data[i*col+j];
	    }
    }
	return r;
}

#if AI
/*	Exponential sum of a matrix, used for softmax computation (factor computation)
*/
double GetSum(Matrix *matrix)
{
	double sum = 0;
	size_t limit = matrix->col*matrix->line;
	for (size_t i = 0; i < limit; i++)
	{
		sum += exp(matrix->data[i]);
	}
	return sum;
}
#endif

// checks if two matrices are equal, for all different values produces a warning
void Equal(Matrix *m1, Matrix *m2)
{
	if (m1->col != m2->col || m2->line != m1->line)
	{
		warnx("Equal: matrix are of different sizes, skipping...");
		return;
	}
	size_t limit = m1->line*m1->col;
	for (size_t i = 0; i < limit; i++)
	{
		if (m1->data[i] != m2->data[i])
		{
			warnx("Equal: values are different i: %zu value: %lf %lf", i,
					m1->data[i], m2->data[i]);
		}
	}
}

// Matrix multiplication for all the data by a factor
// Warning: this operation runs in place
void MatrixMultiplicationDigit(Matrix *m, double factor)
{
	size_t limit = m->line*m->col;
	for (size_t i = 0; i < limit; i++)
	{
		m->data[i] *= factor;
	}
	
}
// Matrix addition (one by one) running IN PLACE: modifies only m1
void AddMatricesIP(Matrix *m1, Matrix *m2)
{
	if (m1->col != m2->col || m1->line != m2->line)
	{
		errx(1,"Sizes are different (AddMatrix)");
	}
	size_t cols = m1->col;
    for (size_t i = 0; i < m1->line; i++)
    {
	    for (size_t j = 0; j < cols; j++)
	    {
			size_t index = i*cols+j;
		    m1->data[index] = m1->data[index] + m2->data[index];
	    }
    }
}

// Matrix substraction (one by one) running IN PLACE: modifies only m1
void SubMatricesIP(Matrix *m1, Matrix *m2)
{
	if (m1->col != m2->col || m1->line != m2->line)
	{
		errx(1,"Sizes are different (AddMatrix)");
	}
	size_t cols = m1->col;
    for (size_t i = 0; i < m1->line; i++)
    {
	    for (size_t j = 0; j < cols; j++)
	    {
			size_t index = i*cols+j;
		    m1->data[index] = m1->data[index] - m2->data[index];
	    }
    }
}