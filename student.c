#include "manager.h"
#include "student.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 학생용 기능 여기서 만들기 + 서브매인도.
// 헤더는 (void student_main())는 무조건 헤더파일에 선언해주어야 합니다.
// * students[] 변수와, count 변수는 헤더에 글로벌변수로 선언 되어 있기에 그냥 변수 쓰시면 오류 안나고 사용 가능.
// 또한, 전역 변수여서  함구 만들때 파라매터로 주지 한고 그냥 사용 가능
// * students[] 변수는 malloc을 이용해서 메모리 할당 해줘야 합니다.
// count 변수는 main.c 에서 0으로 초기화 했으니 사용 하시면 됩니다!

void student_main(){
    printf("학생용 서브메인 입니다\n");

    //test
    //공간 만들고 정보입력 테스트.(지워도 됨)
    students[count] = (student*)malloc(sizeof(student));
    strcat(students[count] ->name, "이수민");
    strcat(students[count] ->s_ID, "22200533");
    strcat(students[count] ->f_m, "여");
    strcat(students[count] ->Dormitory_name, "은혜관");
    students[count] ->room_num = 0;
    students[count] ->total_num_room = 2;
    students[count] ->demerit = 0;
    students[count] ->Y_N = 'N';
    printf("%s(%s)님 방배정 신청이 완료되었습니다!\n", students[count] ->name, students[count] ->s_ID);
    count ++;
    //
    

    //여기에 기능 메뉴 만들어서 기능 사용.
    //여기서 retun 하면 메인으로 돌아가짐.
    return;
}

//여기 밑에 각 기능을 위한 함수 구현. 헤더파일에 헤더부분 꼭 선언 해야 오류 안남.