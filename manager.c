#include "manager.h"
#include "student.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//관리자용 기능 여기서 만들기 + 서브매인도.
// 헤더는 (void student_main())는 무조건 헤더파일에 선언해주어야 합니다.

void manager_main(){
    printf("관리자용 서브메인 입니다\n");


    while(1){
        int menu;

        printf("\n-------관리자용-------\n");
        printf("1. 기숙사 신청자 방 배치\n");
        printf("2. 기숙사 리스트 보기\n");
        printf("3. 벌점 부과하기\n");
        printf("4. 리스트 저장\n");
        printf("5. 리스트 불러오기\n");
        printf("6. 메인 화면으로\n");
        printf("----------------------\n");

        printf("원하는 메뉴를 입력하세요 > ");
        scanf("%d", &menu);

        if (menu == 6) break;
        if (menu == 1){
            room_numbering();
        }
        else if (menu == 2){
            dormitory_list();
        }
        else if (menu == 3){
            penalty_points();
        }
        else if (menu == 4){
            save_list();
        }
        else if (menu ==5){
            recall_list();
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

//1. 기숙사 신청자 방 배치
void room_numbering(){
    int num;
    printf("\n----------------------기숙사 신청자 리스트------------------\n");
    printf("번호 이름    학번   성별 생활관  호실 인실  벌점 방배정여부\n");
    for(int i=0; i<count; i++){
        if(students[i] ->Y_N == 'N'){
            printf("%2d. %-4s %s  %s  %-4s %3d호 %d인실 %2d점  %3c\n",i+1 , students[i]->name, students[i]->s_ID, students[i]->f_m, students[i]->Dormitory_name, students[i]->room_num, students[i]->total_num_room, students[i]->demerit, students[i]->Y_N); 
        }
    }
    printf("-----------------------------------------------------------\n\n");
    printf("방 배정 할 학생의 번호를 입력하세요 > ");
    scanf("%d", &num);
    num--; //배열이라 -1 해줘여함.

    printf("%s(%s)학우님을 배정학 방 호수를 입력하세요 > ", students[num]->name, students[num]->s_ID);
    scanf("%d", &students[num] ->room_num);
    students[num] ->Y_N = 'Y';

    printf("%s(%s)학우님을 %d호에 방배정 했습니다.\n", students[num] ->name, students[num] ->s_ID, students[num] ->room_num);
}

//2. 기숙사 리스트 보기
void dormitory_list(){
    printf("\n-----------------전체 리스트(사용자, 신청자)-----------------\n");
    printf("번호 이름    학번   성별 생활관  호실 인실  벌점 방배정여부\n");
    for(int i=0; i<count; i++){
        
        printf("%2d. %-4s %s  %s  %-4s %3d호 %d인실 %2d점  %3c\n",i+1 , students[i]->name, students[i]->s_ID, students[i]->f_m, students[i]->Dormitory_name, students[i]->room_num, students[i]->total_num_room, students[i]->demerit, students[i]->Y_N); 
        
    }
    printf("-------------------------------------------------------------\n\n");
}


//3. 벌점 부과하기
void penalty_points(){
    int points[4] = {2, 1, 1, 5};
    int choose_points;
    int num;
    printf("\n---------------------기숙사 사용자 리스트------------------\n");
    printf("번호 이름    학번   성별 생활관  호실 인실  벌점 방배정여부\n");
    for(int i=0; i<count; i++){
        if(students[i] ->Y_N == 'Y'){
            printf("%2d. %-4s %s  %s  %-4s %3d호 %d인실 %2d점  %3c\n",i+1 , students[i]->name, students[i]->s_ID, students[i]->f_m, students[i]->Dormitory_name, students[i]->room_num, students[i]->total_num_room, students[i]->demerit, students[i]->Y_N); 
        }
    }
    printf("-----------------------------------------------------------\n\n");
    printf("벌점을 부여 할 학생의 번호를 입력하세요 > ");
    scanf("%d", &num);
    num--; //배열이라 -1 해줘여함.

    printf("* 벌점 리스트 *\n");
    printf("1. 무단외박 (2점)\n");
    printf("2. 미소등(1점)\n");
    printf("3. 침묵시간 안 지킴 (1점)\n");
    printf("4. 외부인 들임 (5점)\n");
    printf("\n벌점 사유를 선택하세요(1~4)> ");
    scanf("%d", &choose_points);
    choose_points--;

    students[num]->demerit = points[choose_points];
    printf("%s(%s)학우님 에게 벌점%d점을 부여했습니다.\n", students[num] ->name, students[num] ->s_ID, points[choose_points]);

}

//4. 리스트 저장
void save_list(){
    FILE *fp;
    fp = fopen("dormitory_List.txt", "w");
        

    for(int i=0; i<count; i++){
        if(students[i]->room_num == -1) continue;
        else{
            fprintf(fp, "%s %s %s %s %d %d %d %c\n",students[i]->name, students[i]->s_ID, students[i]->f_m, students[i]->Dormitory_name, students[i]->room_num, students[i]->total_num_room, students[i]->demerit, students[i]->Y_N); 
        }
    }
   
    fclose(fp);
    printf("\n==> 저장이 완료 되었습니다.\n");
}

//"5. 리스트 불러오기
void recall_list(){

}