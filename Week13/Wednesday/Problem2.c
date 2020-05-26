#include <stdio.h>
#include <stdlib.h>

typedef int MatrixElement;

struct Matrix
{
    int line;
    int column;
    MatrixElement *values;
};

typedef struct Matrix *Matrix;

Matrix createMatrix(const int LINE, const int COLUMN)
{
    Matrix m = malloc(sizeof(struct Matrix));
    m->line = LINE;
    m->column = COLUMN;

    MatrixElement *lines = malloc(sizeof(MatrixElement) * LINE * COLUMN);

    m->values = lines;
    return m;
}

MatrixElement getMaxtrixElement(const Matrix M, const int LINE, const int COLUMN)
{
    if (LINE >= M->line || COLUMN >= M->column)
    {
        perror("Out of index.");
        return -99999;
    }

    return M->values[convertPos2Index(M, LINE, COLUMN)];
}

void setMatrixElement(const Matrix M, const int LINE, const int COLUMN, const MatrixElement value)
{
    if (LINE >= M->line || COLUMN >= M->column)
    {
        perror("Out of index.");
        return -99999;
    }

    M->values[convertPos2Index(M, LINE, COLUMN)] = value;
}

unsigned long long convertIndex2Pos(const Matrix M, const int index)
{
    unsigned long long line = index / M->column;
    unsigned long long column = index % M->column;
    unsigned long long result = column + (line << 32);
    return result;
}

inline int convertPos2Index(const Matrix M, const int LINE, const int COLUMN)
{
    return LINE * M->column + COLUMN;
}

int main()
{
    int m, n, inputValue;
    scanf("%d %d", &m, &n);
    Matrix matrix = createMatrix(m, n);

    for (int i = 0; i < m * n; i++)
    {
        scanf("%d", &inputValue);
        matrix->values[i] = inputValue;
    }

    int index = 0;
    int sum = 0;
    for (int line = 0; line < m; line++)
    {
        for (int column = 0; column < n; column++)
        {
            sum += matrix->values[index];
            index++;
        }
        printf("%d\n", sum);
        sum = 0;
    }

    free(matrix->values);
    free(matrix);
}
