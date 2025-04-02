#include <stdio.h>

#define SIZE 5
int iarray[SIZE];

// 배열에 값 저장 함수
void store(int i, int item) {
    iarray[i] = item;
}

// 배열에서 값 추출 함수
int retrieve(int i) {
    return iarray[i];
}

int main() {
    int i, n, item, sum=0;
    scanf("%d",&n);

    for (i=0; i<n; i++){
        scanf("%d", &item);
        store(i, item);
    }

    for (i=0; i<n; i++) {
        sum = sum + retrieve(i);
    }
    printf("%d", sum);

   return 0;
}