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

bool isLocalMax(const Matrix M, const int LINE, const int COLUMN)
{
    if (LINE == 0 || LINE == M->line - 1) return false;
    if (COLUMN == 0 || COLUMN == M->column - 1) return false;
    MatrixElement scanningElement = getMaxtrixElement(M, LINE, COLUMN);
    MatrixElement over = getMaxtrixElement(M, LINE - 1, COLUMN);
    MatrixElement below = getMaxtrixElement(M, LINE + 1, COLUMN);
    MatrixElement left = getMaxtrixElement(M, LINE, COLUMN - 1);
    MatrixElement right = getMaxtrixElement(M, LINE, COLUMN + 1);
    if (scanningElement > over && scanningElement > below 
    && scanningElement > left && scanningElement > right) return true;
    return false;
}

int main()
{
    int line, column;
    bool hasLocalMax = false;
    scanf("%d %d", &line, &column);
    Matrix m = createMatrix(line, column);
    inputMatrix(m, line * column);

    for (int l = 1; l < line - 1; l++)
    {
        for (int c = 1; c < column - 1; c++)
        {
            if (isLocalMax(m, l, c)) {
                printf("%d %d %d\n", getMaxtrixElement(m, l, c), l+1, c+1);
                hasLocalMax = true;
            }
        }
    }

    if (!hasLocalMax) {
        printf("None %d %d", line, column);
    }
    return 0;
}
