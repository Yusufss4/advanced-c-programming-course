#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <math.h>

union grade
{
    char letterGrade;
    int roundedGrade;
    float exactGrade;
};

enum gradeV2Type
{
    letterGrade,
    roundedGrade,
    exactGrade
};

//this will not work because letterGrade replaces it.
union gradeV2
{
    enum gradeV2Type gradeType; //add enum.
    char letterGrade;
    int roundedGrade;
    float exactGrade;
};

struct gradeV3{
	enum gradeV2Type type;
	union {
    char letterGrade;
    int roundedGrade;
    float exactGrade;
	} gradeData;
};




void printGradeV2Union(union gradeV2 *gradeUnion);
void printGradeUnion(union grade *gradeUnion);
void printGradeV3Union(struct gradeV3 *gradeV3);

int main(void)
{
    union grade record1;
    float variable1 = 10.5;
    record1.letterGrade = variable1;
    record1.roundedGrade = variable1;
    record1.exactGrade = variable1;
    printf("\nRecord One\n");
    printGradeUnion(&record1);

    printf("\nRecord Two\n");
    union grade record2;
    record2.letterGrade = 'A';
    printGradeUnion(&record2);

    printf("\nRecord Three\n");
    union gradeV2 record3;
    record3.gradeType = letterGrade; //this will not work because letterGrade replaces it.
    record3.letterGrade = 'B';
    printGradeV2Union(&record3);

    printf("\nRecord Three\n");
    struct gradeV3 record4;
    record4.type = letterGrade;
    record4.gradeData.letterGrade = 'B';
    printGradeV3Union(&record4);

    return 0;
}

void printGradeUnion(union grade *gradeUnion)
{
    printf("\nLetter grade in (integer): %d", gradeUnion->letterGrade);
    printf("\nLetter grade in (char): %d", gradeUnion->letterGrade);
    printf("\nRounded Grade in (int): %d", gradeUnion->roundedGrade);
    printf("\nExact Grade in (float): %.3f\n", gradeUnion->exactGrade);
}

void printGradeV2Union(union gradeV2 *gradeUnion)
{
    printf("\nGrade type is: ");
    switch (gradeUnion->gradeType)
        {
        case letterGrade:
            printf("Letter Grade\n");
            break;

        case roundedGrade:
            printf("Rounded Grade\n");
            // statements
            break;
        case exactGrade:
            printf("Exact Grade\n");
            // statements
            break;
        default:
            // default statements
            printf("Default");
        }
}


void printGradeV3Union(struct gradeV3 *gradeV3)
{
    printf("\nGrade type is: ");
    switch (gradeV3->type)
        {
        case letterGrade:
            printf("Letter Grade\n");
            printf("Letter grade in (char): %c", gradeV3->gradeData.letterGrade);
            break;

        case roundedGrade:
            printf("Rounded Grade\n");
            printf("Rounded Grade in (int): %d", gradeV3->gradeData.roundedGrade);
            // statements
            break;
        case exactGrade:
            printf("Exact Grade\n");
            printf("Exact Grade in (float): %.3f\n", gradeV3->gradeData.exactGrade);
            // statements
            break;
        default:
            // default statements
            printf("Default");
        }
}