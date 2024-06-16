#include <stdio.h>
#include <string.h>
struct Student {
    char name[100];
    int rollNumber;
    int marks[3];
    int totalMarks;
    float averageMarks;
};

// Function prototypes
void readStudentDetails(struct Student* student);
void calculateTotalAndAverageMarks(struct Student* student);
void displayStudentDetails(const struct Student* student);
struct Student findStudentWithHighestMarks(struct Student students[], int n);

int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    struct Student students[n];
    for (int i = 0; i < n; ++i) {
        printf("Enter details for student %d:\n", i + 1);
        readStudentDetails(&students[i]);
        calculateTotalAndAverageMarks(&students[i]);
    }

    printf("\nStudent Details:\n");
    for (int i = 0; i < n; ++i) {
        printf("Student %d:\n", i + 1);
        displayStudentDetails(&students[i]);
        printf("\n");
}
    struct Student topStudent = findStudentWithHighestMarks(students, n);
    printf("Student with highest total marks:\n");
    displayStudentDetails(&topStudent);

    return 0;
}
void readStudentDetails(struct Student* student) {
    printf("Name: ");
    scanf("%s", student->name);
    printf("Roll Number: ");
    scanf("%d", &student->rollNumber);
    printf("Marks in three subjects: ");
    for (int i = 0; i < 3; ++i) {
        scanf("%d", &student->marks[i]);
    }
}
void calculateTotalAndAverageMarks(struct Student* student) {
    student->totalMarks = 0;
    for (int i = 0; i < 3; ++i) {
        student->totalMarks += student->marks[i];
    }
    student->averageMarks = student->totalMarks / 3.0;
}
void displayStudentDetails(const struct Student* student) {
    printf("Name: %s\n", student->name);
    printf("Roll Number: %d\n", student->rollNumber);
    printf("Total Marks: %d\n", student->totalMarks);
    printf("Average Marks: %.2f\n", student->averageMarks);
}
struct Student findStudentWithHighestMarks(struct Student students[], int n) {
    struct Student topStudent = students[0];
for (int i = 1; i < n; ++i) {
        if (students[i].totalMarks > topStudent.totalMarks) {
            topStudent = students[i];
        }
    }
    return topStudent;
}
