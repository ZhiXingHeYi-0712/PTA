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
        return;
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

void inputMatrix(Matrix m, int inputTimes)
{
    int inputValue;
    for (int i = 0; i < inputTimes; i++)
    {
        scanf("%d", &inputValue);
        m->values[i] = inputValue;
    }
}


bool isMaxInLine(const Matrix M, const int LINE, const MatrixElement testElement)
{
    for (int c = 0; c < M->column; c++)
    {
        if (testElement < getMaxtrixElement(M, LINE, c))
            return false;
    }
    return true;
}

bool isMininColumn(const Matrix M, const int COLUMN, const MatrixElement testElement)
{
    for (int l = 0; l < M->line; l++)
    {
        if (testElement > getMaxtrixElement(M, l, COLUMN))
            return false;
    }
    return true;
}

bool isSaddlePoint(const Matrix M, const int LINE, const int COLUMN)
{
    MatrixElement testElement = getMaxtrixElement(M, LINE, COLUMN);
    return (isMaxInLine(M, LINE, testElement) && isMininColumn(M, COLUMN, testElement));
}
int main()
{
    int size;
    bool hasLocalMax = false;
    scanf("%d", &size);
    Matrix m = createMatrix(size, size);
    int line = size;
    int column = size;
    inputMatrix(m, line * column);

    for (int l = 0; l < line; l++)
    {
        for (int c = 0; c < column; c++)
        {
            if (isSaddlePoint(m, l, c))
            {
                printf("%d %d\n", l, c);
                hasLocalMax = true;
            }
        }
    }

    if (!hasLocalMax)
    {
        printf("NONE");
    }
    return 0;
}
