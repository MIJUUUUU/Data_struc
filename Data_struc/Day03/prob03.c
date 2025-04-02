#include <stdio.h> 
#include <string.h>

#define MAX_STUDENTS 5

// 학생 구조체 선언
struct Student {
    int id;         // 학번
    char name[50];  // 이름
    float score;      // 점수
};

// 학생 정보 입력 함수
void inputStudentData(struct Student *s) {
    scanf("%d", &s->id);
    scanf("%s", s->name);
    scanf("%f", &s->score);
}

// 학생 상세 정보 출력 함수
void displayStudentData(const struct Student *s) {
    printf("Student_Number: %d\n", s->id);
    printf("Name: %s\n", s->name);
    printf("Marks: %.2f\n", s->score);
}

// 학생 점수 평균 계산 함수
float calculateAverageMarks(const struct Student students[], int num) {
    float sum = 0;
    for (int i = 0; i < num; i++) {
        sum += students[i].score; // 총합 계산
    }
    return sum / num; // 평균 반환
}

int main() {
    struct Student students[MAX_STUDENTS]; // 학생 배열 선언
    int num; // 입력받을 학생 수

    // 학생 수 입력
    scanf("%d", &num);

    // 학생 정보 입력
    for (int i = 0; i < num; i++) {
        inputStudentData(&students[i]);
    }

    // 학생 상세 정보 출력
    for (int i = 0; i < num; i++) {
        printf("Details for Student %d:\n", i + 1);
        displayStudentData(&students[i]);
        printf("\n");
    }

    // 학생들의 점수 평균 계산
    float avg = calculateAverageMarks(students, num);
    printf("Average Marks of students: %.2f\n", avg);

    return 0;
}