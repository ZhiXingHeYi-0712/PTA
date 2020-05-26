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

void inputMatrix(Matrix m, int inputTimes)
{
    int inputValue;
    for (int i = 0; i < inputTimes; i++)
    {
        scanf("%d", &inputValue);
        m->values[i] = inputValue;
    }
}

bool canMultiply(Matrix m1, Matrix m2) {
    return m1->column == m2->line;
}

Matrix MultiplyMatrix(Matrix m1, Matrix m2)
{
    Matrix result = createMatrix(m1->line, m2->column);
    int thisLine, thisColumn;
    for (int i = 0; i < result->column * result->line; i++)
    {
        result->values[i] = 0;
        unsigned long long pos = convertIndex2Pos(result, i);
        int thisLine = pos >> 32;
        int thisColumn = (pos << 32) >> 32;

        for (int addTimes = 0; addTimes < m1->column; addTimes++)
        {
            result->values[i] += (getMaxtrixElement(m1, thisLine, addTimes) * getMaxtrixElement(m2, addTimes, thisColumn));
        }
    }
    return result;
}

void outputMatrix(Matrix m)
{
    int outputTimes = 0;
    for (int i = 0; i < m->line * m->column; i++)
    {
        printf("%d", m->values[i]);
        outputTimes++;
        if (outputTimes == m->column) {
            printf("\n");
            outputTimes = 0;
        } else {
            printf(" ");
        }
    }
}

int main()
{
    int times, line, column;
    scanf("%d", &line);
    scanf("%d", &column);
    Matrix m1 = createMatrix(line, column);
    inputMatrix(m1, line * column);

    scanf("%d", &line);
    scanf("%d", &column);
    Matrix m2 = createMatrix(line, column);
    inputMatrix(m2, line * column);

    if (!canMultiply(m1, m2)) {
        printf("Error: %d != %d", m1->column, m2->line);
        return 0;
    }

    Matrix result = MultiplyMatrix(m1, m2);
    printf("%d %d\n", result->line, result->column);
    outputMatrix(result);

    free(m1->values);
    free(m1);
    free(m2->values);
    free(m2);
    free(result->values);
    free(result);
}
