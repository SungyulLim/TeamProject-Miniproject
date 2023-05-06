#include "manager.h"
#include "student.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//관리자용 기능 여기서 만들기 + 서브매인도.
// 헤더는 (void student_main())는 무조건 헤더파일에 선언해주어야 합니다.

void manager_main(){
    printf("관리자용 서브메인 입니다\n");

    //test
    printf("-----------------------LIST-------------------\n");
    for(int i=0; i<count; i++){
        
        printf("%s %s %s %s %d호 %d인실 %d점 %c\n", students[i]->name, students[i]->s_ID, students[i]->f_m, students[i]->Dormitory_name, students[i]->room_num, students[i]->total_num_room, students[i]->demerit, students[i]->Y_N); 
        
    }
    printf("------------------------------------------------\n\n");

    for(int i=0; i<count; i++){
        if(students[i] ->Y_N == 'N'){
            students[i] ->room_num = 101+i;
            students[i] ->Y_N = 'Y';
            printf("%s(%s)님을 %d호에 방배정 했습니다.\n", students[i] ->name, students[i] ->s_ID, students[i] ->room_num);
        }
    }

    while(1){
        int menu;

        printf("\n-------관리자용-------\n");
        printf("1. 기숙사 신청자 방 배치\n");
        printf("2. 기숙사 리스트 보기\n");
        printf("3. 벌점 부과하기\n");
        printf("5. 리스트 저장\n");
        printf("6. 메인 화면으로\n");
        printf("----------------------\n");

        printf("원하는 메뉴를 입력하세요 > ");
        scanf("%d", &menu);

        if (menu == 6) break;
        if (menu == 1){
            
        }
        else if (menu == 2){
            
        }
        else if (menu == 3){
            
        }
        else if (menu == 4){
            
        }
        else if (menu ==5){
            
        }
        else{
            printf("\n!!입력오류!!\n");
            printf("!!다시 입력해주세요!!\n");
        }


    }


    //

    //여기에 기능 메뉴 만들어서 기능 사용.
    //여기서 retun 하면 메인으로 돌아가짐.
    return;
}

//여기 밑에 각 기능을 위한 함수 구현. 헤더파일에 헤더부분 꼭 선언 해야 오류 안남.