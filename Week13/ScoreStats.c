/**
 *  @author 李浩 201911039093
 *  @date 2020.5.19
 **/

#include <stdio.h>
#include <stdlib.h>

typedef int MathScore;
typedef int EnglishScore;
typedef int ChineseScore;
typedef int SportScore;
typedef int ProgramScore;
typedef int StudentID;

struct StudentInfo
{
    StudentID id;
    MathScore math;
    EnglishScore english;
    ChineseScore chinese;
    SportScore sport;
    ProgramScore program;
};

// 节点指针
typedef struct StudentNode *Student;

// 链表节点
struct StudentNode
{
    struct StudentInfo *info;
    Student next;
    Student previous;
};

// 头节点指针
typedef Student StudentList;

int getStudentQuantity();

Student createStudent();

void inputStudentInfo(Student student);

void insertStudent(Student student, StudentList list);

void insertNode(Student node, Student insertPos);

void removeStudent(Student student);

StudentList createStudentList();

void removeStudentList(StudentList list);

Student findStudent(StudentID id, StudentList list);

void printMaxScore(Student stu);

void searchStudentAndOutput(StudentList);

int main()
{
    int number = getStudentQuantity();
    StudentList list = createStudentList();
    Student stu;
    for (int i = 0; i < number; i++)
    {
        stu = createStudent();
        inputStudentInfo(stu);
        insertStudent(stu, list);
    }
    puts("Input End. Now you can enter the student id to query the student.");
    searchStudentAndOutput(list);
    removeStudentList(list);
}

/**
 * 键盘输入学生数量
 * @return 学生数量
 */
int getStudentQuantity()
{
    int number;
    scanf("%d", &number);
    return number;
}

/**
 * 键盘输入学生信息<br>
 * 顺序如下
 * <ol>
 * <li>学号</li>
 * <li>数学</li>
 * <li>英语</li>
 * <li>语文</li>
 * <li>体育</li>
 * <li>程序设计</li>
 * </ol>
 * @param student 学生节点指针
 */
void inputStudentInfo(Student student)
{
    puts("Enter the student number and grades, separated by spaces:");
    scanf("%d %d %d %d %d %d",
          &student->info->id,
          &student->info->math,
          &student->info->english,
          &student->info->chinese,
          &student->info->sport,
          &student->info->program);
}

/**
 * 创建单个节点
 * @return: 学生节点指针
 */
Student createStudent()
{
    Student student = malloc(sizeof(struct StudentNode));
    student->info = malloc(sizeof(struct StudentInfo));
    student->next = NULL;
    student->previous = NULL;
    return student;
}

/**
 * 释放节点内存
 * @param student 节点指针
 */
void removeStudent(Student student)
{
    free(student->info);
    free(student);
}

/**
 * 创建带有头节点的空链表
 * @return 链表头节点指针
 */
StudentList createStudentList()
{
    StudentList list = malloc(sizeof(struct StudentNode));
    list->next = NULL;
    list->previous = NULL;
    return list;
}

/**
 * 删除链表
 * @param list 链表头节点指针
 */
void removeStudentList(StudentList list)
{
    Student stu = list->next;
    free(list);
    while (stu->next)
    {
        stu = stu->next;
        removeStudent(stu->previous);
    }
    free(stu);
}

/**
 * 将student插入list，若原链表从小到大，则保证插入后仍保持
 * @param student 学生节点指针
 * @param list    链表头节点指针
 */
void insertStudent(Student student, StudentList list)
{
    if (list->next == NULL)
    {
        insertNode(student, list);
        return;
    }
    if (findStudent(student->info->id, list) == NULL)
    {
        // 头节点后插入，最小
        if (list->next->info->id > student->info->id)
        {
            insertNode(student, list);
            return;
        }
        else
        {
            Student pos = list;
            while (pos->next)
            {
                // 大于前一个 小于后一个
                if (pos->next->info->id > student->info->id && pos->info->id <= student->info->id)
                {
                    insertNode(student, pos);
                    return;
                }
                pos = pos->next;
            }
            insertNode(student, pos);
            return;
        }
    }
    else
    {
        printf("Student ID conflict. Ignore Student ID %d\n", student->info->id);
        return;
    }
}

/**
 * 执行具体的插入操作
 * @param student 学生节点
 * @param insertPos   在节点后插入
 */
void insertNode(Student node, Student insertPos)
{
    if (insertPos->next)
    {
        insertPos->next->previous = node;
        node->next = insertPos->next;
        node->previous = insertPos;
        insertPos->next = node;
    }
    else
    {
        insertPos->next = node;
        node->previous = insertPos;
        node->next = NULL;
    }
}

/**
 * 按学号查询
 * @param id 学号
 * @param list 学生列表
 * @return 学生节点指针，找不到则返回NULL
 */
Student findStudent(StudentID id, StudentList list)
{
    Student pos = list;
    while (pos->next)
    {
        pos = pos->next;
        if (pos->info->id == id)
        {
            return pos;
        }
    }
    return NULL;
}

/**
 * 输出
 * @param student 学生节点指针
 */
void printStudentInfo(Student student)
{
    struct StudentInfo *info = student->info;
    int totalScore = info->chinese + info->program + info->sport + info->english + info->math;
    float averScore = (float)totalScore / 5;
    printf("---------Start Student %d ---------\n", student->info->id);
    printf("Total Score:%d\nAverage Score:%.2f\n\n",
           totalScore,
           averScore);
    printMaxScore(student);
}

/**
 * 查找并输出相应信息, main函数调用
 * 输入-1结束程序
 * @param student 学生节点指针
 */
void searchStudentAndOutput(StudentList list)
{
    while (1)
    {
        StudentID id;
        scanf("%d", &id);
        if (id == -1)
        {
            printf("Exit.\n");
            return;
        }
        Student stu = findStudent(id, list);
        if (stu)
        {
            printStudentInfo(stu);
        }
        else
        {
            printf("No match.\n");
        }
    }
}

/**
 * 输出最高分有关信息
 * @param stu 学生节点指针
 */
void printMaxScore(Student stu)
{
    int scores[5] = {stu->info->math, stu->info->english,
                     stu->info->chinese, stu->info->sport, stu->info->program};

    int max = scores[0];
    for (int i = 1; i < 5; i++)
    {
        if (scores[i] > max)
        {
            max = scores[i];
        }
    }

    puts("Highest Score Subjects:");

    for (int i = 0; i < 5; i++)
    {
        if (scores[i] == max)
        {
            switch (i)
            {
            case 0:
                printf("Math: %d\n", max);
                break;
            case 1:
                printf("English: %d\n", max);
                break;
            case 2:
                printf("Chinese: %d\n", max);
                break;
            case 3:
                printf("Sport: %d\n", max);
                break;
            case 4:
                printf("Program: %d\n", max);
                break;
            default:
                break;
            }
        }
    }
    printf("---------End Student %d---------\n\n", stu->info->id);
}
