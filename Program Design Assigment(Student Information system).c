#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int id;
    char *name;
    int age;
};

struct Student students[100];
int studentCount = 0;

void guideline();
void addStudent();
void searchStudent();
void showallStudent();
void editStudent();
void deleteStudent();
void deleteallStudent();
void askgoback();
void saveToFile();
void loadFromFile();

int main() {
    int mm_choice;

    loadFromFile(); // 从文件加载学生信息

    do {
        printf(" ---------Student Information System---------\n\n\n");
        printf("               _____________                 \n");
        printf(" --------------| Main Menu |---------------\n");
        printf(" |             -------------              |\n");
        printf(" |                                        |\n");
        printf(" |         1. User Guideline              |\n");
        printf(" |         2. Add A New Student           |\n");
        printf(" |         3. Search Student              |\n");
        printf(" |         4. Show All Students           |\n");
        printf(" |         5. Edit Student                |\n");
        printf(" |         6. Delete Student              |\n");
        printf(" |         7. Delete All Students         |\n");
        printf(" |         8. Save to File                |\n");
        printf(" |         9. Load from File              |\n");
        printf(" |        10. Exit the System             |\n");
        printf(" |                                        |\n");
        printf(" ------------------------------------------\n");

        printf("\n Enter Your Choice :");
        scanf("%d", &mm_choice);

        system("cls");

        switch (mm_choice) {
            case 1:
                guideline();
                askgoback();
                break;
            case 2:
                addStudent();
                askgoback();
                break;
            case 3:
                searchStudent();
                askgoback();
                break;
            case 4:
                showallStudent();
                askgoback();
                break;
            case 5:
                editStudent();
                askgoback();
                break;
            case 6:
                deleteStudent();
                askgoback();
                break;
            case 7:
                deleteallStudent();
                askgoback();
                break;
            case 8:
                saveToFile();
                askgoback();
                break;
            case 9:
                loadFromFile();
                askgoback();
                break;
            case 10:
                printf("\nExiting the system...\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (mm_choice != 10);

    return 0;
}

void guideline() {
    printf(" ---------Student Information System---------\n\n\n");
    printf("               ___________                 \n");
    printf(" --------------|guideline|---------------\n");
    printf("               -----------              \n");

    printf("   Welcome to the Student Information System.\n");
    printf("   Here, you can manage student information.\n");
    printf("\n------------------------------------------\n");
}

void addStudent() {
    struct Student newStudent;

    printf(" ---------Student Information System---------\n\n\n");
    printf("               _____________                 \n");
    printf(" --------------|Add Student|---------------\n");
    printf("               -------------               \n");

    printf("   Enter student ID: ");
    scanf("%d", &newStudent.id);

    newStudent.name = (char *)malloc(50 * sizeof(char));

    printf("\n   Enter student name: ");
    scanf(" %49[^\n]", newStudent.name);

    printf("\n   Enter student age: ");
    scanf("%d", &newStudent.age);

    printf(" \n------------------------------------------\n");

    students[studentCount++] = newStudent;

    printf("Student added successfully.\n");
}

void searchStudent() {
    int searchId;
    printf(" ---------Student Information System---------\n\n\n");
    printf("             ________________                 \n");
    printf("-------------|Search Student|---------------\n");
    printf("             ----------------               \n");

    printf("Enter student ID to search: ");
    scanf("%d", &searchId);

    int i;
    for (i = 0; i < studentCount; ++i) {
        if (students[i].id == searchId) {
            printf("Student found:\n");
            printf("ID: %d\n", students[i].id);
            printf("Name: %s\n", students[i].name);
            printf("Age: %d\n", students[i].age);
            return;
        }
        printf(" \n------------------------------------------\n");
    }

    printf("\nStudent with ID %d not found.\n", searchId);
    printf("\n------------------------------------------\n");
}

void showallStudent() {
    if (studentCount == 0) {
        printf(" ---------Student Information System---------\n\n\n");
        printf("               _____________                 \n");
        printf(" --------------|All Student|---------------\n");
        printf("               -------------               \n");
        printf("   No students in the system.\n");
        printf("\n------------------------------------------\n");
        return;
    }

    printf("All Students:\n");
    int i;

    printf(" ---------Student Information System---------\n\n\n");
    printf("               _____________                 \n");
    printf("--------------|All Student|---------------\n");
    printf("               -------------               \n");
    for (i = 0; i < studentCount; ++i) {
        printf("   ID: %d, Name: %s, Age: %d\n", students[i].id, students[i].name, students[i].age);
    }
    printf("\n------------------------------------------\n");
}

void editStudent() {
    int editId;

    printf(" ---------Student Information System---------\n\n\n");
    printf("               ______________                 \n");
    printf(" --------------|Edit Student|---------------\n");
    printf("               --------------              \n");

    printf("Enter student ID to edit: ");
    scanf("%d", &editId);

    int i;
    for (i = 0; i < studentCount; ++i) {
        if (students[i].id == editId) {

            free(students[i].name);

            students[i].name = (char *)malloc(50 * sizeof(char));

            printf("Enter new name for student: ");
            scanf("%s", students[i].name);

            printf("Enter new age for student: ");
            scanf("%d", &students[i].age);

            printf("Student information updated successfully.\n");
            printf("\n------------------------------------------\n");
            return;
        }
    }

    printf("Student with ID %d not found.\n", editId);
    printf("\n------------------------------------------\n"); 
}

void deleteStudent() {
    int deleteId;

    printf(" ---------Student Information System---------\n\n\n");
    printf("               ______________                 \n");
    printf(" --------------|Delete Student|---------------\n");
    printf("               --------------              \n");

    printf("Enter student ID to delete: ");
    scanf("%d", &deleteId);

    int i;
    for (i = 0; i < studentCount; ++i) {
        if (students[i].id == deleteId) {

            int j;
            for (j = i; j < studentCount - 1; ++j) {
                students[j] = students[j + 1];
            }
            studentCount--;

            printf("\nStudent deleted successfully.\n");

            printf("\n------------------------------------------\n");
            return;
        }
    }

    printf("\nStudent with ID %d not found.\n", deleteId);
    printf("\n------------------------------------------\n");
}

void deleteallStudent() {
    printf(" ---------Student Information System---------\n\n\n");
    printf("              ___________________               \n");
    printf(" ------------|Delete all students|--------------\n");
    printf("             --------------------             \n");

    int i;
    for (i = 0; i < studentCount; ++i) {
        free(students[i].name);
    }

    studentCount = 0;
    printf("All students deleted successfully.\n");
    printf("\n------------------------------------------\n");
}

void askgoback() {
    int goback;

    printf("\n\n\n\nGo Back To Main Menu (press 0):");
    scanf("%d", &goback);
    system("cls");
    if (goback == 0) {
        return;
    }
}

void saveToFile() {
    FILE *file = fopen("students.txt", "w");
    if (file == NULL) {
        printf("Unable to open the file.\n");
        return;
    }

	int i;
	for (i = 0; i < studentCount; ++i) {
        fprintf(file, "%d %s %d\n", students[i].id, students[i].name, students[i].age);
    }

    fclose(file);
    printf("Student information saved to file.\n");
}

void loadFromFile() {
    FILE *file = fopen("students.txt", "r");
    if (file == NULL) {
        printf("Unable to open the file.\n");
        return;
    }

    while (fscanf(file, "%d %s %d", &students[studentCount].id, students[studentCount].name, &students[studentCount].age) != EOF) {
        students[studentCount].name = strdup(students[studentCount].name);
        studentCount++;
    }

    fclose(file);
    printf("Student information loaded from file.\n");
}


