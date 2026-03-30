#include <stdio.h>

#define MAX_LOCKER 10 // 사물함 최대 개수 상수

// 함수 원형 선언
void showLockers(int arr[], int size);
void assignLocker(int arr[], int size);
void findLongestEmpty(int arr[], int size);

int main(void) {
    int lockers[MAX_LOCKER] = {0}; // 모든 사물함을 0(빈 상태)으로 초기화
    int choice;

    while (1) {
        printf("\n=== 사물함 관리 시스템 ===\n");
        printf("1. 사물함 상태 보기\n");
        printf("2. 사물함 배정하기\n");
        printf("3. 최대 연속 빈 공간 찾기\n");
        printf("0. 프로그램 종료\n");
        printf("메뉴 선택: ");
        scanf("%d", &choice);

        if (choice == 0) {
            printf("프로그램을 종료합니다.\n");
            break; // 무한 루프 탈출
        }

        switch (choice) {
            case 1:
                showLockers(lockers, MAX_LOCKER);
                break;
            case 2:
                assignLocker(lockers, MAX_LOCKER);
                break;
            case 3:
                findLongestEmpty(lockers, MAX_LOCKER);
                break;
            default:
                printf("잘못된 입력입니다. 다시 선택해주세요.\n");
        }
    }

    return 0;
}

// 1. 사물함 상태 출력 함수
void showLockers(int arr[], int size) {
    printf("\n[현재 사물함 상태]\n[ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

// 2. 사물함 배정 함수
void assignLocker(int arr[], int size) {
    int num;
    printf("배정할 사물함 번호를 입력하세요 (1~%d): ", size);
    scanf("%d", &num);
    
    // 예외 처리 1: 입력한 번호가 범위를 벗어난 경우 (오버플로우 방지)
    if (num < 1 || num > size) {
        printf("[오류] 1부터 %d 사이의 번호를 입력해야 합니다.\n", size);
        return; // 함수 종료
    }

    // 핵심: 사용자가 입력한 번호(1~10)를 배열 인덱스(0~9)로 변환
    int index = num - 1; 

    // 예외 처리 2: 이미 사용 중인 경우
    if (arr[index] == 1) {
        printf("[경고] 이미 사용 중인 사물함입니다!\n");
    } else {
        // 배정 성공
        arr[index] = 1; 
        printf("[알림] %d번 사물함이 성공적으로 배정되었습니다.\n", num);
    }
}

// 3. [심화] 최대 연속 빈 공간 찾기 함수
void findLongestEmpty(int arr[], int size) {
    int maxEmpty = 0;     // 지금까지 발견한 가장 긴 빈 공간
    int currentEmpty = 0; // 현재 연속해서 세고 있는 빈 공간

    for (int i = 0; i < size; i++) {
        if (arr[i] == 0) {
            // 빈 공간을 발견하면 현재 카운트 증가
            currentEmpty++; 
            
            // 방금 증가시킨 카운트가 기존 최대 기록보다 크면 기록 갱신
            if (currentEmpty > maxEmpty) {
                maxEmpty = currentEmpty;
            }
        } else {
            // 누군가 사용 중(1)이라면 흐름이 끊겼으므로 카운트 초기화
            currentEmpty = 0; 
        }
    }

    printf("\n[분석] 현재 가장 길게 연속으로 비어있는 공간은 %d칸입니다.\n", maxEmpty);
}
