#include <stdio.h>
#include <string.h>

typedef struct {
    int roll;
    char name[50];
    char dept[5];
    int series;
    int semester;
}studentinfo;

int main()
{
    FILE *fp;
    studentinfo student[500];
    char *filename = "StudentsInfo.txt";
    int i, length, number;
    char line[50];
    fp = fopen(filename, "r");

    i = 0;
    printf("Roll\t\tDepartment\tSeries\t\tSemester\tName\n");
    while (i < 58) {
        fgets(line, 50, fp);
        length = strlen(line);
        line[length-1] = '\0';
        strcpy(student[i].name, line); //Coping the line as an ith number of student's name
        fgets(line, 50, fp);
        sscanf(line, "%d %s %d %d", &student[i].roll, student[i].dept, &student[i].series, &student[i].semester);
        printf("%d\t\t%s\t\t%d\t\t%d\t\t%s\n", student[i].roll, student[i].dept, student[i].series, student[i].semester, student[i].name);
        i++;
    }
    printf("\n\n");

    int num, status;
    mainmenu:
    printf("Enter 1 to search info by roll number. Enter 2 to update info.\n");
    scanf("%d", &num);

    switch(num) {
        case 1: //Searching info by entering roll number
            readroll:
            printf("Enter Roll Number:\n");
            scanf("%d", &num);
            status = 0;
            for (i = 0; i < 58; i++) {
                if (num == student[i].roll) {
                status = 1;
                break;
                }
            }
            if (status == 1) {
               printf("Student's Information\n");
               printf("Full Name:\t\t%s\n", student[i].name);
               printf("Roll Number:\t\t%d\n", student[i].roll);
               printf("Department Name:\t%s\n", student[i].dept);
               printf("Series:\t\t\t%d\n", student[i].series);
               printf("Semester No:\t\t%d\n", student[i].semester);
            }
            else {
               printf("Invalid Roll Number\n");
            }
            printf("What do you want to do now?\n");
            printf("1.Continue searching\t2.Go Back to Main Menu\t3.End\n");
            scanf("%d", &number);
            if (number == 1) {
                goto readroll;
            }
            else if(number == 2) {
                goto mainmenu;
            }
            else {
                return 0;
            }
            break;
        case 2: //Updating info by entering roll number
            update:
            printf("Enter Roll Number you want to update info:\n");
            scanf("%d", &num);
            status = 0;
            for (i = 0; i < 58; i++) {
                if (num == student[i].roll) {
                    status = 1;
                    break;
                }
            }
            if (status == 0) {
                printf("Invalid Roll Number.\n");
            }
            else {
                printf("Enter the current semester: ");
                scanf("%d", &student[i].semester); //Updating the current semester no.
                fclose(fp);
                printf("\n");
                fp = fopen(filename, "w");
                printf("Roll\t\tDepartment\tSeries\tSemester\tName\n");
                    for (i = 0; i < 58; i++) {
                        fprintf(fp, "%s\n%d %s %d %d\n", student[i].name, student[i].roll, student[i].dept, student[i].series, student[i].semester);
                        printf("%d\t\t%s\t\t%d\t\t%d\t\t%s\n", student[i].roll, student[i].dept, student[i].series, student[i].semester, student[i].name);
                    }
            }
            printf("What do you want to do now?\n");
            printf("1.Continue Updating\t2.Go Back to Main Menu\t3.End\n");
            scanf("%d", &number);
            if (number == 1) {
                goto update;
            }
            else if (number == 2) {
                goto mainmenu;
            }
            else {
                return 0;
            }
            break;
        default:
            printf("Invalid Number\n");
            printf("What do you want to do now?\n");
            printf("1.Go Back to Main Menu\t2.End\n");
            scanf("%d", &number);
            if (number == 1) {
                goto mainmenu;
            }
            else {
                return 0;
            }
            break;
    }

    fclose(fp);

    return 0;
}
