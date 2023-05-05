#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "manager.h"
#include "student.h"

//메인은 완성 끝. 더이상 건들 필료 없음.
int main(void){
    count = 0;

    while(1){
        int menu;

        printf("\n---생활관 관리 시스템---\n");
        printf("1. 학생\n");
        printf("2. 관리자\n");
        printf("0. 종료\n");
        printf("----------------------\n");

        printf("원하는 메뉴를 입력하세요 > ");
        scanf("%d", &menu);

        if (menu == 0) break;
        if (menu == 1){
            student_main();
        }
        else if (menu == 2){
            manager_main();
        }
        else{
            printf("\n!!입력오류!!\n");
            printf("!!다시 입력해주세요!!\n");
        }


    }

    printf("\n서비스를 이용해 주셔서 감사합니다!!\n");
}