#include <stdio.h>
#include "./matrix.h"
int random = 0;

// Prints a matrix of name s given in parameter
void print(char *s, Matrix *m)
{
	if (m == NULL)
	{
		warnx("Print: null matrix was given, skipping the printing");
		return;
	}
    printf("%s =\n", s);
    for (size_t i = 0; i < m->line; i++)
    {
	    for (size_t j = 0; j < m->col; j++)
	    {
		    printf("   %4g", m->data[i * m->col + j]);
	    }
	    printf("\n");
    }
}

// Inits a matrix of dim line*col. Warning: values are not initialized.
Matrix *InitMatrix(size_t line, size_t col)
{
	//mallocs++;
	Matrix *matrix = malloc(sizeof(Matrix));
	if (!matrix)
		errx(1, "InitMatrix failed: not enough memory!");
	matrix->data = malloc(line*col*sizeof(double));
	matrix->col = col;
	matrix->line = line;
	return matrix;
}

// Inits a matrix of dim line*col. Warning: values are initialized.
Matrix *InitMatrixFULL(size_t line, size_t col)
{
	//mallocs++;
	Matrix *matrix = malloc(sizeof(Matrix));
	if (!matrix)
		errx(1, "InitMatrix failed: not enough memory!");
	matrix->data = calloc(line*col, sizeof(double));
	matrix->col = col;
	matrix->line = line;
	return matrix;
}

// Inits a matrix of dim line*col.
Matrix *InitMatrixRandom(size_t line, size_t col)
{
	//mallocs++;
	Matrix *matrix = malloc(sizeof(Matrix));
	if (!matrix)
		errx(1, "InitMatrix failed: not enough memory!");
	matrix->data = malloc(line*col*sizeof(double));
	size_t limit = line*col;
	for (size_t i = 0; i < limit; i++)
	{
		matrix->data[i] = CappedRandom();
	}
	matrix->col = col;
	matrix->line = line;
	return matrix;
}

// standard procedure to free a matrix
void FreeMatrix(Matrix *matrix)
{
	if (matrix == NULL)
		return;
	free(matrix->data);
	free(matrix);
}
/* Copies the content of a matrix to another. SRC & DST must be initialized and
 * of same size
*/
void CopyMatrix(Matrix *src, Matrix *dst)
{
	if (src == NULL || dst == NULL)
		return;
	if (src->col != dst->col || src->line != dst->line)
		errx(1, "Copy matrix failure, sizes are different");
	memmove(dst->data, src->data, (src->line*src->col)*sizeof(double));
}

// Returns a copy of the matrix given in argument
Matrix *copyMatrixNIP(Matrix *src)
{
	if (!src)
		return NULL;
	Matrix *copy = InitMatrix(src->line, src->col);
	CopyMatrix(src, copy);
	return copy;
}

// Generate an identity matrix of size line*col
Matrix *GenerateIdentity(size_t line, size_t col)
{
	Matrix *m = InitMatrix(line, col);
	for (size_t i = 0; i < line; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			if (i == j)
			{
				m->data[col*i+j] = 1;
			}
			else
			{
				m->data[col*i+j] = 0;
			}
		}
	}
	return m;
}

// Generates a matrix of dimension line*col containing only ones.
Matrix *GenerateMatrixOnes(size_t line, size_t col)
{
	Matrix *m = InitMatrix(line, col);
	size_t limit = line*col;
	for (size_t i = 0; i < limit; i++)
	{
		m->data[i] = 1;
	}
	return m;
	
}

// Random generator init
void Init_Random(void)
{
	if (random)
		return;
	srand(time(NULL));
	random = 1;
}

// Returns a double between 0 and 1
double CappedRandom(void)
{
	if (!random)
		Init_Random();
	int randa = rand();
	if (randa % 2 == 0)
	{
		return (double) (rand() % 1000000) / 1000000.0;
	}
	else
	{
		return (double) -(rand() % 1000000) / 1000000.0;
	}
	
}