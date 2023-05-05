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
    for(int i=0; i<count; i++){
       printf("%s %s %s %s %d호 %d인실 %d점 %c\n", students[i]->name, students[i]->s_ID, students[i]->f_m, students[i]->Dormitory_name, students[i]->room_num, students[i]->total_num_room, students[i]->demerit, students[i]->Y_N); 
    }

    for(int i=0; i<count; i++){
        if(students[i] ->Y_N == 'N'){
            students[i] ->room_num = 101+i;
            students[i] ->total_num_room = 2;
            students[i] ->demerit = 0;
            students[i] ->Y_N = 'Y';
        }
    }


    //

    //여기에 기능 메뉴 만들어서 기능 사용.
    //여기서 retun 하면 메인으로 돌아가짐.
    return;
}

//여기 밑에 각 기능을 위한 함수 구현. 헤더파일에 헤더부분 꼭 선언 해야 오류 안남.