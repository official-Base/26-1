# 배열 과제

```
요구사항 :
상수 사용 : 사물함 칸 수를 상수로 선언

무한 루프와 선택문 사용

함수활용 :
showLockers() : 현재 사물함의 상태 출력
assignLocker() : 사용자에게 번호를 입력받아 사물함 배정
findLongestEmpty(): 현재 가장 길게 연속으로 비어있는 사물함의 개수를 찾아 출력
```

#### 뼈대 코드
```c
#include <stdio.h>

#define MAX_LOCKER 10 // 사물함 최대 개수 상수

// 함수 원형 선언
void showLockers(int arr[], int size);
void assignLocker(int arr[], int size);
void findLongestEmpty(int arr[], int size);

int main() {
    int lockers[MAX_LOCKER] = {0}; // 0으로 모두 초기화
    int choice;

    while (1) {
        printf("\n 사물함 관리 시스템 \n");
        printf("1. 사물함 상태 보기\n");
        printf("2. 사물함 배정하기\n");
        printf("3. 최대 연속 빈 공간 찾기\n");
        printf("0. 프로그램 종료\n");
        printf("메뉴 선택: ");
        scanf("%d", &choice);

        if (choice == 0) {
            printf("프로그램을 종료합니다.\n");
            break;
        }

        switch (choice) {
            case 1:
                // TODO: showLockers 함수 호출하기
                break;
            case 2:
                // TODO: assignLocker 함수 호출하기
                break;
            case 3:
                // TODO: findLongestEmpty 함수 호출하기
                break;
            default:
                printf("잘못된 입력입니다. 다시 선택해주세요.\n");
        }
    }

    return 0;
}

// 1. 사물함 상태 출력 함수
void showLockers(int arr[], int size) {
    // TODO: for문을 사용하여 배열의 모든 요소를 출력하세요.
}

// 2. 사물함 배정 함수
void assignLocker(int arr[], int size) {
    int num;
    printf("배정할 사물함 번호를 입력하세요 (1~%d): ", size);
    scanf("%d", &num);
    
    // TODO: 입력받은 번호가 범위를 벗어났는지 검사하세요. (힌트: 1~10 사이인가?)
    // TODO: 사용자가 입력한 번호(num)를 배열의 인덱스로 변환하여 상태를 확인하세요.
    // 비어있다면 1로 바꾸고 성공 메시지 출력, 이미 1이라면 경고 메시지 출력
}

// 3. [심화] 최대 연속 빈 공간 찾기 함수
void findLongestEmpty(int arr[], int size) {
    int maxEmpty = 0;     // 가장 긴 연속 빈 공간의 수
    int currentEmpty = 0; // 현재 세고 있는 연속 빈 공간의 수

    // TODO: 배열을 처음부터 끝까지 탐색하면서, 
    // 0을 만나면 currentEmpty를 1 증가시키고,
    // 1을 만나면 currentEmpty를 다시 0으로 초기화하세요.
    // 매번 maxEmpty와 currentEmpty를 비교하여 가장 큰 값을 찾으세요.

    printf("[분석] 현재 가장 길게 연속으로 비어있는 공간은 %d칸입니다.\n", maxEmpty);
}
```
