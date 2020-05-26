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

int convertPos2Index(const Matrix M, const int LINE, const int COLUMN);

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

int convertPos2Index(const Matrix M, const int LINE, const int COLUMN)
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

int main()
{
    int line, column;
    scanf("%d %d", &line, &column);
    Matrix m = createMatrix(line, column);
    inputMatrix(m, line * column);
    for (int c = 0; c < column; c++)
    {
        for (int l = 0; l < line; l++)
        {
            printf("%d", getMaxtrixElement(m, l, c));
            if (l != line - 1)
            {
                printf(" ");
            }
            else
            {
                printf("\n");
            }
        }
    }
    return 0;
}