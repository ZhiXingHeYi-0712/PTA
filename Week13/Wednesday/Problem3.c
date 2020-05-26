#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool isUpperTriangleMatrix(Matrix m)
{
    for (int line = 1; line < m->line; line++)
    {
        for (int column = 0; column < line; column++)
        {
            if (getMaxtrixElement(m, line, column) != 0) {
                return false;
            }
        }
    }
    return true;
}

void inputMatrix(Matrix m, int inputTimes) {
    int inputValue;
    for (int i = 0; i < inputTimes; i++)
    {
        scanf("%d", &inputValue);
        m->values[i] = inputValue;
    }
}

int main()
{
    int times, size;
    scanf("%d", &times);
    for (int t = 0; t < times; t++)
    {
        scanf("%d", &size);
        Matrix m = createMatrix(size, size);
        inputMatrix(m, size*size);
        if (isUpperTriangleMatrix(m)) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
}
